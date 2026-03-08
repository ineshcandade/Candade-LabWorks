% Read the audio file into a variable.
[y, Fs] = audioread('3rd_Project_Audio.mp3');

% Make sure the signal has an even length 
if mod(length(y), 2) ~= 0
    y = y(1:end-1);
end

% Perform the Fast Fourier Transform (FFT).
Y = fft(y);
L = length(y);
P2 = abs(Y/L);
f = Fs*(0:(L-1))/L;

% Perform the Filtering (Low-Pass Filter) 
% Create a simple low-pass filter. This REMOVES high frequencies.
high_frequency_limit = 2000; 
high_frequency_indices = (f > high_frequency_limit);

% Set the high frequencies in the spectrum to zero.
Y_filtered = Y;
Y_filtered(high_frequency_indices) = 0;
Y_filtered((L - high_frequency_indices) + 2) = 0;

% Perform the Inverse FFT to get the filtered audio
y_filtered = ifft(Y_filtered);

% Plot and Play the Audio 
% Display the original and filtered frequency spectrums.
figure;
plot(f(1:L/2+1), P2(1:L/2+1));
hold on;
P2_filtered = abs(Y_filtered/L);
plot(f(1:L/2+1), P2_filtered(1:L/2+1), 'r', 'LineWidth', 2);
title('Frequency Spectrum');
xlabel('Frequency (Hz)');
ylabel('Magnitude');
legend('Original', 'Filtered');
hold off;

% Play the original audio.
soundsc(y, Fs);
pause(27); % Pause for 27 seconds 

% Play the filtered audio.
soundsc(real(y_filtered), Fs);