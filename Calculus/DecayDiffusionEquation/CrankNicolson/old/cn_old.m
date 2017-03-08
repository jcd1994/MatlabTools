function [ x ] = cn_old( A, x0, T, dtmax )
%CN_OLD Solves the system of ode's given by dx/dt = A*x for x(T) using the 
% Crank-Nicolson method:
% 
%   x(t+dt)	~	x(t) + (dt/2)*(A*x(t+dt) + A*x(t))
%	x(0)    =	x0
%   
%	=>	x(t+dt)	=	((2/dt)*I - A)^-1 * ((2/dt)*I + A) * x(t)

%==========================================================================
% Parse Inputs
%==========================================================================
if isequal( T, 0 )
    x	=   x0;
    return
end
T       =   T(:).';
T0flag	=   false;
if T(1) == 0,	T0flag	=   true;
else            T       =   [ 0, T ];
end

%==========================================================================
% Evaluate x via the Crank-Nicholson Method
%==========================================================================
if nargin < 4
    x	=   cn_iter( A, x0, T );
else
    x	=	cn_dtmax( A, x0, T, dtmax );
end

if ~T0flag
    x	=   x(:,n+1:end);
end

end

function x = cn_dtmax( A, x0, T, dtmax )

[m,n]       =   size(x0);
x           =	zeros( m, n*length(T) );
x(:,1:n)	=	x0;

for ii = 2:length(T)
    
    jlast	=   (ii-2)*n+1:(ii-1)*n;
    jnext	=   (ii-1)*n+1:ii*n;
    
    N       =   ceil((T(ii)-T(ii-1))/dtmax);
    dt      =   (T(ii)-T(ii-1))/N;
    
    AL      =	(2/dt)*speye(m,m) - A;
    AR      =	(2/dt)*speye(m,m) + A;
    xnext	=   AR*x(:,jlast);
    xnext	=   AL\xnext;
    
    for jj = 2:N
        xnext	=   AR*xnext;
        xnext	=   AL\xnext;
    end
    
    x(:,jnext)	=   xnext;
    
end

end

function x = cn_iter( A, x0, T )

maxiter	=   10;
tol     =   1e-3;

dtmax	=   min(diff(T))/2;
xlast	=	cn_dtmax( A, x0, T, dtmax );

dtmax	=   dtmax/5;
x       =	cn_dtmax( A, x0, T, dtmax );

iter	=   2;
while max(abs(x(:)-xlast(:))) > tol && iter < maxiter
    iter	=   iter + 1;
    xlast	=   x;
    dtmax	=   dtmax/5;
    x       =	cn_dtmax( A, x0, T, dtmax );
end

end
