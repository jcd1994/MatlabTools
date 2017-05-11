chebfun3eps 1e-8
cheb.xyz

dx = 1;
B0 = 1;
gamma = 1;
a  = 0.25;
alpha = pi/4;

[X,Y,Z] = meshgrid(linspace(-1,1,128));
f = (X.^2 + Y.^2 <= a^2);
g = gauss_kernel(2,128*[1,1,1],[1,1,1]);
f = fftconvn(f,g);
F = chebfun3(f,'equi');

ir2 = chebfun3(@(x,y,z) ir2(x,y,z,a));
phi = chebfun3(@(x,y,z) atan2(y,x));

R2 = (30 - 15)*F + 15;
dw_in = gamma * B0 * dx/6 * (3*cos(alpha)^2-1);
dw_out = gamma * B0 * dx/2 * (sin(alpha)^2 .* ir2 .* cos(2*phi));