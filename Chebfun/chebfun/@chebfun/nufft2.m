function f = nufft2( c, x, y, tol)
% CHEBFUN.NUFFT2   Two-dimensional nonuniform fast Fourier transform
%
% F = CHEBFUN.NUFFT2( C ) is the same as fft2( C ).
%
% F = CHEBFUN.NUFFT2( C, X, Y ) is a 2D nonuniform fast Fourier transform 
% (of type 2), which computes the following sums in quasi-optimal 
% complexity:
%
%  F_{st} = \sum_{j=0}^{m-1}\sum_{k=0}^{n-1} 
%           C(j,k)*exp(-2*pi*1i*X(s,t)*k/N)*exp(-2*pi*1i*Y(s,t)*j/N).
% 
% See also chebfun.nufft and chebfun.inufft. 

% Copyright 2017 by The University of Oxford and The Chebfun Developers.
% See http://www.chebfun.org/ for Chebfun information.

%%% DEVELOPER'S NOTE %%%
% The algorithm in this MATLAB script is based on the paper:
%
% [1] D. Ruiz--Antoln and A. Townsend, "A nonuniform fast Fourier transform
% based on low rank approximation", submitted, 2017.
%
% This paper related the NUFFT to a FFT by low rank approximation.

% Default tolerance. 
if ( nargin < 4 )
    tol = 100*eps; 
end
    
% Get size of sample vectors 
% (We use this to reshape the final vector at the end.) 
[M, N] = size( x ); 
if ( ~all( size(y) == [M, N] ) )
    error('CHEBFUN::NUFFT2::SampleArrays', ...
          'The dimensions of X and Y are not the same.');
end

% Size of Fourier coefficient matrix:
[m, n] = size( c );

% Make samples columns: 
x = x(:); 
y = y(:);

% Find nearest equispaced grid to the sample points (x,y):
xj = round(n*x)/n;
xt = mod(round(n*x),n)+1;
yj = round(m*y)/m; 
yt = mod(round(m*y),m)+1;

%%%%%%%%%%% FAST TRANSFORM %%%%%%%%%%%%%%%%

% Ay = exp(-2*pi*1i*m*(yy(:)-yj(:))*(0:m-1)/m);
% Find low rank approximation to Ay = U1*V1.': 
er = m*(y-yj);
gam = norm(er, inf); 
K1 = ceil(5*gam*exp(lambertw(log(10/tol)/gam/7)));
scl = exp(-1i*pi*er);
U1 = repmat(scl,1,K1).*(ChebP(K1-1,er/gam)*Bessel_cfs(K1, gam));
V1 = ChebP(K1-1, 2*(0:m-1)'/m - 1);

% Ax = exp(-2*pi*1i*n*(xx(:)-xj(:))*(0:n-1)/n);
% Find low rank approximation to Ay = U1*V1.': 
er = n*(x-xj);
gam = norm(er, inf); 
K2 = ceil(5*gam*exp(lambertw(log(10/tol)/gam/7)));
scl = exp(-1i*pi*er);
U2 = repmat(scl,1,K2).*(ChebP(K2-1,er/gam)*Bessel_cfs(K2, gam));
V2 = ChebP(K2-1, 2*(0:n-1)'/n - 1);

% See paper [1] for explanation on this code: 
f = zeros(M*N, 1);
for r = 1:K2 
    Ar = fft( bsxfun(@times,c.',V2(:,r)) ).';
    for s = 1:K1
        fj = fft( bsxfun(@times, Ar, V1(:,s))); 
        f = f + U1(:,s).*fj(yt(:)+m*(xt(:)-1)).*U2(:,r);
    end
end

% Reshape vector to match input vectors x and y: 
f = reshape( f, M, N); 
end

function cfs = Bessel_cfs(K, gam)
% The bivarate Chebyshev coefficients for the function f(x,y) = exp(-i*x.*y)
% on the domain [-gam, gam]x[0,2*pi] are given by Lemma A.2 of Townsend's
% DPhil thesis.
arg = -gam*pi/2;
[pp,qq] = meshgrid(0:K-1);
cfs = 4*(1i).^qq.*besselj((pp+qq)/2,arg).*besselj((qq-pp)/2, arg);
cfs(2:2:end,1:2:end) = 0;
cfs(1:2:end,2:2:end) = 0;
cfs(1,:) = cfs(1,:)/2;
cfs(:,1) = cfs(:,1)/2;
end

function T = ChebP( n, x )
% Evaluate Chebyshev polynomials of degree 0,...,n at points in x. Use the
% three-term recurrence relation:
N = size(x, 1);
T = zeros(N, n+1);
T(:,1) = 1;
T(:,2) = x;
twoX = 2*x;
for k = 2:n
    T(:,k+1) = twoX.*T(:,k) - T(:,k-1);
end
end