% Read audio file.
[y, Fs] = audioread('Song.mp3');
% Create time vector.
t = (0:length(y)-1) / Fs;
% Plot time-domain signal.
figure;
plot(t, y);
title('Time-Domain Signal');
xlabel('Time (s)');
ylabel('Amplitude');
% Perform FFT.
Y = fft(y);
P2 = abs(Y/length(y));
% Correct for symmetry and get single-sided spectrum.
P1 = P2(1:length(y)/2+1);
P1(2:end-1) = 2*P1(2:end-1);
% Create frequency vector.
f = Fs*(0:(length(y)/2))/length(y);
% Plot frequency spectrum.
figure;
plot(f, P1);
title('Audio Frequency Spectrum');
xlabel('Frequency (Hz)');
ylabel('|P1(f)|');