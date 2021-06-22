clear all; close all; clc;
% Read a RGB image
A_gray = imread('fig3.20.jpg');
A_gray = rgb2gray(A_gray);
[d,e]=imhist(A_gray);
disp([d,e]);
s=zeros(256,1);
for x=1:256
s(x,1)=uint8(255/(size(A_gray,1)*size(A_gray,2))*sum(d(1:x)));
end
A_mapped(:,:)=s(A_gray(:,:)+1);
A2_mapped=uint8(A_mapped);
[g,h]=imhist(A2_mapped);
d=d/(size(A_gray,1)*size(A_gray,2));
g=g/(size(A2_mapped,1)*size(A2_mapped,2));
figure, subplot(2, 2, 1),imshow(A_gray), title('Original Im.');
subplot(2, 2, 2),imshow(A2_mapped), title('Equalized Hist. Im.');
subplot(2, 2, 3),bar(d), title('Orig. Hist.');
subplot(2, 2, 4),bar(g), title('Eq. Hist.');
% Also works:
%for f=1:256
%    r(f)=sum(d(find(s==(f-1))))/(size(A_gray,1)*size(A_gray,2));
%end
% subplot(2, 2, 4),bar(r), title('Eq. Hist.');