% This is 2D Fourier Transform "package". It takes an image and computes its (centered) Fourier spectrum. It then shows the inverse transform.
% It uses a Gaussian lowpass filter in the frequency domain, and compares it with direct filtering in the spatial domain. 
spectrum
h=[-1 0 1;-2 0 2;-1 0 1];
t = imread('fig4.41a.jpg');
A_gray = rgb2gray(t);
a=uint8(A_gray);

g5=dir_fil(a,h);

a0=padding(a,size(a,1),size(a,2),size(h,1),size(h,2));
h0=padding(h,size(a,1),size(a,2),size(h,1),size(h,2));
a0c=centering(a0);
h0c=centering(h0);
A=transform(a0c)
H=transform(h0c)

G=mult(A,H)
g1=real(transform(conj(G/((size(a,1)+size(h,1))*(size(a,2)+size(h,2))))))
g3=real(transform(conj(A/((size(a,1)+size(h,1))*(size(a,2)+size(h,2))))))

g0=centering(g1)
g=antip(g0,size(a,1),size(a,2))
g2=(g-min(min(g)))/(max(max(g))-min(min(g)));

g0=centering(g3)
g=antip(g0,size(a,1),size(a,2))
g4=(g-min(min(g)))/(max(max(g))-min(min(g)));

%w=uint8(w*255);
g2=im2double(g2);
g4=im2double(g4);

A=abs(A);
A=im2double(A);

figure, subplot(2, 3, 1),imshow(A_gray), title('Original');
subplot(2, 3, 2),imshow(histo(A)), title('DFT (spectrum)');
subplot(2, 3, 3),imshow(g4), title('IDFT (Unfiltered)');
subplot(2, 3, 4),imshow(g2), title('IDFT (Filtered)');
subplot(2, 3, 5),imshow(g5), title('Spacial-filtered)');

function y=dir_fil(a,w)

Am=zeros(size(a,1)+2,size(a,2)+2);
Am(2:end-1,2:end-1)=a(:,:);

Af=zeros(size(Am,1),size(Am,2));

Af(2:end-1,2:end-1)=w(3,3)*Am(1:end-2,1:end-2)+w(3,2)*Am(1:end-2,2:end-1)+w(3,1)*Am(1:end-2,3:end)...
+w(2,3)*Am(2:end-1,1:end-2)+w(2,2)*Am(2:end-1,2:end-1)+w(2,1)*Am(2:end-1,3:end)...
+w(1,3)*Am(3:end,1:end-2)+w(1,2)*Am(3:end,2:end-1)+w(1,1)*Am(3:end,3:end);

Af=(Af-min(min(Af)))/(max(max(Af))-min(min(Af)));

%w=uint8(w*255);
y=im2double(Af);

end

function y=padding(a,sa1,sa2,sa3,sa4)
y=zeros(sa1+sa3,sa2+sa4);
y(1:size(a,1),1:size(a,2))=a;
end

function y=transform(g)
bv=0:size(g,2)-1;
bu=0:size(g,1)-1;
cu=kron(transpose(bu),ones(1,size(bv,2)));
cv=kron(bv,transpose(ones(1,size(bu,2))));
y=zeros(size(g,1),size(g,2));
for v=1:size(g,2)
    for u=1:size(g,1)
    y(u,v)=sum(sum(g.*(exp(-i*2*pi*(u-1)/size(bu,2)).^cu)).*(exp(-i*2*pi*(v-1)/size(bv,2)).^bv));
    end
end
end

function y=histo(c)
A_mapped=zeros(size(c,1),size(c,2));
c2=uint8(255*c/(max(max(c))-min(min(c))));
[d,e]=imhist(c2);
s=zeros(256,1);
for r=1:256
s(r,1)=uint8(255/(size(c2,1)*size(c2,2))*sum(d(1:r)));
end
A_mapped(:,:)=s(c2(:,:)+1);
y=uint8(A_mapped);
end

function y=centering(a)
ax=1:size(a,2);
ay=1:size(a,1);
axy=kron(transpose(ay),ones(1,size(ax,2)))+kron(ones(size(ay,2),1),ax);
axy=(-1).^axy;
y=a.*axy;
end

function y=mult(A,H)
y=A.*H;
end

function y=dub(tr)
y=2*tr;
end

function y=antip(a,sa1,sa2)
y(1:sa1,1:sa2)=a(1:sa1,1:sa2);
end

function y=shi(a,sa1,sa2,sa3,sa4)
y=zeros(sa1+sa3,sa2+sa4);
y(1:size(a,1),1:size(a,2))=a;
end
