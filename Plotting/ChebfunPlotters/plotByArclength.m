function [ h ] = plotByArclength( f, npts, scale, varargin )
%PLOTBYARCLENGTH Plots the function f by the arclength.

if nargin < 3 || isempty(scale); scale = [f.hscale,f.vscale];
elseif isscalar(scale); scale = [f.hscale,scale];
end
if nargin < 2; npts = 20; end

S   = cumsum( sqrt( (1/scale(1))^2 + diff(f/scale(2)).^2 ) );
t   = inv(S);

dom = f.domain;
x   = t(linspace(0,S(dom(2)),npts));

h   = plot(x,f(x),varargin{:});

end

