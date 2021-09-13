% A program which converts a given image to 10 levels of gray, which are represented by 10 (3 x 3) dot patterns of black and white dots.

clear all; close all; clc;

% Read a RGB image
A = imread('fig6.37.jpg');
% Convert RGB image to Grayscale
A_gray = rgb2gray(A);

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
    for v=1:size(row,1)
        a3(row(v),col(v))=booklet(mod(row(v)-1,3)+1,mod(col(v)-1,3)+1,f);
    end
end

% Display the conversion result
figure, subplot(3, 1, 1), imshow(A), title('Input image');
subplot(3, 1, 2), imshow(A_gray), title('Gray-converted image');
subplot(3, 1, 3), imshow(a3), title('half-toned image');

function y=assign(x,n1,n2,n3,n4,n5,n6,n7,n8,n9)
y=zeros(size(x,1),size(x,2));
y(:,:)=1*(x(:,:)<=n1)+2*(x(:,:)>n1 & x(:,:)<=n2)+3*(x(:,:)>n2 & x(:,:)<=n3)+4*(x(:,:)>n3 & x(:,:)<=n4)+5*(x(:,:)>n4 & x(:,:)<=n5)+6*(x(:,:)>n5 & x(:,:)<=n6)+7*(x(:,:)>n6 & x(:,:)<=n7)+8*(x(:,:)>n7 & x(:,:)<=n8)+9*(x(:,:)>n8 & x(:,:)<=n9)+10*(x(:,:)>n9);
end

