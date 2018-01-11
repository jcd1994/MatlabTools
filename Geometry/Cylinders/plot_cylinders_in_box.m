function h = plot_cylinders_in_box( p, v, r, BoxDims, BoxCenter, titlestr, h, col, alpha )
%PLOT_CYLINDERS_IN_BOX Plots the cylinderes defined by the [3xN] set of
%points and directinos p and v and [1xN] radii r in the box defined by the
%[3x1] vectors BoxDims and BoxCenter.

if nargin < 9 || isempty(alpha);    alpha = 0.2; end;
if nargin < 8 || isempty(col);      col = 'b'; end;
if nargin < 7 || isempty(h);        h = figure; end
if nargin < 6 || isempty(titlestr); titlestr = ''; end;

hold on
fig	=	get(h,'Number');

BoxBounds	=   [   BoxCenter(:)' - 0.5*BoxDims(:)'
                    BoxCenter(:)' + 0.5*BoxDims(:)' ];
rectpatchPlot( BoxBounds, fig );

for ii = 1:size(p,2)
    cylinderPlot( p(:,ii), v(:,ii), r(ii), 2*norm(BoxDims), fig, col, alpha );
end

axis image
axis( (1+1e-4) * BoxBounds(:)' )

xlabel('x'); ylabel('y'); zlabel('z');
if ~isempty( titlestr ); title( titlestr ); end;

drawnow

end