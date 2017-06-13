function varargout = gallerydisk(name)
%CHEB.GALLERYDISK   Diskfun example functions.
%   F = CHEB.GALLERYDISK(NAME) returns a diskfun corresponding to NAME. 
%   See the listing below for available names.
%
%   For example,  plot(cheb.gallerydisk('yinyang')) plots Grady Wright's
%   yin-yang function.  For details of how each function is constructed,
%   try 'type +cheb/gallerydisk' or 'edit cheb.gallerydisk'.
%
%   [F,FA] = CHEB.GALLERYDISK(NAME) also returns the anonymous function FA 
%   used to define the function.  If the arguments are (t,r), the diskfun
%   should be constructed in 'polar' mode; if they are (x,y), it should be
%   constructed in 'cart' mode
%   Some gallery functions are generated by operations beyond the usual
%   Diskfun constructor (e.g. by solving PDEs), so FA in those cases 
%   is equal to F.
%
%   CHEB.GALLERYDISK with no input argument returns a function chosen at
%   random from the gallery.
%
%   CHEB.GALLERYDISK with no output argument creates a plot of the selected
%   function.
%
%   challenge  Zooms in on a portion of the function from SIAM 100-digit challenge
%   ellipsepeg An ellipse-shaped peg, rank 52
%   flower     A pretty function with 5-fold symmetry
%   roundpeg   Approx characteristic function of a disk, rank 1
%   squarepeg  Approx characteristic function of a square, rank 33
%   tiltedpeg  A tilted variant of squarepeg, rank 34
%   wave       A wavy function
%   yinyang    Yin-yang function
%   Gallery functions are subject to change in future releases of Chebfun.
%
% See also CHEB.GALLERY, CHEB.GALLERYTRIG, CHEB.GALLERY2, CHEB.GALLERY3, CHEB.GALLERYSPHERE

% Copyright 2017 by The University of Oxford and The Chebfun Developers.
% See http://www.chebfun.org/ for Chebfun information.


% If the user did not supply an input, return a function chosen at random
% from the gallery.
if ( nargin == 0 )
    names = {'challenge','flower','poisson', 'ellipsepeg'...
           'roundpeg','squarepeg','tiltedpeg', 'wave','yinyang'};
    name = names{randi(length(names))};
end
type=0;
% The main switch statement.
switch lower(name)
    
    case 'challenge'
        fa = @(x,y) exp(sin(50*x/3)) + sin(60*exp(y/3)) + sin(70*sin(x/3)) + ...
            sin(sin(80*y/3)) - sin(10*((x+y)/3)) + (x.^2+y.^2)./(4*3^2);
        f = diskfun(fa);
        type =2; %contourf plot instead
    % A scaled version of the classic MATLAB peaks function:
    %case 'peaks'
      %  fa = @(x,y) 2*(1-2*x).^2.*exp(-(2*x).^2 - ((2*y)+1).^2) ...
       %     - 10*((2*x)/5 - (2*x).^3 - (2*y).^5).*exp(-(2*x).^2 - (2*y).^2) ...
       %     - 1/3*exp(-((2*x)+1).^2 - (2*y).^2);
       % f = diskfun(fa);
       % type=1; %set to view(3)
    case 'ellipsepeg' %an ellipse-shaped peg
         fa   = @(t,r)1./(1+(4*((r.*cos(t)).^2+.5*(r.*sin(t)).^2)).^20);
         f = diskfun(fa, 'polar'); 
    case 'flower'
        fa = @(t,r) sin(21*pi*(1+cos(pi*r)).* ...
            (r.^2-2*r.^5.*cos(5*(t-0.11))));
        f = diskfun(fa, 'polar');
        
    case 'poisson'   % solution to a Poisson problem
        rhs = @(t,r) -exp(-40*(r.^2-1).^4).* ...
              sinh(5*(1-r.^11.*cos(11*(t-1/sqrt(2)))));
        bc = @(t) 0*t+1;  
        f = diskfun.poisson(rhs, bc, 512);
        fa = f;
        
    case 'roundpeg'  % a round peg of radius 0.5
        fa = @(t,r) 1./(1+(2*r).^100);
        f = diskfun(fa, 'polar');
    case 'translatepeg'  % a translated round peg of radius 0.5
        fa = @(x,y) 1./(1+(2*((x-.2).^2+x.^2).^20));
        f = diskfun(fa);
    case 'squarepeg'  % a square peg in a round hole
        fa = @(x,y) 1./((1+(2*x).^20).*(1+(2*y).^20));
        f = diskfun(fa);
        
    case 'tiltedpeg'    % A tilted version of squarepeg
         fa = @(x,y) 1./((1+(2*x+.4*y).^20).*(1+(2*y-.4*x).^20));
         f = diskfun(fa);
   
    case 'wave'
        fa = @(x,y) cos(20*x+5*y).^2.*(1-(x.^2+y.^2));
        f = diskfun(fa);
        type = 1; %view(3)
    case 'yinyang'    % a function created by Grady Wright
        fa = @(t,r) -cos(((sin(pi*r).*cos(t) + sin(2*pi*r).*sin(t)))/4);
        f = diskfun(fa, 'polar');

    % Raise an error if the input is unknown.
    otherwise
        error('CHEB:GALLERYDISK:unknown:unknownFunction', ...
            'Unknown function.')
end

% Only return something if there is an output argument.
if ( nargout > 0 )
    varargout = {f, fa};
elseif type==1
    % Otherwise, plot the function.
        plot(f), axis off
        view(3)
        title([name ', rank = ' num2str(length(f))])
elseif type==2
        contourf(f), axis off
        title([name ', rank = ' num2str(length(f))])
else   
    plot(f), axis off
    title([name ', rank = ' num2str(length(f))])
end

end
