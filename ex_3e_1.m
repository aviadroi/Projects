% Implementing the technique of unsharp masking using Gaussian smoothing filter.

clear all; close all; clc;

% Read a RGB image
A = imread('fig3.40a.jpg');
A_gray = rgb2gray(A);
w=zeros(5);
sigma=3;k=4.5;
w=gaussmat(sigma);
% w=0.04*[1 1 1 1 1; 1 1 1 1 1; 1 1 1 1 1; 1 1 1 1 1; 1 1 1 1 1];

Am=zeros(size(A_gray,1)+4,size(A_gray,2)+4);
Am(3:end-2,3:end-2)=A_gray(:,:);

Af=zeros(size(Am,1),size(Am,2));
% mask=zeros(size(Am,1),size(Am,2));

Af(3:end-2,3:end-2)=w(1,1)*Am(1:end-4,1:end-4)+w(1,2)*Am(1:end-4,2:end-3)+w(1,3)*Am(1:end-4,3:end-2)+w(1,4)*Am(1:end-4,4:end-1)+w(1,5)*Am(1:end-4,5:end)...
+w(2,1)*Am(2:end-3,1:end-4)+w(2,2)*Am(2:end-3,2:end-3)+w(2,3)*Am(2:end-3,3:end-2)+w(2,4)*Am(2:end-3,4:end-1)+w(2,5)*Am(2:end-3,5:end)...
+w(3,1)*Am(3:end-2,1:end-4)+w(3,2)*Am(3:end-2,2:end-3)+w(3,3)*Am(3:end-2,3:end-2)+w(3,4)*Am(3:end-2,4:end-1)+w(3,5)*Am(3:end-2,5:end)...
+w(4,1)*Am(4:end-1,1:end-4)+w(4,2)*Am(4:end-1,2:end-3)+w(4,3)*Am(4:end-1,3:end-2)+w(4,4)*Am(4:end-1,4:end-1)+w(4,5)*Am(4:end-1,5:end)...
+w(5,1)*Am(5:end,1:end-4)+w(5,2)*Am(5:end,2:end-3)+w(5,3)*Am(5:end,3:end-2)+w(5,4)*Am(5:end,4:end-1)+w(5,5)*Am(5:end,5:end);

mask=Am-Af;

Am2=Am+k*mask
Am=uint8(Am);
Am2=uint8(Am2);
Af=uint8(Af);
mask=uint8(mask);

figure, subplot(2, 2, 1),imshow(Am), title('Original');
subplot(2, 2, 2),imshow(Af), title('Blurred image');
subplot(2, 2, 3),imshow(mask), title('The mask');
subplot(2, 2, 4),imshow(Am2), title('Unsharp-result');

function m = gaussmat(sigma)
m=zeros(5);
x=1:5;
m=repelem(x'.*x',1,5)+repelem(x.*x,5,1)
m=exp(-m/(2*sigma^2));
m=m/sum(sum(m))
end