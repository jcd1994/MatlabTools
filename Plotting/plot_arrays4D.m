function [ ] = plot_arrays4D( A, maxrows, slices, types, xb, yb, zb )
%PLOT_ARRAYS4D( A, maxrows, slices, types, xb, yb, zb )
% Plots the 4D array A.

%==========================================================================
% Input Parsing
%==========================================================================
if ~isa( A, 'cell' )
    A	=   { A };
end

rep	=   @(x) repmat( x, 1, numel(A) );

if nargin < 2 || isempty( maxrows )
    maxrows	=   rep(3);
elseif isscalar( maxrows )
    maxrows	=   rep(maxrows);
end

if nargin < 3
    slices	=   rep( {[]} );
elseif ~isa( slices, 'cell' )
    slices	=   rep( {slices} );
elseif isscalar( slices )
    slices	=   rep( slices );
end

if nargin < 4 || isempty( types )
    types	=   rep( 0 );
elseif isscalar( types )
    types	=   rep( types );
end

if nargin < 7 || isempty(xb) || isempty(yb) || isempty(zb)
    [xb,yb,zb]	=   deal( rep({[]}) );
else
    [xb,yb,zb]	=   deal( rep({xb}), rep({yb}), rep({zb}) );
end

%==========================================================================
% Plot Arrays
%==========================================================================
for ii = 1:numel(A)
    plot_array4D( A{ii}, maxrows(ii), slices{ii}, types(ii), xb{ii}, yb{ii}, zb{ii} );    
end

end

function plot_array4D( A, maxrows, slices, type, xb, yb, zb )

if size(A,4) > maxrows
    tidx	=   round(linspace(1,size(A,4),maxrows));
    A       =   A(:,:,:,tidx);
else
    tidx	=   1:size(A,4);
end

Asize	=   size(A);
if numel(Asize) < 4
    Asize(end+1:4)	=   1;
end

if isa(A,'logical'); A = single(A); end

if isempty( slices ) || ( numel( slices ) ~= 3 )
    slices	=   round( size(A)/2 );
end

if isempty(xb) || numel(xb) ~= 2, xb = [1,Asize(1)]; end
if isempty(yb) || numel(yb) ~= 2, yb = [1,Asize(2)]; end
if isempty(zb) || numel(zb) ~= 2, zb = [1,Asize(3)]; end

switch type
    otherwise
        % Default surf
        plot_array4D_surf( A, slices, tidx, xb, yb, zb );
end

end

function plot_array4D_surf( A, slices, tidx, xb, yb, zb )

Asize	=   size(A);
if numel(Asize) < 4; Asize(end+1:4) = 1; end

m       =   length(tidx);
x       =	linspace(xb(1),xb(2),Asize(1)).';
y       =	linspace(yb(1),yb(2),Asize(2)).';
z       =	linspace(zb(1),zb(2),Asize(3)).';

[Y_yz,Z_yz]	=   ndgrid(y,z);
[X_xz,Z_xz]	=   ndgrid(x,z);
[X_xy,Y_xy]	=   ndgrid(x,y);

minmaxall	=   @(x) [min(x(:)),max(x(:))];
addeps      =   @(xb) double(xb)+eps('double')*[-1,1];
Zlim_X	=   minmaxall( A(slices(1),:,:,:) );
Zlim_Y	=   minmaxall( A(:,slices(2),:,:) );
Zlim_Z	=   minmaxall( A(:,:,slices(3),:) );
if ~diff(Zlim_X); Zlim_X = addeps(Zlim_X); end
if ~diff(Zlim_Y); Zlim_Y = addeps(Zlim_Y); end
if ~diff(Zlim_Z); Zlim_Z = addeps(Zlim_Z); end

if m > 1,	zlab	=	@(ii) sprintf( 'Time: %d/%d', tidx(ii), tidx(m) );
else        zlab	=	@(ii) '';
end
    
figure;
props	=   { 'linestyle', 'none' };
for ii = 1:m
    
    [px,py,pz]	=   dealArray( (1:3) + 3*(ii-1) );
        
    % X-subplot
    subplot(m,3,px), hold on
    a	=   double(squeeze(A(slices(1),:,:,ii)));
    hx	=	surf(Y_yz,Z_yz,a,props{:});
    xlim(yb); xlabel('y');
    ylim(zb); ylabel('z');
    zlim(Zlim_X); zlabel(zlab(ii));
    view([1,1,0.5]);
    
    % Y-subplot
    subplot(m,3,py), hold on
    a	=   double(squeeze(A(:,slices(2),:,ii)));
    hy	=	surf(X_xz,Z_xz,a,props{:});
    xlim(xb); xlabel('x');
    ylim(zb); ylabel('z');
    zlim(Zlim_Y); zlabel(zlab(ii));
    view([1,1,0.5]);
    
    % Z-subplot
    subplot(m,3,pz), hold on
    a	=   double(A(:,:,slices(3),ii));
    hz	=	surf(X_xy,Y_xy,a,props{:});
    xlim(xb); xlabel('x');
    ylim(yb); ylabel('y');
    zlim(Zlim_Z); zlabel(zlab(ii));
    view([1,1,0.5]);
    
    if ii == 1
        str	=   @(ii) sprintf( ': %d/%d', slices(ii), Asize(ii) );
        subplot(m,3,px), title( [ 'X', str(1) ] );
        subplot(m,3,py), title( [ 'Y', str(2) ] );
        subplot(m,3,pz), title( [ 'Z', str(3) ] );
    end
    
end

end
