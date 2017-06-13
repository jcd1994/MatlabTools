function pass = test_battery( pref ) 
% A large battery of functions. 

if ( nargin < 1 ) 
    pref = chebfunpref; 
end 
tol = 1e8 * pref.cheb2Prefs.chebfun2eps;

Battery = {@(x,y) cos(pi*x.*y),...                                        % 1
    @(x,y) cos(2*pi*x.*y), ...                                            % 2
    @(x,y) cos(3*pi*x.*y),...                                             % 3
    @(x,y) cos(4*pi*x.*y),...                                             % 4
    @(x,y) cos(5*pi*x.*y),...                                             % 5
    @(x,y) cos(6*pi*x.*y),...                                             % 6
    @(x,y) cos(7*pi*x.*y),...                                             % 7
    @(x,y) sin(pi*x.*y),...                                               % 8
    @(x,y) sin(8*pi*x.*(1-x).*y.*(1-y)),...                               % 9
    @(x,y) sin(8*pi*x.*(1-x).*y.*(1-y).*(x-y).^2),...                     % 10
    @(x,y) cos(0*pi*(x-y).^2),...                                         % 11
    @(x,y) cos(pi*(x-y).^2),...                                           % 12
    @(x,y) cos(2*pi*(x-y).^2),...                                         % 13
    @(x,y) exp(sin(4*pi./(1+x)).*sin(4*pi./(1+y))),...                    % 14
    @(x,y) log(1+x.*y),...                                                % 15
    @(x,y) cos(pi*x.*sin(pi*y)) + cos(pi*y.*sin(pi*x)),...                % 16
    @(x,y) cos(2*pi*x.*sin(pi*y)) + cos(2*pi*y.*sin(pi*x)),...            % 17 
    @(x,y) (1-x.*y)./(1+x.^2+y.^2),...                                    % 18
    @(x,y) cos(pi*x.*y.^2).*cos(pi*y.*x.^2),...                           % 19
    @(x,y) cos(2*pi*x.*y.^2).*cos(2*pi*y.*x.^2),...                       % 20        
    @(x,y) cos(3*pi*x.*y.^2).*cos(3*pi*y.*x.^2),...                       % 21      
    @(x,y) (x-y)./(2-x.^2+y.^2)+(y-x)./(2-y.^2+x.^2),...                  % 22            
    @(x,y) exp(-y.*x.^2) + exp(-x.*y.^2), ...                             % 23
    @(x,y) exp((1-x.^2)./(1+y.^2)) + exp((1-y.^2)./(1+x.^2)),...          % 24                   
    @(x,y) 10.^(-x.*y),...                                                % 25
    @(x,y) 10.^(-10*x.*y),...                                             % 26
    @(x,y) sqrt(1e-15).^((x+y).^6),...                                    % 27        
    @(x,y) sin(x+y),...                                                   % 30
    @(x,y) exp(x+y).*cos(x+y), ...                                        % 31
    @(x,y) cos(pi/3+x+y),...                                              % 32
    @(x,y) cos(pi/3+5*x+5*y), ...                                         % 33
    @(x,y) (x+y).^4,...                                                   % 34
    @(x,y) (x+y).^8,...                                                   % 35
    @(x,y) (x+y).^12,...                                                  % 36
    @(x,y) exp(x.^2.*y.^2).*cos(x+y),...                                  % 37
    @(x,y) sin(x.*y),...                                                  % 38
    @(x,y) sin(x.*y)+x+y,...                                              % 39
    @(x,y) (1+x+y).^(-3),...                                              % 40
    @(x,y) (1+5*x+5*y).^(-3),...                                          % 41
    @(x,y) cos(pi*x.*sin(pi*y)) - cos(pi*y.*sin(pi*x)),...                % 42
    @(x,y) exp(-y.*x.^2) - exp(-x.*y.^2),...                              % 43
    @(x,y) exp((1-x.^2)./(1+y.^2)) - exp((1-y.^2)./(1+x.^2)),...          % 44
    @(x,y) cos(100*x)-cos(100*y),...                                      % 45
    @(x,y) x-y,...                                                        % 46
    @(x,y) -sin(x).*(sin(x.^2/pi).^2 - -sin(y).*sin(y.^2/pi).^2),...      % 47
    @(x,y) cos(3*pi*x.*y.^2).*cos(3*pi*y.*x.^2)+sin(x),...                % 48
    @(x,y) cos(10*x.*(y-1)),...                                           % 49
    @(x,y) (x-y).^2.*cos(x).*log(1+y),...                                 % 50
    @(x,y) cos(x+y+log(1+x.*y)),...                                       % 51
    @(x,y) cos(100*x),...                                                 % 52
    @(x,y) x.*(1-y+cos(10*x)),...                                         % 53
    @(x,y) -x.*sin(sqrt(abs(x)))-y.*sin(sqrt(abs(y))),...                 % 54
    @(x,y) (x.^2+y.^2)/4000 - cos(x).*cos(y/sqrt(2))+1,...                % 55
    @(x,y) exp(-(x-3).^2/pi-(y-5).^2/pi).*cos(pi*(x-3).^2+pi*(y-5).^2) + 2*exp(-(x-5).^2/pi-(y-2).^2/pi).*cos(pi*(x-5).^2+pi*(y-2).^2) + 5*exp(-(x-2).^2/pi-(y-1).^2/pi).*cos(pi*(x-2).^2+pi*(y-1).^2) + 2*exp(-(x-1).^2/pi-(y-4).^2/pi).*cos(pi*(x-1).^2+pi*(y-4).^2) + 3*exp(-(x-7).^2/pi-(y-9).^2/pi).*cos(pi*(x-7).^2+pi*(y-9).^2),...
    @(x,y) (4-2.1*(x/3).^2+(x/3).^4/3).*(x/3).^2 + (x/3).*(y/3) + (-4-4*(y/3).^2).*y.^2,...
    @(x,y) -(1+cos(12*sqrt((x./5).^2+(y/5).^2)))./(.5*((x/5).^2+(y/5).^2)+2),...
    @(x,y) cos(x.*(1+y)),...
    @(x,y) exp(-1000*((x-.5).^2+(y-.5).^2-.125).^2),...
    @(x,y) exp(1./(1+(((x+1)/2).*((y+1)/2)).^2)),...
    @(x,y) 2*exp(exp((x+1)/2)),...
    @(x,y) (1./(1+1e-3*(((x+1)/2-.3).^2+((y+1)/2-.3).^2))),...
    };

% Exact values for definite integrals computed in Mathematica
exact = [
    0.5894898722360821,...
    0.2257058333950713,...
    0.1776977458727282,...
    0.1187424174709143,...
    0.1040214328382758,...
    0.08053420291629177,...
    0.07348799958904405,...
    0.5246630675753145,...
    0.5735519176658511,...
    0.06955139313890799,...
    1,0.7479656668315220,...
    0.4882534060753284,...
    1.171460474510744,...
    0.2087613945440329,...
    0.857861895707081,...
    0.241651766729031165,...
    0.5086983159291771,...
    0.7231765864851378,...
    0.5891599692839595,...
    0.4769961059000557,...
    0.09422407514560267,...
    1.723055413592619,...
    3.492035304274583,...
    0.6269639737246870,...
    0.1612897266836097,...
    0.1727371891,...
    0.7736445427901117,...
    1.072069561535282,...
    -0.4216201034137229,...
    0.05571869648415638,...
    2.066666666666667,...
    11.35555555555556,...
    90.01098901098886,...
    0.5014624050192373,...
    0.2398117420005848,...
    1.239811742000715,...
    0.1666666666666678,...
    0.01515151515151557,...
    0,...
    0,...
    0,...
    0,...
    0,...
    -0.021260414733480,...
    0.9366938000318889,...
    0.1658347594218874,...
    0.05658954650254417,...
    0.30723021414730670,...
    -0.005063656411097588,...
    0.1772071736202985,...
    -0.7083943110937996,...
    0.2270859249178878,...
    0.230747707969006,...
    -1.251416160428506,...
    -0.3882055297584357,...
    0.6593299064355118,...
    0.1760859897887420,...
    2.146572044542719,...
    17.81651365967990,...
    0.9995535671520096,...
    ];

for jj=1:length(Battery)
    
    g = chebfun2(Battery{jj}, [0 1 0 1]);
    
    pass(jj) = (abs( sum2(g) - exact(jj) ) < tol);
    
end

end