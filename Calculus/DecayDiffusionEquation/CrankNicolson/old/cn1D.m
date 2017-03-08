function [ u ] = cn1D( a, b, c, u0, xb, I, T, N )
%CN1D CURRENTLY DOES NOT WORK. Solves the general 1D parabolic equation using the Crank-Nicolson
%method. The equation considered is:
% 
%   u_t = a(x)*u_xx + b(x)*u_x + c(x)*u

if nargin < 8; N = 10; end

k	=   T/N;
t	=	linspace(0,T,N+1);

x	=   linspace(xb(1),xb(2),I+1)';
h	=   diff(xb)/I;
ii	=   (1:I-1)+1;

ax	=   a(x(ii));
bx	=   b(x(ii));
cx	=   c(x(ii));

BC1	=   sparse(1,I+1);
BC1([1,end])	=   [1, -1]; %periodic value bc

BC2	=   sparse(1,I+1);
BC2([1,2,end-1,end])	=   [-1,1,1,-1]; % periodic derivative bc

u       =   zeros(I+1,N+1);
u(:,1)	=   u0(x);

%==========================================================================
% Construct matrix explicitly
%==========================================================================

A	=   -(2*k*ax + k*h*bx);
B	=   4*h^2 + 4*k*ax - 2*h^2*k*cx;
C	=   -(2*k*ax - k*h*bx);

M	=   sparse(I+1,I+1);
M	=   M + spdiags( [ [A(:); 0; 0], [0; B(:); 0], [0; 0; C(:)] ], ...
                     -1:1, I+1, I+1 );
M(1,:)	=   BC1;
M(end,:)=   BC2;

for jj = 2:N+1
    D       =   zeros(I+1,1);
    
    D(ii)	=   (2*k*ax+k*h*bx) .* u(ii+1,jj-1) + ...
                (4*h^2-4*k*ax+2*h^2*k*cx) .* u(ii,jj-1) + ...
                (2*k*ax-k*h*bx) .* u(ii-1,jj-1);
	u(:,jj)	=   M\D;
end

%==========================================================================
% Conjugate gradient method
%==========================================================================
% 
% Au	=   @(u) [	u(1)-u(end); ...
%                 u(2:end-1) - (k/2) * F_func(u,ax,bx,cx,h); ...
%                 (u(2)-u(1)) - (u(end)-u(end-1))	];
% for jj = 2:N+1
%     B       =   [ 0; u(ii,jj-1) + (k/2) * F_func(u(:,jj-1),ax,bx,cx,h); 0 ];
%     u(:,jj)	=   cg(Au,B,u(:,jj-1),1e-6,100,true);
% end

%==========================================================================
% pdepe method
%==========================================================================
% 
% u = pdepe(0,@pdex1pde,@pdex1ic,@pdex1bc,x,t)';
% 
% % --------------------------------------------------------------
% function [c,f,s] = pdex1pde(x,t,u,DuDx)
% c = 1;
% f = x^2*DuDx;
% s = -x*DuDx+x^2*u;
% end
% % --------------------------------------------------------------
% function u0 = pdex1ic(x)
% u0 = besselj(3,x);
% end
% % --------------------------------------------------------------
% function [pl,ql,pr,qr] = pdex1bc(xl,ul,xr,ur,t)
% pl = ul;
% ql = 0;
% pr = ur;
% qr = 0;
% end

%==========================================================================
% pbcpdeSolver method
%==========================================================================
% 
% ic=u0(x');
% 
% % Here is where we call the solver.
% u=pbcpdeSolver(@fpde,ic,x',t)';
% 
% %Here is where we define the diffusion and reaction parts.
% function [D,s]=fpde(x,t,u)
%    D=a(x);  % Diffusion coefficient
%    s=c(x).*u; % constant decay
% end

%==========================================================================
% odeXX method
%==========================================================================
% M = speye(I+1);
% M(1,:)	=   BC1;
% M(end,:)=	BC2;
% options	=	odeset('Mass',M,'MassSingular',false,'Jacobian',get_J);
% % [~,u]	=	ode15s(@dudt,t(:)',u0(x(:)),options);
% [~,u]	=	ode23s(@dudt,t(:)',u0(x(:)),options);
% % [~,u]	=	ode45(@dudt,t(:)',u0(x(:)),options);
% u       =   u';
% 
%     function dudt = dudt(t,u)
%         dudt	=   [	0
%                         ax .* ( u(ii+1) - 2*u(ii) + u(ii-1) )/h^2 + ...
%                         bx .* ( u(ii+1) - u(ii-1) )/h + ...
%                         cx .* u(ii)
%                         0	];
%     end
%     
%     function J = get_J
%         J	=   sparse(I+1,I+1);
%         J	=   J + spdiags( [[ax;0;0],[0;-2*ax;0],[0;0;ax]]/h^2, -1:1, I+1, I+1 ) + ...
%                     spdiags( [[bx;0;0],[0;0;bx]]/h, [-1,1], I+1, I+1 ) + ...
%                     spdiags( [0;cx;0], 0, I+1, I+1 );
%     end

%==========================================================================
% output
%==========================================================================
% u	=   u(:,end);

end

% function F = F_func(u,ax,bx,cx,h)
% % computes a(x)*u_xx + b(x)*u_x + c(x)*u for the inner points of u. F has
% % length = length(u)-2
% 
% ii	=	2:length(u)-1;
% F	=   ax .* ( u(ii+1) - 2*u(ii) + u(ii-1) )/h^2 + ...
%         bx .* ( u(ii+1) - u(ii-1) )/h + ...
%         cx .* u(ii);
% 
% end

function testing
% I = 10; % num. spatial points
% N = 3; % num. time points
% T = 0.06;
% t = linspace(0,T,N+1);

%==========================================================================
% bessel functions
%==========================================================================
% m	=	3;
% ue	=	@(x,t) exp(m^2*t) * besselj(m,x);
% u0	=	@(x) besselj(m,x);
% du0	=	@(x) -besselj(m+1.0,x)+(m.*besselj(m,x))./x;
% 
% if mod(m,2) == 0
%     z = fzero( du0, m*pi/2 + pi/4 );
%     z = fzero( du0, z + [-pi/8,pi/8] );
% else
%     z = fzero( u0, m*pi/2 + pi/2 );
%     z = fzero( u0, z + [-pi/8,pi/8] );
% end
% xb = [-z,z];
% 
% a = @(x) x.^2;
% b = @(x) x;
% c = @(x) x.^2;
% 
% x = linspace(xb(1),xb(2),I+1);

%==========================================================================
% u(x,t) = exp(-t) * (1+sin(m*x))
%==========================================================================
% m	=   3;
% u0	=	@(x) 1+sin(m*x);
% a	=   @(x) -ones(size(x));
% b	=   @(x) zeros(size(x));
% c	=   @(x) m^2 * a(x);
% ue	=   @(x,t) exp(a(x)*m^2*t) .* (1+sin(m*x));
% xb	=   [-pi,pi];
% x	=   linspace(xb(1),xb(2),I+1);

%==========================================================================
% u(x,t) = exp(t) * (x^3-x)
%==========================================================================
% ue	=   @(x,t) exp(t) .* (x.^3-x);
% u0	=	@(x) (x.^3-x);
% a	=   @(x) (1/12)*(x.^2-1);
% b	=   @(x) zeros(size(x));
% c	=   @(x) 0.5*ones(size(x));
% xb	=   [-1,1];
% x	=   linspace(xb(1),xb(2),I+1);

%==========================================================================
% solve and plot
%==========================================================================
% 
% u = cn1D( a, b, c, u0, xb, I, T, N );
% 
% % close all force
% figure, hold on
% for jj = unique([1,round( N*(1:5)/5 )])
%     plot( x, ue(x,t(jj)), 'r--', 'linewidth', 4 );
%     plot( x, u(:,jj), 'b-', 'linewidth', 2 );
% end

end