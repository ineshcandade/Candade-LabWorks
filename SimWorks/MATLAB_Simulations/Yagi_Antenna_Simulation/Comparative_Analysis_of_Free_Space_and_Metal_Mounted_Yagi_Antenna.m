%% Comparative Analysis of Free-Space and Metal-Mounted Yagi Antenna at 1.9 GHz
% By Inesh Candade, Thejas S and Rakshit M Kalyani
clear; clc; close all;
saveFigures = true;          
saveCSV     = true;           
outPrefix   = 'yagi_antenna';
f0 = 1.9e9;               
c0 = physconst('LightSpeed');
lambda = c0 / f0;
mm = 1e3;
boom_max_mm = 300;            
Z0 = 50;                     
fprintf('Outputs of Yagi Antenna\n');
fprintf('Frequency = %.2f GHz, lambda = %.3f m (%.2f mm)\n', f0/1e9, lambda, lambda*mm);

%% YAGI GEOMETRY
L_driven    = 0.50 * lambda;
L_reflector = 1.03 * L_driven;
L_dirs_base = [0.95, 0.93, 0.92] * L_driven;

S_ref_drv   = 0.15 * lambda;
S_drv_dir1  = 0.12 * lambda;
S_dir1_dir2 = 0.12 * lambda;
S_dir2_dir3 = 0.12 * lambda;

spacings_base = [S_ref_drv, S_drv_dir1, S_dir1_dir2, S_dir2_dir3];
boom_len_mm_base = sum(spacings_base) * mm;
fprintf('Initial boom length: %.1f mm\n', boom_len_mm_base);

%% SWEEP PARAMETERS 
dir_scale_vals   = linspace(0.90, 1.05, 11);
space_scale_vals = linspace(0.85, 1.05, 11);
theta = 0:1:180;   % elevation sweep 

% Metal mounting heights taken into consideration
h_vals = [0.05, 0.10, 0.20, 0.30] * lambda;
min_clearance = 0.01 * lambda;   
thinWidth = 1e-4;

%% FREE-SPACE OPTIMIZATION
fprintf('\nFree-space optimization\n');

bestList = struct([]);
k = 1;
for ds = dir_scale_vals
    for ss = space_scale_vals
        L_dirs = L_dirs_base * ds;
        spacings = spacings_base * ss;
        boom_len_mm = sum(spacings) * mm;
        if boom_len_mm > boom_max_mm
            continue;
        end

        d_exc = dipole('Length', L_driven, 'Width', thinWidth);

        % building yagi antenna
        ant_tmp = yagiUda( ...
            'Exciter',          d_exc, ...
            'NumDirectors',     numel(L_dirs), ...
            'ReflectorLength',  L_reflector, ...
            'DirectorLength',   L_dirs, ...
            'ReflectorSpacing', spacings(1), ...
            'DirectorSpacing',  spacings(2:end));

        % metrics
        M = computeMetrics(ant_tmp, f0, Z0, theta);

        % prioritize gain and F/B, ignore large or invalid VSWR
        if isnan(M.VSWR) || isinf(M.VSWR)
            vswrPenalty = 10;
        else
            vswrPenalty = max(0, M.VSWR - 2);
        end
        score = M.gain_max + 0.5*M.FB - 0.5*vswrPenalty;

        bestList(k).ds = ds;
        bestList(k).ss = ss;
        bestList(k).boom_mm = boom_len_mm;
        bestList(k).M = M;
        bestList(k).L_dirs = L_dirs;
        bestList(k).spacings = spacings;
        bestList(k).score = score;
        k = k + 1;
    end
end

if isempty(bestList)
    error('Free-space search failed.');
end

% choose best free-space candidate
scores = [bestList.score];
[~, ix] = max(scores);
bestFS = bestList(ix);

fprintf('Best free-space: ds=%.3f ss=%.3f boom=%.1f mm gain=%.2f dBi F/B=%.2f VSWR=%s\n', ...
    bestFS.ds, bestFS.ss, bestFS.boom_mm, bestFS.M.gain_max, bestFS.M.FB, ...
    mat2str(bestFS.M.VSWR,4));

% Build final free-space Yagi Antenna
d_exc_FS = dipole('Length', L_driven, 'Width', thinWidth);
ant_free = yagiUda( ...
    'Exciter', d_exc_FS, ...
    'NumDirectors', numel(bestFS.L_dirs), ...
    'ReflectorLength', L_reflector, ...
    'DirectorLength', bestFS.L_dirs, ...
    'ReflectorSpacing', bestFS.spacings(1), ...
    'DirectorSpacing', bestFS.spacings(2:end));

% Show and save geometry
figGeom = figure('Name','Free-space Yagi Geometry');
show(ant_free);
title('Free-space Optimized Yagi');
if saveFigures
    try
        saveas(figGeom, sprintf('%s_free_space_geometry.png', outPrefix));
    catch
        warning('Could not save free-space geometry image.');
    end
end

try
    figFS3D = figure('Name','Free-space 3D pattern');
    pattern(ant_free, f0);
    title('Free-space 3D pattern (baseline)');
catch
    warning('Could not display free-space 3D pattern.');
end

%% FREE-SPACE METRICS
M_fs = computeMetrics(ant_free, f0, Z0, theta);
fprintf('\nFree-space metrics: Gain=%.2f dBi, F/B=%.2f dB, VSWR=%s\n', ...
    M_fs.gain_max, M_fs.FB, mat2str(M_fs.VSWR,4));

%% METAL MOUNTING SWEEP
fprintf('\nMetal mounting sweep for safe heights \n');

% arrays to store per-height results
results_h = table();
results_h.Height_lambda = (h_vals / lambda).';
results_h.Height_m = h_vals.';

gain_metal = nan(size(h_vals));
FB_metal   = nan(size(h_vals));
VSWR_metal = nan(size(h_vals));
Zin_metal  = complex(nan(size(h_vals)));
validFlag  = false(size(h_vals));

for i = 1:numel(h_vals)
    h = h_vals(i);
    if h < min_clearance
        warning('h=%.4g m is below min_clearance (%.4g m) — using min_clearance', ...
            h, min_clearance);
        h = min_clearance;
    end

    try
        ant_metal = reflector( ...
            'Exciter', ant_free, ...
            'GroundPlaneLength', 1.0*lambda, ...
            'GroundPlaneWidth',  1.0*lambda, ...
            'Spacing', h);

        M = computeMetrics(ant_metal, f0, Z0, theta);

        gain_metal(i) = M.gain_max;
        FB_metal(i)   = M.FB;
        VSWR_metal(i) = M.VSWR;
        Zin_metal(i)  = M.Zin;
        validFlag(i)  = true;

        fprintf('h=%.3f λ: gain=%.2f dBi, F/B=%.2f dB, VSWR=%s\n', ...
            h/lambda, M.gain_max, M.FB, mat2str(M.VSWR,4));

    catch ME
        fprintf('Skipped h=%.3f λ due to meshing error: %s\n', h/lambda, ME.message);
        gain_metal(i) = NaN;
        FB_metal(i)   = NaN;
        VSWR_metal(i) = NaN;
        validFlag(i) = false;
    end
end

% store into results table
results_h.Gain_dBi = gain_metal.';
results_h.FB_dB    = FB_metal.';
results_h.VSWR     = VSWR_metal.';
results_h.Zin      = Zin_metal.';

if saveCSV
    writetable(results_h, sprintf('%s_metal_sweep_results.csv', outPrefix));
end

%% SELECT HEIGHT FOR METAL MOUNTING
validVSWR = VSWR_metal;
validVSWR(~validFlag) = NaN;

if all(isnan(validVSWR))
    warning('No valid metal-mounted cases succeeded meshing. Using first available height.');
    idxWorst = 1;   % fall back safely to the first height
else
    [~, idxWorst] = max(validVSWR);
end

h_worst = h_vals(idxWorst);

%% RE-OPTIMIZE FOR METAL
fprintf('\nRe-optimization over metal (target h = %.3f λ)\n', ...
    h_worst/lambda);

bestMetalList = struct([]);
k = 1;
for ds = dir_scale_vals
    for ss = space_scale_vals
        L_dirs = L_dirs_base * ds;
        spacings = spacings_base * ss;
        boom_len_mm = sum(spacings) * mm;
        if boom_len_mm > boom_max_mm
            continue;
        end

        % build Yagi with thin exciter
        d_exc = dipole('Length', L_driven, 'Width', thinWidth);
        ant_tmp = yagiUda( ...
            'Exciter', d_exc, ...
            'NumDirectors', numel(L_dirs), ...
            'ReflectorLength', L_reflector, ...
            'DirectorLength', L_dirs, ...
            'ReflectorSpacing', spacings(1), ...
            'DirectorSpacing', spacings(2:end));

        try
            ant_metal_tmp = reflector( ...
                'Exciter', ant_tmp, ...
                'GroundPlaneLength', 1.0*lambda, ...
                'GroundPlaneWidth',  1.0*lambda, ...
                'Spacing', h_worst);

            M = computeMetrics(ant_metal_tmp, f0, Z0, theta);
            if isnan(M.VSWR) || isinf(M.VSWR)
                vswrPenalty = 10;
            else
                vswrPenalty = max(0, M.VSWR - 2);
            end
            score = M.gain_max + 0.6*M.FB - 0.5*vswrPenalty;

            bestMetalList(k).ds = ds;
            bestMetalList(k).ss = ss;
            bestMetalList(k).boom_mm = boom_len_mm;
            bestMetalList(k).M = M;
            bestMetalList(k).L_dirs = L_dirs;
            bestMetalList(k).spacings = spacings;
            bestMetalList(k).score = score;
            k = k + 1;
        catch
            % Skip, if meshing fails over metal
            continue;
        end
    end
end

if isempty(bestMetalList)
    error('No metal-mounted candidate found.');
end

% pick best metal-optimized candidate
scoresM = [bestMetalList.score];
[~, ixM] = max(scoresM);
bestM = bestMetalList(ixM);

fprintf('Best metal-optimized: ds=%.3f ss=%.3f boom=%.1f mm gain=%.2f F/B=%.2f VSWR=%s\n', ...
    bestM.ds, bestM.ss, bestM.boom_mm, bestM.M.gain_max, bestM.M.FB, ...
    mat2str(bestM.M.VSWR,4));

% Build optimized Yagi for metal
d_exc_mopt = dipole('Length', L_driven, 'Width', thinWidth);
ant_metal_opt_yagi = yagiUda( ...
    'Exciter', d_exc_mopt, ...
    'NumDirectors', numel(bestM.L_dirs), ...
    'ReflectorLength', L_reflector, ...
    'DirectorLength', bestM.L_dirs, ...
    'ReflectorSpacing', bestM.spacings(1), ...
    'DirectorSpacing', bestM.spacings(2:end));

ant_metal_opt = reflector( ...
    'Exciter', ant_metal_opt_yagi, ...
    'GroundPlaneLength', 1.0*lambda, ...
    'GroundPlaneWidth',  1.0*lambda, ...
    'Spacing', h_worst);

% show optimized geometry
figOptG = figure('Name','Optimized metal geometry');
show(ant_metal_opt);
title('Optimized Yagi over metal');
if saveFigures
    try
        saveas(figOptG, sprintf('%s_metal_opt_geometry_h%.3flambda.png', ...
            outPrefix, h_worst/lambda));
    catch
        warning('Could not save optimized geometry');
    end
end

try
    figOpt3D = figure('Name','Optimized metal 3D');
    pattern(ant_metal_opt, f0);
    title('Optimized 3D pattern (over metal)');
catch
    warning('Could not display optimized 3D pattern.');
end

%% FINAL METRICS & COMPARISONS 
M_metal_opt   = computeMetrics(ant_metal_opt, f0, Z0, theta);

CaseNames = {
    'Free-space';
    sprintf('Optimised_h%.3fL', h_worst/lambda)
};

GainVec = [ M_fs.gain_max;        M_metal_opt.gain_max ];
FBVec   = [ M_fs.FB;              M_metal_opt.FB       ];
VSWRVec = [ M_fs.VSWR;            M_metal_opt.VSWR     ];

T = table( ...
    CaseNames, ...
    GainVec, ...
    FBVec, ...
    VSWRVec, ...
    'VariableNames', {'Case','Gain_dBi','FB_dB','VSWR'} ...
);

if saveCSV
    writetable(T, sprintf('%s_final_comparison.csv', outPrefix));
end

fprintf('\n--- Final Comparison Table ---\n');
fprintf('%-18s  %8s  %8s  %8s\n', 'Case', 'Gain(dBi)', 'F/B(dB)', 'VSWR');
for i = 1:height(T)
    fprintf('%-18s  %8.2f  %8.2f  %8.3f\n', ...
        T.Case{i}, T.Gain_dBi(i), T.FB_dB(i), T.VSWR(i));
end

%% E-PLANE & H-PLANE CARTESIAN PLOTS

% E-plane: phi = 0
pat_fs  = pattern(ant_free,        f0, 0, theta);
pat_opt = pattern(ant_metal_opt,   f0, 0, theta);

figCmp = figure('Name','E-plane comparison');
hold on;
plot(theta, pat_fs,  'LineWidth',1.5);
plot(theta, pat_opt, 'LineWidth',1.5);
grid on;
xlabel('\theta (deg)');
ylabel('Gain (dBi)');
legend('Free-space','Re-optimized on metal','Location','best');
title('E-plane (phi=0) comparison');
if saveFigures
    try
        saveas(figCmp, sprintf('%s_Eplane_comparison.png', outPrefix));
    catch
        warning('Could not save E-plane comparison');
    end
end

% H-plane: phi = 90 deg
thetaH = theta;
pat_fs_H  = pattern(ant_free,        f0, 90, thetaH);
pat_opt_H = pattern(ant_metal_opt,   f0, 90, thetaH);

figCmpH = figure('Name','H-plane comparison');
hold on;
plot(thetaH, pat_fs_H,  'LineWidth',1.5);
plot(thetaH, pat_opt_H, 'LineWidth',1.5);
grid on;
xlabel('\theta (deg)');
ylabel('Gain (dBi)');
legend('Free-space','Re-optimized on metal','Location','best');
title('H-plane (phi=90) comparison');
if saveFigures
    try
        saveas(figCmpH, sprintf('%s_Hplane_comparison.png', outPrefix));
    catch
        warning('Could not save H-plane comparison');
    end
end

%% E-PLANE & H-PLANE POLAR PLOTS 

% E-plane:phi / az = 0 deg 
try
    figEPol_fs = figure('Name','E-plane polar - Free-space');
    patternElevation(ant_free, f0, 0);
    title('E-plane polar (Free-space, az = 0°)');

    figEPol_opt = figure('Name','E-plane polar - Re-optimized on metal');
    patternElevation(ant_metal_opt, f0, 0);
    title(sprintf('E-plane polar (Re-optimized, h = %.3f\\lambda)', h_worst/lambda));
catch
    warning('E-plane polar plots failed due to graphics issue.');
end

% H-plane:elevation = 0 deg
try
    figHPol_fs = figure('Name','H-plane polar - Free-space');
    patternAzimuth(ant_free, f0, 0);
    title('H-plane polar (Free-space, el = 0°)');

    figHPol_opt = figure('Name','H-plane polar - Re-optimized on metal');
    patternAzimuth(ant_metal_opt, f0, 0);
    title(sprintf('H-plane polar (Re-optimized, h = %.3f\\lambda)', h_worst/lambda));
catch
    warning('H-plane polar plots failed due to graphics issue.');
end


%% VSWR vs FREQUENCY (BANDWIDTH)
fSweep = linspace(1.8e9, 2.0e9, 41);  % 1.8 to 2.0 GHz
VSWR_band = nan(size(fSweep));

for i = 1:numel(fSweep)
    f = fSweep(i);
    try
        Zin_f = impedance(ant_metal_opt, f);
        Gamma_f = (Zin_f - Z0) / (Z0 + Zin_f);
        gabs_f = abs(Gamma_f);
        if gabs_f >= 0.9999
            VSWR_band(i) = Inf;
        else
            VSWR_band(i) = (1 + gabs_f) / (1 - gabs_f);
        end
    catch
        VSWR_band(i) = NaN;
    end
end

figVSF = figure('Name','VSWR vs frequency');
plot(fSweep/1e9, VSWR_band, '-o','LineWidth',1.5);
grid on;
xlabel('Frequency (GHz)');
ylabel('VSWR');
title('VSWR vs frequency for re-optimized metal-mounted Yagi');

if saveFigures
    try
        saveas(figVSF, sprintf('%s_VSWR_band_reopt.png', outPrefix));
    catch
        warning('Could not save VSWR vs frequency plot');
    end
end

validIdx = find(VSWR_band <= 2);
if ~isempty(validIdx)
    f_low  = fSweep(min(validIdx))/1e9;
    f_high = fSweep(max(validIdx))/1e9;
    bw_pct = (f_high - f_low)/((f_high + f_low)/2)*100;
    fprintf('Approx. VSWR <= 2 bandwidth: %.3f–%.3f GHz (%.1f%%)\n', ...
        f_low, f_high, bw_pct);
else
    fprintf('VSWR never drops below 2 in 1.8–2.0 GHz for the re-optimized antenna.\n');
end

fprintf('\n--- Report Summary ---\n');
fprintf('Free-space VS metal-mounted Yagi comparison at 1.9 GHz.\n');
fprintf('Metal height used for re-optimization: h = %.3f λ\n', h_worst/lambda);
fprintf('Final gain, F/B ratio and VSWR are shown in the comparison table above.\n');

%% LOCAL HELPER FUNCTION
function M = computeMetrics(antObj, f0, Z0, theta)
    % compute metrics: gain, fwd/back, impedance, VSWR
    pat = pattern(antObj, f0, 0, theta);
    M.gain_max = max(pat);
    M.gain_fwd = interp1(theta, pat, 0);
    M.gain_back= interp1(theta, pat, 180);
    M.FB = M.gain_fwd - M.gain_back;
    try
        Zin = impedance(antObj, f0);
        Gamma = (Zin - Z0) / (Z0 + Zin);
        gabs = abs(Gamma);
        if gabs >= 0.9999
            M.VSWR = Inf;
        else
            M.VSWR = (1 + gabs) / (1 - gabs);
        end
        M.Zin = Zin;
    catch
        M.VSWR = NaN;
        M.Zin  = NaN + 1i*NaN;
    end
end