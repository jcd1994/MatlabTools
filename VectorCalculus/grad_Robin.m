function [varargout] = grad_Robin(img, vSize, type, varargin)
%GRAD_ROBIN First order forward finite difference gradient with Robin BC.
%
% INPUT ARGUMENTS
%   img:    -[MxNxP] image array
%   vSize:  -[1x1, 3x1, empty] voxel dimensions
%   type:   -['Neumann' (default), 'Robin', 'Same'] Boundary conditions
%               Neumann:    dx, dy, dz last points satisfy:
%                              	dx(end,:,:) = 0;
%                               dy(:,end,:) = 0;
%                              	dz(:,:,end) = 0;
% 
%               Robin:      dx, dy, dz last points satisfy:
%                               a * img(end,:,:) + b * dx(end,:,:) = g
%                               a * img(:,end,:) + b * dy(:,end,:) = g
%                               a * img(:,:,end) + b * dz(:,:,end) = g
% 
%               Same:       dx, dy, dz last points satisfy:
%                              	dx(end,:,:) = dx(end-1,:,:);
%                              	dy(:,end,:) = dy(:,end-1,:);
%                              	dz(:,:,end) = dz(:,:,end-1);
% 
% OUTPUT ARGUMENTS
%	[dx,dy,dz]: -[MxNxP] derivative image arrays in x, y, z directions
%   [dg]:       -[3x1xMxNxP] 5D gradient vector array with:
%                   squeeze(dg(1,1,:,:,:)) = dx
%                   squeeze(dg(2,1,:,:,:)) = dy
%                   squeeze(dg(3,1,:,:,:)) = dz


if nargin < 2
    vSize	=   [];
elseif ~isempty(vSize) && isscalar( vSize )
    vSize	=   [ vSize, vSize, vSize ];
end

if nargin < 3 || isempty(type)
    type	=   'same';
end

dx = circshift(img, [-1, 0, 0]);
dx = dx - img;

dy = circshift(img, [0, -1, 0]);
dy = dy - img;

dz = circshift(img, [0, 0, -1]);
dz = dz - img;

switch upper(type)
    case 'ROBIN'
        
        if length(varargin) ~= 3
            error('Robin BC requires 3 arguments: a, b, and g');
        end
        
        [a,b,g]	=   parse_robin(varargin{:});
        
        dx(end,:,:) = ( g(1) - a(1) * img(end,:,:) ) / b(1);
        dy(:,end,:) = ( g(2) - a(2) * img(:,end,:) ) / b(2);
        dz(:,:,end) = ( g(3) - a(3) * img(:,:,end) ) / b(3);
        
    case 'SAME'
        
        dx(end,:,:) = dx(end-1,:,:);
        dy(:,end,:) = dy(:,end-1,:);
        dz(:,:,end) = dz(:,:,end-1);
        
    otherwise
        
        % Default is Neumann
        dx(end,:,:) = 0;
        dy(:,end,:) = 0;
        dz(:,:,end) = 0;
        
end

if ~isempty( vSize )
    dx = dx ./ vSize(1);
    dy = dy ./ vSize(2);
    dz = dz ./ vSize(3);
end

if nargout == 1
    varargout{1}        =   permute( cat(4,dx,dy,dz), [4,5,1,2,3] );
    clear dx dy dz
else
    [varargout{1:3}]	=   deal(dx,dy,dz);
end

end

function [a,b,g] = parse_robin(a,b,g)

if any( b==0 )
    error('Robin BC undefined for b = 0');
end

a	=   parse_robin_input(a);
b	=   parse_robin_input(b);
g	=   parse_robin_input(g);

end

function x = parse_robin_input(x)

if ~ismember( numel(x), [1,3] )
    error( 'Robin inputs must all be scalar or have length 3' );
end

if isscalar( x )
    x	=   repmat(x,[3,1]);
else
    x	=	x(:);
end

end












