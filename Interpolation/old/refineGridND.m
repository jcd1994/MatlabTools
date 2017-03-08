function [ Vk ] = refineGridND( V, K )
%REFINEGRIDND Returns the interpolated values on a refined grid formed by
% repeatedly dividing the intervals K times in each dimension.

if isvector(V)
    dim	=   1;
else
    dim	=   ndims(V);
end

switch dim
    case 1
        
        Vk	=   V(:);
        for k = 1:K
            Vk	=   refineGridOnce1D( Vk );
        end
        if size(V,1) == 1
            Vk	=   reshape( Vk, 1, [] );
        end
        
    case 2
        
        Vk	=   V;
        for k = 1:K
            Vk	=   refineGridOnce2D( Vk );
        end
        
    case 3
        
        Vk	=   V;
        for k = 1:K
            Vk	=   refineGridOnce3D( Vk );
        end
        
end

end

function Vk = refineGridOnce1D( V )

Vsize	=   size(V);
Vk      =   zeros( 2*Vsize(1)-1, 1, 'like', V );
Vk(2:2:end)	=   0.5 * (V(1:end-1) + V(2:end));
Vk(1:2:end)	=   V;

end

function Vk = refineGridOnce2D( V )

Vsize	=   size(V);
Vk      =   zeros( 2*Vsize(1)-1, Vsize(2), 'like', V );
Vk(2:2:end,:)	=   0.5 * (V(1:end-1,:) + V(2:end,:));
Vk(1:2:end,:)	=   V;

V       =   Vk;
Vsize	=   size(V);
Vk      =   zeros( Vsize(1), 2*Vsize(2)-1, 'like', V );
Vk(:,2:2:end)	=   0.5 * (V(:,1:end-1) + V(:,2:end));
Vk(:,1:2:end)	=   V;

end

function Vk = refineGridOnce3D( V )

Vsize	=   size(V);
Vk      =   zeros( 2*Vsize(1)-1, Vsize(2), Vsize(3), 'like', V );
Vk(2:2:end,:,:)	=   0.5 * (V(1:end-1,:,:) + V(2:end,:,:));
Vk(1:2:end,:,:)	=   V;

V       =   Vk;
Vsize	=   size(V);
Vk      =   zeros( Vsize(1), 2*Vsize(2)-1, Vsize(3), 'like', V );
Vk(:,2:2:end,:)	=   0.5 * (V(:,1:end-1,:) + V(:,2:end,:));
Vk(:,1:2:end,:)	=   V;

V       =   Vk;
Vsize	=   size(V);
Vk      =   zeros( Vsize(1), Vsize(2), 2*Vsize(3)-1, 'like', V );
Vk(:,:,2:2:end)	=   0.5 * (V(:,:,1:end-1) + V(:,:,2:end));
Vk(:,:,1:2:end)	=   V;

end

function testing

%==========================================================================
% 1D Testing
%==========================================================================
f	=	@(x) sin(x);
n	=	16;
k	=	2;
nk	=   (n-1)*2^k+1;
X	= linspace(-pi,pi,n)';
Xk	= linspace(-pi,pi,nk)';
V	= f(X);
Vk	= refineGridND(V,k);
figure, plot(X,V,'ro'), hold on, plot(Xk,Vk,'b.');
title( ['Refine Grid: 1D, k = ' num2str(k)] )

%==========================================================================
% 2D Testing
%==========================================================================
f = @(x,y) sin(x).*cos(y);
n = 16;
k = 2;
nk	=   (n-1)*2^k+1;
[X,Y]	=	meshgrid(linspace(-pi,pi,n));
[Xk,Yk]	=	meshgrid(linspace(-pi,pi,nk));
V = f(X,Y);
Vk = refineGridND(V,k);
figure, plot3(X,Y,V,'k.','markersize',10), hold on, surf(Xk,Yk,Vk), axis image;
title( ['Refine Grid: 2D, k = ' num2str(k)] )

%==========================================================================
% 3D Testing
%==========================================================================
f	=	@(x,y,z) sin(x).*cos(y).*sin(2*x.*z);
n	=	16;
k	=	2;
nk	=   (n-1)*2^k+1;
[X,Y,Z]     =	meshgrid(linspace(-pi,pi,n));
[Xk,Yk,Zk]	=	meshgrid(linspace(-pi,pi,nk));
V = f(X,Y,Z);
Vk = refineGridND(V,k);

n2	=   floor(n/2);
nk2	=   floor(nk/2);
figure, plot3(X(:,:,n2),Y(:,:,n2),V(:,:,n2),'k.','markersize',10), hold on
surf(Xk(:,:,nk2),Yk(:,:,nk2),Vk(:,:,nk2)), axis image;
title( ['Refine Grid: 3D, Z-Slice, k = ' num2str(k)] )


end


