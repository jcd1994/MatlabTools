function [ ] = anisotropicDiffusionAlgebra( )
%ANISOTROPICDIFFUSIONALGEBRA Verifies the solution to the anisotropic
%diffusion equation:
% 
%   du/dt = div( D * grad( u ) )
% 
% Where the solution is given by:
% 
%   u(x,t) = exp(-x'*D^-1*x/(4*t)) / sqrt( (4*pi*t)^n * |D| )
% 
% Where n is the number of dimensions

%% Initialize variables
D2 = sym('D',[2,2],'real');
D3 = sym('D',[3,3],'real');
D2(2,1) = D2(1,2);
for ii = 1:3; for jj = ii+1:3; D3(jj,ii) = D3(ii,jj); end; end;

x = sym('x',[1,1],'real');
y = sym('y',[1,1],'real');
z = sym('z',[1,1],'real');
r2 = [x;y];
r3 = [x;y;z];
t = sym('t',[1,1],'positive');

%% relevant functions
grad2 = @(u) [diff(u,x); diff(u,y)];
grad3 = @(u) [diff(u,x); diff(u,y); diff(u,z)];
div2 = @(u) diff(u(1),x) + diff(u(2),y);
div3 = @(u) diff(u(1),x) + diff(u(2),y) + diff(u(3),z);

L2 = @(u) div2( D2 * grad2(u) );
L3 = @(u) div3( D3 * grad3(u) );

%% define functions
u2 = exp(-r2'*inv(D2)*r2/(4*t)) / sqrt( (4*pi*t)^2 * det(D2) );
u2 = simplify(expand(u2));

u3 = exp(-r3'*inv(D3)*r3/(4*t)) / sqrt( (4*pi*t)^3 * det(D3) );
u3 = simplify(expand(u3));

%% verify 2D
fprintf('\n');
try
    assert(isequal( simplify(expand( diff(u2,t) - L2(u2) )), 0 ));
    fprintf('Algebraic assertion passed - 2D\n');
catch me
    fprintf('Algebraic assertion failed - 2D\n');
end

%% verify 3D
try
    assert(isequal( simplify(expand( diff(u3,t) - L3(u3) )), 0 ));
    fprintf('Algebraic assertion passed - 3D\n');
catch me
    fprintf('Algebraic assertion failed - 3D\n');
end
fprintf('\n');

%% verify normalization

V2 = randRotMat([],[],2);
V3 = randRotMat;
L2 = diag(5*(0.5+rand(2,1)/2));
L3 = diag(5*(0.5+rand(3,1)/2));
D2 = V2 * L2 * V2';
D3 = V3 * L3 * V3';

fu2 = matlabFunction(u2);
fu3 = matlabFunction(u3);

fu2 = @(x,y,t)      fu2(D2(1,1),D2(1,2),D2(2,2),t,x,y);
fu3 = @(x,y,z,t)	fu3(D3(1,1),D3(1,2),D3(1,3),D3(2,2),D3(2,3),D3(3,3),t,x,y,z);

t = 10 * (0.5 + rand/2);
T = 10 * t;
tol = 1e-8;
I2 = integral2( @(x,y) fu2(x,y,t),-T,T,-T,T,'abstol',tol,'reltol',tol );
I3 = integral3( @(x,y,z) fu3(x,y,z,t),-T,T,-T,T,-T,T,'abstol',tol,'reltol',tol );

%% verify 2D
try
    assert( abs(I2 - 1) < 1e-6 );
    fprintf('Normalization assertion passed - 2D\nI2 = %0.12f\n',I2);
catch me
    fprintf('Normalization assertion failed - 2D\nI2 = %0.12f\n',I2);
end

%% verify 3D
try
    assert( abs(I3 - 1) < 1e-6 );
    fprintf('Normalization assertion passed - 3D\nI3 = %0.12f\n',I3);
catch me
    fprintf('Normalization assertion failed - 3D\nI3 = %0.12f\n',I3);
end
fprintf('\n');

end
