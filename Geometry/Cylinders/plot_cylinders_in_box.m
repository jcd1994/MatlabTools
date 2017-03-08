function h = plot_cylinders_in_box( p, v, r, BoxDims, BoxCenter, titlestr )
%PLOT_CYLINDERS_IN_BOX Plots the cylinderes defined by the [3xN] set of
%points and directinos p and v and [1xN] radii r in the box defined by the
%[3x1] vectors BoxDims and BoxCenter.

if nargin < 6; titlestr = ''; end;

h	=	figure; hold on
fig	=	get(gcf,'Number');

BoxBounds	=   [   BoxCenter(:)' - 0.5*BoxDims(:)'
                    BoxCenter(:)' + 0.5*BoxDims(:)' ];
rectpatchPlot( BoxBounds, fig );

for ii = 1:size(p,2)
    cylinderPlot( p(:,ii), v(:,ii), r(ii), 2*norm(BoxDims), fig );
end

axis image
axis( BoxBounds(:)' )

xlabel('x'); ylabel('y'); zlabel('z');
if ~isempty( titlestr ); title( titlestr ); end;

drawnow

end