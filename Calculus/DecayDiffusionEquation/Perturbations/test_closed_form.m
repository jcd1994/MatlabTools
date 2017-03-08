function [ ] = test_closed_form( )
%TEST_CLOSED_FORM

xb = [0,3000];
x0 = linspacePeriodic(xb(1),xb(2),10);

% D  = 3037;
D  = 300;
f  = @(x) -complex(R2(x,x0),dW(x,x0));

X  = @(N) linspacePeriodic(xb(1),xb(2),N).';
U0 = @(N) 1i * ones(N,1);

%--------------------------------------------------------------------------
% Gradient Echo
%--------------------------------------------------------------------------
% T  = (10:10:60).'/1000;
T  = linspaceVec(0,60e-3,200,[1,0],false);

N  = 5000;
u1 = [U0(N),parabolicPeriodic1D(D,0,f,U0(N),xb,N,T)];
% figure, grid on, hold on;
% plot(X(N),abs(u1(:,1:5:end))), title('Exact Solution: Gradient Echo');

N  = 512;
% u2 = [U0(N),simple_convolution(D,0,f,U0(N),xb,N,T)];
u2 = [U0(N),perturbation(D,0,f,U0(N),xb,N,T,1)];
u3 = [U0(N),perturbation(D,0,f,U0(N),xb,N,T,2)];
% figure, grid on, hold on;
% plot(X(N),abs(u2(:,1:5:end))), title('Approximate Solution: Gradient Echo');

S1 = mean(u1,1).';
S2 = mean(u2,1).';
S3 = mean(u3,1).';

figure, grid on, hold on;
h = plot([0;T],abs([S1,S2,S3]),'-','linewidth',3);
title('Signal vs. Time: Gradient Echo');
legend(h,'Exact','First Term','Second Term');

figure, grid on, hold on;
err = @(S) log10(abs(S-S1));
h = plot([0;T],[err(S2),err(S3)],'-','linewidth',3);
title('Error vs. Time: Gradient Echo');
legend(h,'First Term','Second Term');

%--------------------------------------------------------------------------
% Spin Echo
%--------------------------------------------------------------------------
% dt = 2;
% T  = (dt:dt:60).'/1000;
% T2 = (dt:dt:30).'/1000;
% 
% N  = 5000;
% u1 = [U0(N),parabolicPeriodic1D(D,0,f,U0(N),xb,N,T2)];
% u1 = [u1,parabolicPeriodic1D(D,0,f,conj(u1(:,end)),xb,N,T2)];
% figure, grid on, hold on;
% % plot(X(N),abs(u1(:,1:5:end))), title('Exact Solution: Spin Echo');
% plot(X(N),abs(u1(:,end))), title('Exact Solution: Spin Echo');
% 
% N  = 512;
% u2 = [U0(N),simple_convolution(D,0,f,U0(N),xb,N,T2)];
% u2 = [u2,simple_convolution(D,0,f,conj(u2(:,end)),xb,N,T2)];
% % figure, grid on, hold on;
% % plot(X(N),abs(u2(:,1:5:end))), title('Approximate Solution: Spin Echo');
% plot(X(N),abs(u2(:,end))), title('Approximate Solution: Spin Echo');
% 
% S1 = mean(u1,1).';
% S2 = mean(u2,1).';
% 
% figure, grid on, hold on;
% plot([0;T],abs([S1,S2]),'o--'), title('Signal vs. Time: Spin Echo');

end

function u = perturbation(D,~,f,u0,xb,N,T,order)
if nargin < 8, order = 1; end;
lap    = @(x,h) (1/h^2) * ( -2*x + circshift(x,-1,1) + circshift(x,1,1) );
gradsq = @(x,h) (0.5/h) * ( circshift(x,-1,1) - circshift(x,1,1) );
M   = length(T);
t   = repmat(T(:).',[N,1]);
%dx = diff(xb)/N;
h   = 2/N;
e   = D/(diff(xb)/2)^2;

x   = linspacePeriodic(xb(1),xb(2),N).';
G   = repmat(-f(x(:)),[1,M]);
E   = exp(-G.*t);

M0  = 1i*E;
M1  = (1i/6).*E.*( 2*gradsq(G,h).*t.^3 - 3*lap(G,h).*t.^2 );

switch order
    case 1
        u   = M0;
    case 2
        u   = M0 + e*M1;
    otherwise
        error('only 1 or 2 terms');
end
end

function u = simple_convolution(D,~,f,u0,xb,N,T)
dt  = mean(diff(T));
vox = diff(xb)/(N-1);

sig = sqrt(2*D*dt);
min_width   =   8; % min width of gaussian (in standard deviations)
width       =	ceil( min_width / (vox/sig) );
unitsum     =   @(x) x/sum(x(:));
Gaussian1   =	unitsum( exp( -0.5 * ( (-width:width).' * (vox/sig) ).^2 ) );
[N1,N2]     =   deal(ceil((N-length(Gaussian1))/2),floor((N-length(Gaussian1))/2));
Kernel      =	[zeros(N1,1); Gaussian1; zeros(N2,1)];
Kernel      =	fft( ifftshift( Kernel ) );

x   = linspace(xb(1),xb(2),N).';
Exp = exp(dt*f(x));

u      = zeros(N,numel(T)+1);
u(:,1) = u0(:);
for ii = 2:size(u,2)
    u(:,ii) = ifftn(fftn(Exp.*u(:,ii-1)).*Kernel);
end
u      = u(:,2:end);
end

function r2 = R2(x,x0)
% r2 = (31.1-14.5)*reshape(any(abs(bsxfun(@minus,x(:),x0(:).'))<13.7,2),size(x))+14.5;
r2 = (63.5-14.5)*reshape(any(abs(bsxfun(@minus,x(:),x0(:).'))<13.7,2),size(x))+14.5;
end

function dw = dW(x,x0)
y  = bsxfun(@minus,x(:),x0(:).');
b  = abs(y)<13.7;
y  = 270 * sign(y).*(13.7./y).^2;
y(b) = 0;
dw = reshape(sum(y,2),size(x));
end
