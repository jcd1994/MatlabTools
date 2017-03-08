function [h,x,y,z]=cylinderPlot( q,v,r,height,fig )
%	-   plots the right-circular cylinder defined by central-axis direction 'v',
%       a point on the central axis 'q', the radius 'r', and the height 'height'.
% 
%   -   figure is plotted on figure 'fig'
% 
%   -   note:   notation is consistent with [q,v,r]=lscylinder(...)
%               from lscylinder.m

if nargin < 5 || isempty(fig), figure(gcf); else figure(fig); end
hold on, axis image

[hh,xx,yy,zz]=Cylinder(q-height/2*v,q+height/2*v,r,20,'b',0,1,.2);

view([0.5852    0.7752    0.2380]);
% length=50; baseangle=60; tipangle=30; width=20;
% properties={length,baseangle,tipangle,width};
% arrow(q-height/2*v,q+height/2*v,properties{:},'FaceColor','c');
hold off;

if nargout>0; h=hh; x=xx; y=yy; z=zz; end;

end

