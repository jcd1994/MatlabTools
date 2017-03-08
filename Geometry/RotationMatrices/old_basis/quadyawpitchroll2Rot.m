function R = quadyawpitchroll2Rot( psi, theta, phi )
%YAWPITCHROLL2ROT yaw, pitch, and roll angles to the corresponding rotation
%matrix. yaw rotation is performed first about the z-axis, then pitch about
%the new x' axis, and finally roll about the new y'' axis.

% Rx = ...
%     [ 1,          0,           0
%       0, cos(theta), -sin(theta)
%       0, sin(theta),  cos(theta) ];
% 
% Ry = ...
%     [  cos(phi), 0, sin(phi)
%               0, 1,        0
%       -sin(phi), 0, cos(phi) ];
% 
% Rz = ...
%     [ cos(psi), -sin(psi), 0
%       sin(psi),  cos(psi), 0
%              0,         0, 1 ];     
%   
% R = Rz*Rx*Ry;

R = ... 
    [ cos(phi)*cos(psi) - sin(phi)*sin(psi)*sin(theta), -cos(theta)*sin(psi), cos(psi)*sin(phi) + cos(phi)*sin(psi)*sin(theta)
      cos(phi)*sin(psi) + cos(psi)*sin(phi)*sin(theta),  cos(psi)*cos(theta), sin(phi)*sin(psi) - cos(phi)*cos(psi)*sin(theta)
                                  -cos(theta)*sin(phi),           sin(theta),                              cos(phi)*cos(theta) ];
 
end
