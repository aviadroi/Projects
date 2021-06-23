% Implementing the Laplacian enhancement technique.

clear all; close all; clc;

% Read a RGB image
A = imread('fig3.38a.jpg');
A_gray = rgb2gray(A);

% Laplacian without diagonal elements:
w=[0 1 0; 1 -4 1; 0 1 0];
% Laplacian with diagonal elements:
w2=[1 1 1; 1 -8 1; 1 1 1];

Am=zeros(size(A_gray,1)+2,size(A_gray,2)+2);
Am(2:end-1,2:end-1)=A_gray(:,:);

Af=zeros(size(Am,1),size(Am,2));
Ag=zeros(size(Am,1),size(Am,2));
Af1=zeros(size(Am,1),size(Am,2));
Af2=zeros(size(Am,1),size(Am,2));

Af(2:end-1,2:end-1)=w(1,1)*Am(1:end-2,1:end-2)+w(1,2)*Am(1:end-2,2:end-1)+w(1,3)*Am(1:end-2,3:end)...
+w(2,1)*Am(2:end-1,1:end-2)+w(2,2)*Am(2:end-1,2:end-1)+w(2,3)*Am(2:end-1,3:end)...
+w(3,1)*Am(3:end,1:end-2)+w(3,2)*Am(3:end,2:end-1)+w(3,3)*Am(3:end,3:end);

Ag(2:end-1,2:end-1)=w2(1,1)*Am(1:end-2,1:end-2)+w2(1,2)*Am(1:end-2,2:end-1)+w2(1,3)*Am(1:end-2,3:end)...
+w2(2,1)*Am(2:end-1,1:end-2)+w2(2,2)*Am(2:end-1,2:end-1)+w2(2,3)*Am(2:end-1,3:end)...
+w2(3,1)*Am(3:end,1:end-2)+w2(3,2)*Am(3:end,2:end-1)+w2(3,3)*Am(3:end,3:end);

Af1=((Af-min(min(Af)))*255/(max(max(Af))-min(min(Af))));
% also possible:
% Af1=(Af-min(min(Af)));
% Af1=Af1/max(max(Af1))*255;
Ag1=((Ag-min(min(Ag)))*255/(max(max(Ag))-min(min(Ag))));

Af2=Am-Af;
Ag2=Am-Ag;

Am=uint8(Am);
% Afu=uint8(Af);
Afs=uint8(Af1);
Ags=uint8(Ag1);
Af2=uint8(Af2);
Ag2=uint8(Ag2);

figure, subplot(2, 3, 1),imshow(Am), title('Original');
subplot(2, 3, 2),imshow(Af2), title('Adding Laplacian #1');
subplot(2, 3, 3),imshow(Ag2), title('Adding Laplacian #2');
subplot(2, 3, 4),imshow(Afs), title('Laplacian #1 (grayscaled)');
subplot(2, 3, 5),imshow(Ags), title('Laplacian #2 (grayscaled)');
