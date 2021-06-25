% A program for converting the dots in gray-scale images into patterns (halftoning).

clear all; close all; clc;

% Read a RGB image
A = imread('small.jpg');

% Convert RGB image to Grayscale
A_gray = rgb2gray(A);
% A_gray=[50 80 230; 10 40 90; 190 130 60];

z1=25;z2=50;z3=75;z4=100;z5=125;z6=150;z7=175;z8=200;z9=225;

a2=zeros(size(A_gray,1),size(A_gray,2));
a2(:,:)=assign(A_gray(:,:),z1,z2,z3,z4,z5,z6,z7,z8,z9);
a3=zeros(size(A_gray,1)*3,size(A_gray,2)*3);
a3=repelem(a2,3,3);

booklet(1:3,1:3,1:10)=0;booklet(1,2,2)=1;
booklet(1,2,3)=1;booklet(3,3,3)=1;
booklet(1,1:2,4)=1;booklet(3,3,4)=1;
booklet(1,1:2,5)=1;booklet(3,1,5)=1;boolet(3,3,5)=1;
booklet(1,1:3,6)=1;booklet(3,1,6)=1;booklet(3,3,6)=1;
booklet(1,1:3,7)=1;booklet(2:3,3,7)=1;booklet(3,1,7)=1;
booklet(1:3,1:3,8)=1;booklet(2,1:2,8)=0;
booklet(1:3,1:3,9)=1;booklet(2,2,9)=0;
booklet(1:3,1:3,10)=1;

for f=1:10
[row,col]=find(a3==f);
disp([size(a3,1),size(a3,2)]);
a3(a3==f)=diag(booklet(mod(row-1,3)+1,mod(col-1,3)+1,f));
end

% Display the conversion result
figure, subplot(1, 3, 1), imshow(A), title('Input RGB image');
subplot(1, 3, 2), imshow(A_gray), title('Converted Grayscale image');
subplot(1, 3, 3), imshow(a3), title('half-toned image');

function y=assign(x,n1,n2,n3,n4,n5,n6,n7,n8,n9)
y=zeros(size(x,1),size(x,2));
y(:,:)=1*(x(:,:)<=n1)+2*(x(:,:)>n1 & x(:,:)<=n2)+3*(x(:,:)>n2 & x(:,:)<=n3)+4*(x(:,:)>n3 & x(:,:)<=n4)+5*(x(:,:)>n4 & x(:,:)<=n5)+6*(x(:,:)>n5 & x(:,:)<=n6)+7*(x(:,:)>n6 & x(:,:)<=n7)+8*(x(:,:)>n7 & x(:,:)<=n8)+9*(x(:,:)>n8 & x(:,:)<=n9)+10*(x(:,:)>n9)
end
