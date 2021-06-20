% Image Enhancement Using Intensity Transformations

clear all; close all; clc;

c=0.5;d=1;gamma=5;

% Read a RGB image
A = imread('fig3.9.jpg');

% Convert RGB image to Grayscale
A_gray = rgb2gray(A);
a2=zeros(size(A_gray,1),size(A_gray,2));
a2(:,:)=c*log(double(A_gray(:,:))/255+1)*255;
a2=uint8(a2);
a3=zeros(size(A_gray,1),size(A_gray,2));
a3(:,:)=d*(double(A_gray(:,:))/255).^gamma*255;
a3=uint8(a3);
figure, subplot(1, 3, 1),imshow(A_gray), title('Original');
subplot(1, 3, 2), imshow(a2), title('Log-3.2-2');
subplot(1, 3, 3), imshow(a3), title('Power-3.2-3');


























