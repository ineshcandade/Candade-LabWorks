% Read the image file into a variable called 'I'.
I = imread('My_Image.jpg');

% Convert the color image to a grayscale image.
I_gray = rgb2gray(I);

% Display the original image.
figure;
imshow(I);
text(10, size(I, 1) - 40, 'Original Image', 'Color', 'white', 'FontSize', 12, 'FontWeight', 'bold');

% Display the grayscale image.
figure;
imshow(I_gray);
text(10, size(I_gray, 1) - 40, 'Grayscale Image', 'Color', 'white', 'FontSize', 11, 'FontWeight', 'bold');