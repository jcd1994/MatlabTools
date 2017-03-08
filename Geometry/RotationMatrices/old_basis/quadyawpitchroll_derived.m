% yaw, pitch, roll geometry for quad. based on chrobitics description at
%   http://www.chrobotics.com/library/understanding-euler-angles
% but with x-y-z oriented with z upwards, x east, and y north

syms theta phi psi da db dg real 

Rx = @(t) ...
    [ 1,      0,      0
      0, cos(t), -sin(t)
      0, sin(t),  cos(t) ];

Ry = @(t) ...
    [  cos(t), 0, sin(t)
            0, 1,      0
      -sin(t), 0, cos(t) ];

Rz = @(t) ... 
    [ cos(t), -sin(t), 0
      sin(t),  cos(t), 0
           0,       0, 1 ];           

%% Standard aerospace yaw/pitch/roll about z/y'/x''
%   -z faces towards the Earth, y faces east, and x faces north
% R_v1_I  = Rz(-psi);
% R_v2_v1 = Ry(-theta);
% R_B_v2  = Rx(-phi);
% 
% R_v2_I  = R_v2_v1 * R_v1_I;
% R_B_v1  = R_B_v2  * R_v2_v1;
% R_B_I   = R_B_v2  * R_v2_I;
% 
% R = R_B_I;
% 
% %not entirely sure why (if?) this works
% D = simplify(inv([eye(3)*[1;0;0], R_B_v2*[0;1;0], R_B_v1*[0;0;1]]));

%% Quadcopter yaw/pitch/roll about z/x'/y''
%   -z faces upwards, x faces east, and y faces north
R = Rz(psi) * Rx(theta) * Ry(phi);

%% Get small angle approximation
syms x y z th dth dphi dpsi 
fR = matlabFunction(R); % argument order: @(phi,psi,theta)
Ru =  [    1,   -z*th,    y*th;
        z*th,       1,   -x*th;
       -y*th,    x*th,       1   ];

% manually simplify dR taylor series, defined as below
%   dR = expand( fR(phi+dphi, psi+dpsi, theta+dth) - fR(phi,psi,theta) * Ru );
% by setting:
%   -cos(d_angle) -> 1
%   -sin(d_angle) -> d_angle
%   -products of 2 or more d_angle's -> 0
% 
% dR = expand( ...
%     [ sin(phi)*sin(psi)*sin(theta) - cos(phi)*cos(psi) + th*y*cos(psi)*sin(phi) + th*z*cos(theta)*sin(psi) + 1*1*cos(phi)*cos(psi) - 1*cos(phi)*dpsi*sin(psi) - 1*cos(psi)*dphi*sin(phi) + 0*sin(phi)*sin(psi) + th*y*cos(phi)*sin(psi)*sin(theta) - 1*1*1*sin(phi)*sin(psi)*sin(theta) - 1*1*cos(theta)*dth*sin(phi)*sin(psi) - 1*1*cos(psi)*dpsi*sin(phi)*sin(theta) - 1*cos(psi)*cos(theta)*0*sin(phi) - 1*1*cos(phi)*dphi*sin(psi)*sin(theta) - 1*cos(phi)*cos(theta)*0*sin(psi) - 1*cos(phi)*cos(psi)*0*sin(theta) - cos(phi)*cos(psi)*cos(theta)*0*dth, cos(theta)*sin(psi) - th*x*cos(psi)*sin(phi) - 1*1*cos(theta)*sin(psi) - 1*cos(psi)*cos(theta)*dpsi + 1*dth*sin(psi)*sin(theta) + cos(psi)*0*sin(theta) + th*z*cos(phi)*cos(psi) - th*x*cos(phi)*sin(psi)*sin(theta) - th*z*sin(phi)*sin(psi)*sin(theta), 1*1*cos(psi)*sin(phi) - cos(phi)*sin(psi)*sin(theta) - th*x*cos(theta)*sin(psi) - cos(psi)*sin(phi) + 1*cos(phi)*cos(psi)*dphi - 1*dpsi*sin(phi)*sin(psi) - cos(phi)*0*sin(psi) - th*y*cos(phi)*cos(psi) + th*y*sin(phi)*sin(psi)*sin(theta) + 1*1*1*cos(phi)*sin(psi)*sin(theta) + 1*1*cos(phi)*cos(theta)*dth*sin(psi) + 1*1*cos(phi)*cos(psi)*dpsi*sin(theta) + 1*cos(phi)*cos(psi)*cos(theta)*0 - 1*1*dphi*sin(phi)*sin(psi)*sin(theta) - 1*cos(theta)*0*sin(phi)*sin(psi) - 1*cos(psi)*0*sin(phi)*sin(theta) - cos(psi)*cos(theta)*0*dth*sin(phi)
%       th*y*sin(phi)*sin(psi) - cos(psi)*sin(phi)*sin(theta) - cos(phi)*sin(psi) + 1*1*cos(phi)*sin(psi) + 1*cos(phi)*cos(psi)*dpsi - 1*dphi*sin(phi)*sin(psi) - cos(psi)*0*sin(phi) - th*z*cos(psi)*cos(theta) - th*y*cos(phi)*cos(psi)*sin(theta) + 1*1*1*cos(psi)*sin(phi)*sin(theta) + 1*1*cos(psi)*cos(theta)*dth*sin(phi) + 1*1*cos(phi)*cos(psi)*dphi*sin(theta) + 1*cos(phi)*cos(psi)*cos(theta)*0 - 1*1*dpsi*sin(phi)*sin(psi)*sin(theta) - 1*cos(theta)*0*sin(phi)*sin(psi) - 1*cos(phi)*0*sin(psi)*sin(theta) - cos(phi)*cos(theta)*0*dth*sin(psi), th*z*cos(phi)*sin(psi) - cos(psi)*cos(theta) - th*x*sin(phi)*sin(psi) + 1*1*cos(psi)*cos(theta) - 1*cos(psi)*dth*sin(theta) - 1*cos(theta)*dpsi*sin(psi) + 0*sin(psi)*sin(theta) + th*x*cos(phi)*cos(psi)*sin(theta) + th*z*cos(psi)*sin(phi)*sin(theta), cos(phi)*cos(psi)*sin(theta) - sin(phi)*sin(psi) - th*y*cos(phi)*sin(psi) + 1*1*sin(phi)*sin(psi) + 1*cos(psi)*dpsi*sin(phi) + 1*cos(phi)*dphi*sin(psi) + cos(phi)*cos(psi)*0 + th*x*cos(psi)*cos(theta) - th*y*cos(psi)*sin(phi)*sin(theta) - 1*1*1*cos(phi)*cos(psi)*sin(theta) - 1*1*cos(phi)*cos(psi)*cos(theta)*dth + 1*1*cos(phi)*dpsi*sin(psi)*sin(theta) + 1*cos(phi)*cos(theta)*0*sin(psi) + 1*1*cos(psi)*dphi*sin(phi)*sin(theta) + 1*cos(psi)*cos(theta)*0*sin(phi) - 1*0*sin(phi)*sin(psi)*sin(theta) - cos(theta)*0*dth*sin(phi)*sin(psi)
%                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           cos(theta)*sin(phi) - th*z*sin(theta) - 1*1*cos(theta)*sin(phi) - 1*cos(phi)*cos(theta)*dphi + 1*dth*sin(phi)*sin(theta) + cos(phi)*0*sin(theta) + th*y*cos(phi)*cos(theta),                                                                                                                                                                                                      1*sin(theta) - sin(theta) + cos(theta)*dth - th*z*cos(theta)*sin(phi) - th*x*cos(phi)*cos(theta),                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     th*x*sin(theta) - cos(phi)*cos(theta) + th*y*cos(theta)*sin(phi) + 1*1*cos(phi)*cos(theta) - 1*cos(phi)*dth*sin(theta) - 1*cos(theta)*dphi*sin(phi) + 0*sin(phi)*sin(theta) ] ...
% 	);
dR = [ th*y*cos(psi)*sin(phi) - dpsi*cos(phi)*sin(psi) - dphi*cos(psi)*sin(phi) + th*z*cos(theta)*sin(psi) - dphi*cos(phi)*sin(psi)*sin(theta) - dpsi*cos(psi)*sin(phi)*sin(theta) - dth*cos(theta)*sin(phi)*sin(psi) + th*y*cos(phi)*sin(psi)*sin(theta), dth*sin(psi)*sin(theta) - dpsi*cos(psi)*cos(theta) - th*x*cos(psi)*sin(phi) + th*z*cos(phi)*cos(psi) - th*x*cos(phi)*sin(psi)*sin(theta) - th*z*sin(phi)*sin(psi)*sin(theta), dphi*cos(phi)*cos(psi) - dpsi*sin(phi)*sin(psi) - th*x*cos(theta)*sin(psi) + dpsi*cos(phi)*cos(psi)*sin(theta) + dth*cos(phi)*cos(theta)*sin(psi) - dphi*sin(phi)*sin(psi)*sin(theta) - th*y*cos(phi)*cos(psi) + th*y*sin(phi)*sin(psi)*sin(theta)
       dpsi*cos(phi)*cos(psi) - dphi*sin(phi)*sin(psi) + th*y*sin(phi)*sin(psi) + dphi*cos(phi)*cos(psi)*sin(theta) + dth*cos(psi)*cos(theta)*sin(phi) - dpsi*sin(phi)*sin(psi)*sin(theta) - th*z*cos(psi)*cos(theta) - th*y*cos(phi)*cos(psi)*sin(theta), th*z*cos(phi)*sin(psi) - dth*cos(psi)*sin(theta) - dpsi*cos(theta)*sin(psi) - th*x*sin(phi)*sin(psi) + th*x*cos(phi)*cos(psi)*sin(theta) + th*z*cos(psi)*sin(phi)*sin(theta), dphi*cos(phi)*sin(psi) + dpsi*cos(psi)*sin(phi) - th*y*cos(phi)*sin(psi) - dth*cos(phi)*cos(psi)*cos(theta) + dphi*cos(psi)*sin(phi)*sin(theta) + dpsi*cos(phi)*sin(psi)*sin(theta) + th*x*cos(psi)*cos(theta) - th*y*cos(psi)*sin(phi)*sin(theta)
                                                                                                                                                          dth*sin(phi)*sin(theta) - dphi*cos(phi)*cos(theta) - th*z*sin(theta) + th*y*cos(phi)*cos(theta),                                                                                                         dth*cos(theta) - th*z*cos(theta)*sin(phi) - th*x*cos(phi)*cos(theta),                                                                                                                                                    th*x*sin(theta) - dphi*cos(theta)*sin(phi) - dth*cos(phi)*sin(theta) + th*y*cos(theta)*sin(phi) ];

% get d_angle approximations
sol = solve([dR(2,1);dR(3,2);dR(1,3)],dphi,dpsi,dth);
sol.dpsi = simplify(sol.dpsi); fprintf('dpsi: '); disp(sol.dpsi);
sol.dth  = simplify(sol.dth);  fprintf('dth:  '); disp(sol.dth);
sol.dphi = simplify(sol.dphi); fprintf('dphi: '); disp(sol.dphi);

% check solution works
fdR = matlabFunction(dR);
fprintf('Difference matrix (should be zeros):\n');
disp( simplify(fdR(sol.dphi,sol.dpsi,sol.dth,phi,psi,th,theta,x,y,z)) );


