function [ ] = second_order_central_diff_yiwang( )
%SECOND_ORDER_CENTRAL_DIFF_YIWANG Summary of this function goes here
%   Detailed explanation goes here

hx = 0.5;
hy = 0.4;
hz = 0.3;
central_diff_testing( @testfun1, hx, hy, hz );
central_diff_testing( @testfun2, hx, hy, hz );


hx = 0.05;
hy = 0.04;
hz = 0.03;
central_diff_testing( @testfun1, hx, hy, hz );
central_diff_testing( @testfun2, hx, hy, hz );


end

function [rmse_good, rmse_bad] = central_diff_testing(func,hx,hy,hz)

% [X,Y,Z] = meshgrid( hx*(-10:10), hy*(-10:10), hz*(-10:10) );
[X,Y,Z] = meshgrid( -1:hx:1, -1:hy:1, -1:hz:1 );

% exact solution
[f,lapf_exact]	=	func(X,Y,Z);

% rmse
f_rmse          =   @(f1,f2) ...
    sqrt( mean( ( f1(:) - f2(:) ).^2 ) );

% get approx
lapf_approx_good	=   central_diff_good(func,X,Y,Z,hx,hy,hz);
lapf_approx_bad     =   central_diff_bad_yiwang(func,X,Y,Z,hx,hy,hz);

rmse_good	=	f_rmse( lapf_exact, lapf_approx_good );
rmse_bad	=	f_rmse( lapf_exact, lapf_approx_bad );

% compare
fprintf('\n------------------------------\n');
fprintf(  'Central Difference Testing\n' );
fprintf(  '------------------------------\n\n');

fprintf( 'Standard approximation:\n' );
fprintf( 'Error for %s with [hx,hy,hz] = [%0.4f,%0.4f,%0.4f]:\n', ...
    func2str(func), hx, hy, hz );
fprintf( '%0.6f rmse\n', rmse_good );

fprintf('\n');

fprintf( 'Yi wang''s kek approximation\n:' );
fprintf( 'Error for %s with [hx,hy,hz] = [%0.4f,%0.4f,%0.4f]:\n', ...
    func2str(func), hx, hy, hz );
fprintf( '%0.6f rmse\n', rmse_bad );

fprintf('\n\n');

end

function ddf = central_diff_good(f,X,Y,Z,hx,hy,hz)

ddf	=	...
    ( f(X+hx,Y,Z) - 2*f(X,Y,Z) + f(X-hx,Y,Z) )/hx^2 + ...
    ( f(X,Y+hy,Z) - 2*f(X,Y,Z) + f(X,Y-hy,Z) )/hy^2 + ...
    ( f(X,Y,Z+hz) - 2*f(X,Y,Z) + f(X,Y,Z-hz) )/hz^2;

end

function ddf = central_diff_bad_yiwang(f,X,Y,Z,hx,hy,hz)

ddf	=	...
    ( f(X+hx,Y,Z) - 2*f(X,Y,Z) + f(X-hx,Y,Z) )/(4*hx^2) + ...
    ( f(X,Y+hy,Z) - 2*f(X,Y,Z) + f(X,Y-hy,Z) )/(4*hy^2) + ...
    ( f(X,Y,Z+hz) - 2*f(X,Y,Z) + f(X,Y,Z-hz) )/(4*hz^2);

end

function [f,lapf] = testfun1(x,y,z)

% syms x y z real
% f = x^2+y^2+z^2;
% lapf = divergence(gradient(f),[x,y,z]);

f       =	x.^2 + y.^2 + z.^2;
lapf	=	6 * ones(size(x));

end

function [f,lapf] = testfun2(x,y,z)

% syms x y z real
% f = exp(-4*x^2)*cos(y*z^2)+10*x*y^3*z^5;
% lapf = divergence(gradient(f),[x,y,z]);

f       =	cos(y.*z.^2).*exp(x.^2.*-4.0)+x.*y.^3.*z.^5.*1.0e1;
lapf	=	cos(y.*z.^2).*exp(x.^2.*-4.0).*-8.0+x.*y.*z.^5.*6.0e1+x.*y.^3.*z.^3.*2.0e2-y.*sin(y.*z.^2).*exp(x.^2.*-4.0).*2.0+x.^2.*cos(y.*z.^2).*exp(x.^2.*-4.0).*6.4e1-z.^4.*cos(y.*z.^2).*exp(x.^2.*-4.0)-y.^2.*z.^2.*cos(y.*z.^2).*exp(x.^2.*-4.0).*4.0;

end