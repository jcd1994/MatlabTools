function [ psi, theta, phi ] = rot2QuadYawpitchroll( R )
%YAWPITCHROLL2ROT gets the yaw, pitch, and roll angles from the input
% rotation matrix. the angled are defined by:
%   -yaw rotation is performed first about the z-axis
%   -pitch is performed second, about the new x' axis
%   -roll is performed last, about the new y'' axis.
% 
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
% 
% R = ... 
%     [ cos(phi)*cos(psi) - sin(phi)*sin(psi)*sin(theta), -cos(theta)*sin(psi), cos(psi)*sin(phi) + cos(phi)*sin(psi)*sin(theta)
%       cos(phi)*sin(psi) + cos(psi)*sin(phi)*sin(theta),  cos(psi)*cos(theta), sin(phi)*sin(psi) - cos(phi)*cos(psi)*sin(theta)
%                                   -cos(theta)*sin(phi),           sin(theta),                              cos(phi)*cos(theta) ];

phi   = atan2( -R(3,1), R(3,3) );
theta = atan2(  R(3,2), sqrt( R(3,1)^2 + R(3,3)^2 ) );
psi   = atan2( -R(1,2), R(2,2) );

end
