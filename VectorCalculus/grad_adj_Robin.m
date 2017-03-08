function [varargout] = grad_adj_Robin(x, y, z, vSize, type, varargin)
%GRAD_ADJ_ROBIN Summary of this function goes here
%   Detailed explanation goes here

if nargin < 4
    vSize	=   [];
elseif ~isempty(vSize) && isscalar( vSize )
    vSize	=   [ vSize, vSize, vSize ];
end

if nargin < 5 || isempty(type)
    type	=   'same';
end

dx = circshift(x, [1, 0, 0]);
dy = circshift(y, [0, 1, 0]);
dz = circshift(z, [0, 0, 1]);

dx = dx - x;
dy = dy - y;
dz = dz - z;

switch upper(type)
    case 'ROBIN' % TODO
        error( 'Not implemented' )
        
    case 'SAME'
        
        dx(1,:,:)   =  dx(2,:,:); clear x
        dy(:,1,:)   =  dy(:,2,:); clear y
        dz(:,:,1)   =  dz(:,:,2); clear z
        
    otherwise
        
        % Default is Dirichlet:
        %	u(0)-u(1) and u(end-1)-u(end), where u(0) = u(end) = 0
        dx(1,:,:)   = -x(1,:,:);
        dx(end,:,:) =  x(end-1,:,:); clear x
        
        dy(:,1,:)   = -y(:,1,:);
        dy(:,end,:) =  y(:,end-1,:); clear y
        
        dz(:,:,1)   = -z(:,:,1);
        dz(:,:,end) =  z(:,:,end-1); clear z
        
end

if isempty( vSize )
    varargout{1} = dx + dy + dz;
else
    varargout{1} = dx./vSize(1) + dy./vSize(2) + dz./vSize(3);
end

end


