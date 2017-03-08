n = 1000;
[T,X,Y,Z,PHI,THETA,PSI,PHI0,THETA0,PSI0,PHI1,THETA1,PSI1] = deal(zeros(n,1));

for i = 1:n
%     phi = pi*(2*rand-1);
%     theta  = pi/2*(2*rand-1);
    phi = pi/4*(2*rand-1);
    theta  = pi/4*(2*rand-1);
    psi = pi*(2*rand-1);
    N = yawpitchroll2Rot(psi, theta, phi);
    
    % approx theta for omega = 10, freq = 125Hz
    t = (1/125)*10*(2*rand-1);
    u = 2*rand(3,1)-1; % rand
    u = u/norm(u); % rand
    
    % true rotation and small angle approx. rotation in body from
    Ru0 = axisAngle2Rot(u,t);
    Ru1 = axisAngle2Rot(u,t,true);
    
    % rotation is done in the body frame
    % Rz = axisAngle2Rot([0;0;1],psi);
    R0 = N * Ru0;
    R1 = N * Ru1;
    
    [psi0,theta0,phi0] = rot2Yawpitchroll(R0);
    [psi1,theta1,phi1] = rot2Yawpitchroll(R1);
    
    x = u(1); y = u(2); z = u(3);
    T(i) = t; X(i) = x; Y(i) = y; Z(i) = z;
    PHI(i)  = phi;  THETA(i)  = theta;  PSI(i)  = psi;
    PHI0(i) = phi0; THETA0(i) = theta0; PSI0(i) = psi0;
    PHI1(i) = phi1; THETA1(i) = theta1; PSI1(i) = psi1;
    if n == 1
%         D = [ 1, 0,               -tan(phi)
%               0, 1,     tan(theta)/cos(phi)
%               0, 0, 1/(cos(phi)*cos(theta)) ];
%         D = [            cos(phi), 0,           -sin(phi)
%               sin(phi)*tan(theta), 1, cos(phi)*tan(theta)
%               sin(phi)/cos(theta), 0, cos(phi)/cos(theta) ];
        
%         d_euler = D * [ t*x; t*y; t*z ];
%         d_phi   = t*x + (t*(z*cos(phi)*sin(theta) + y*sin(phi)*sin(theta)))/cos(theta);
%         d_theta = t*(y*cos(phi) - z*sin(phi));
%         d_psi   =(t*(z*cos(phi) + y*sin(phi)))/cos(theta);

        d_phi   = t*y - t*(z*cos(phi)*sin(theta) - x*sin(phi)*sin(theta))/cos(theta);
        d_theta = t*(x*cos(phi) + z*sin(phi));
        d_psi   = t*(z*cos(phi) - x*sin(phi))/cos(theta);
        
        disp([phi, theta, psi; phi0, theta0, psi0; phi1, theta1, psi1]);
        disp([phi+d_phi, theta+d_theta, psi+d_psi; phi0, theta0, psi0; phi1, theta1, psi1]);
%         disp([  phi + d_euler(1), theta + d_euler(2), psi + d_euler(3); ...
%                             phi0,             theta0,             psi0; ...
%                             phi1,             theta1,             psi1 ]);
    end
    PHI(i) = PHI(i) + d_phi;
    THETA(i)  = THETA(i) + d_theta;
    PSI(i) = PSI(i) + d_psi;
end

% clearvars -except T X Y Z PHI THETA PSI PHI0 THETA0 PSI0 PHI1 THETA1 PSI1

