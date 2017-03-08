function [ ] = TM_Equation_1D( )
%TM_EQUATION_1D Solves the 1D transverse magnetization equation:
%   M_t     =	k * M_xx - f(x) * M,    a < x < b,  t > 0
%   M(x,0)  =   h(x),                   a < x < b
%   M(a,t)	=   M(b,t),                 t > 0
%   M_x(a,t)=   M_x(b,t),               t > 0
% 
% The solution is given by:
%   M(x,t)	=   sum( T[n](t) * X[n](x) ),	n	= -inf:inf
% 
% Where (after mapping x -> 2*pi*(x-a)/(b-a) - pi):
%   X[n](x)	=   exp( i*n*x ) / sqrt(2*pi)
%   T[n](t)	=	sum( E[n,j](t) * T[j](0) ),         j	= -inf:inf
%   E(t)	=   exp( A*t )
%   A[m,n]  =   K[m,n] + B[m,n],                    i,j	= -inf:inf
%   K[m,n]  =  -k*m*n * delta[m,n],                 i,j	= -inf:inf
%   B[m,n]  =  -int( f(x)*exp(i*(n-m)*x)/(2*pi) )	i,j = -inf:inf



end

%% evaluate f(x)
function y = func(x)

R2	=   5;
dw	=   x.^3 .* sin( exp(1) * x );
y	=   R2 + 1i*dw;

end

%% calculate bL
function bL = get_bL( f, Lrange )

bL	=	zeros(size(Lrange));
for ii = 1:numel(Lrange)
    bL(ii)	=   integral( @(x) f(x) .* exp( 1i * L(ii) * x ), -pi, pi );
end
bL	=   bL / (2*pi);

end