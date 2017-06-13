function varargout = gallerytrig(name)
%CHEB.GALLERYTRIG   Chebfun periodic example functions.
%   F = CHEB.GALLERYTRIG(NAME) returns a periodic chebfun or a quasimatrix
%   corresponding to NAME. See the listing below for available names.
%
%   For example,  plot(cheb.gallerytrig('gibbs'))  plots the first 20 terms of
%   the Gibbs-Wilbraham approximation of a square wave. For details of how each
%   function is constructed, try  type +cheb/gallerytrig  or
%   edit cheb.gallerytrig.
%
%   [F,FA] = CHEB.GALLERYTRIG(NAME) also returns the anonymous function FA used
%   to define the function. Some gallery functions are generated by operations
%   beyond the usual Chebfun constructor (e.g. by solving ODEs), so FA in those
%   cases simply evaluates the chebfun.
%
%   CHEB.GALLERYTRIG with no input argument returns a random function from the
%   gallery.
%
%   CHEB.GALLERYTRIG with no output argument creates a plot of the selected
%   function.
%
%   AMsignal     Signal with modulated amplitude
%   FMsignal     Signal with modulated frequency
%   gibbs        Gibbs-Wilbraham approximation of a square wave
%   gibbsinterp  Interpolant of a square wave
%   noisyfun     Smooth function plus high-frequency noise
%   random       Trigonometric interpolant through random data
%   sinefun1     As smooth as it looks
%   sinefun2     Not as smooth as it looks
%   starburst    Complex function from Approx Theory & Approx Practice
%   tsunami      Solution to periodic ODE
%   wavepacket   Cosine modulated by Gaussian
%   weierstrass  First 8 terms of Weierstrass fractal
%
%   Gallery functions are subject to change in future releases of Chebfun.
%
% See also CHEB.GALLERY, CHEB.GALLERY2, CHEB.GALLERY3, CHEB.GALLERYDISK, CHEB.GALLERYSPHERE.

% Copyright 2017 by The University of Oxford and The Chebfun Developers.
% See http://www.chebfun.org/ for Chebfun information.


% If the user did not supply an input, return a random function
% from the gallery.
if ( nargin == 0 )
    names = {'AMsignal', 'FMsignal', 'gibbs', 'gibbsinterp', ...
        'noisyfun', 'random', 'sinefun1', 'sinefun2', 'starburst', ...
        'tsunami', 'wavepacket', 'weierstrass'};
    name = names{randi(length(names))};
end

% If nargout == 0, then the function is plotted. Each function in the gallery
% has its own plotting preferences.
ylims = [];
axispref = {};

% The main switch statement.
switch lower(name)

    % Signal with modulated amplitude:
    case 'amsignal'
        fa = @(x) cos(50*x).*(1+.2*cos(5*x));
        f = chebfun(fa, [-pi pi], 'trig');
        ylims = [-2 2];

    % Signal with modulated frequency:
    case 'fmsignal'
        fa = @(x) cos(50*x+4*sin(5*x));
        f = chebfun(fa, [-pi pi], 'trig');
        ylims = [-2 2];

    % Function from SIAM 100-digit challenge:
    case 'gibbs'
        n = 20;
        N = (1:2:n)';
        fa = @(x) sum(4/pi * sin(bsxfun(@times,N,x(:)')) ...
                            ./ (N*ones(1,length(x))) )';
        f = chebfun(fa, [-pi pi], 'trig');

    % Interpolant of a square wave:
    case 'gibbsinterp'
        n = 20;
        fa = @(x) 2*(x > 0) - 1;
        f = chebfun(fa, [-pi pi], 'trig', 2*n+1);

    % Smooth function plus high-frequency noise:
    case 'noisyfun'
        n = 200;
        xx = trigpts(n, [-pi pi]);
        ff = exp(sin(xx)) + 0.05*randn(n,1);
        f = chebfun(ff, [-pi pi], 'trig');
        fa = @(x) f(x);

    % Trigonometric interpolant through random data:
    case 'random'
        f = chebfun(rand(100,1), [-pi,pi], 'trig');
        fa = @(x) f(x);

    % As smooth as it looks:
    case 'sinefun1'
        fa = @(x) (1.75 + sin(16*pi*x));
        f = chebfun(fa, 'trig');

    % Not as smooth as it looks:
    case 'sinefun2'
        fa = @(x) (1.75 + sin(16*pi*x)).^1.0001;
        f = chebfun(fa, 'trig');

    % Complex function from Approx Theory & Approx Practice:
    case 'starburst'
        fa = @(t) (3 + sin(10*t) + sin(61*exp(.8*sin(t)+.7))).*exp(1i*t);
        f = chebfun(fa, [-pi,pi], 'trig');
        axispref = {'equal', [-5.5 5.5 -5 5.5]};

    % Solution to periodic ODE:
    case 'tsunami'
        op = @(x,u) diff(u,2) + diff(u) + 600*(1+sin(x)).*u;
        L = chebop(op, [-pi,pi], 'periodic');
        f = L\1;
        fa = @(x) f(x);
        ylims = [-.15 .23];

    % Cosine modulated by Gaussian:
    case 'wavepacket'
        fa = @(x) exp(-5*x.^2).*cos(50*x);
        f = chebfun(fa, [-pi pi], 'trig');
        ylims = [-1.2 1.2];

    % The first eight terms of the pathological function:
    case 'weierstrass'
        k = 8;
        K = (1:k)';
        fa = @(x) sum( 2.^-(K*ones(1,length(x))) ...
                    .* cos(bsxfun(@times, 4.^K, x(:)')) )';
        f = chebfun(fa, [-pi/4 pi/4], 'trig');
        ylims = [-1 1.2];

    % Raise an error if the input is unknown.
    otherwise
        error('CHEB:GALLERYTRIG:unknown:unknownFunction', ...
            'Unknown function.')
end

% Only return something if there is an output argument.
if ( nargout > 0 )
    varargout = {f, fa};
else
    % Otherwise, plot the function.
    plot(f)
    title([name ', length = ' num2str(length(f))])
    if ( ~isempty(ylims) )
        ylim(ylims)
    end
    if ( ~isempty(axispref) )
        axis(axispref{:})
    end
end

end
