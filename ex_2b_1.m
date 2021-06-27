clear all; close all; clc;

% Read a RGB image
A = imread('exmp3.jpg');
A_gray = rgb2gray(A);
A_gray=im2double(A_gray);
a2=zeros(size(A_gray,1),size(A_gray,2));
a1=input('enter a number:');
a2=assign4(A_gray,a1);
a3=a2/255;
figure, subplot(1, 2, 1), imshow(A), title('Input RGB image');
subplot(1, 2, 2), imshow(a3), title('new Grayscale image');

function y=assign4(x,x1)
y1=zeros(size(x,1),size(x,2));
y=zeros(size(x,1),size(x,2));
x2=[0:floor(255/(2^x1-1)):floor(255/(2^x1-1))*(2^x1-2) 255];
for ky=1:size(x,1)
    for kx=1:size(x,2)
y1(ky,kx)=min(find(abs(255*x(ky,kx)-x2)==min(abs(255*x(ky,kx)-x2))));
y(ky,kx)=x2(y1(ky,kx));
    end
end
end