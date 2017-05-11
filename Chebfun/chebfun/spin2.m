function [uout, tout] = spin2(varargin)
%SPIN2  Solve a time-dependent PDE in 2D with periodicity in space, using a
%Fourier spectral method and an exponential integrator time-stepping scheme.
%
%   UOUT = SPIN2(PDECHAR) solves the PDE specified by the string PDECHAR, and
%   plots a movie of the solution as it computes it; it is a demo mode.
%   The space and time intervals and the initial condition are chosen to produce
%   beautiful movies. Strings available include 'GL2' for Ginzburg-Landau
%   equation and 'GS2' for Gray-Scott equations. Many other PDEs are available,
%   see Remark 1 and Examples 1-4. The output UOUT is a CHEBFUN2 corresponding
%   to the solution at the final time (a CHEBMATRIX for systems of equations,
%   each row representing one variable).
%
%   UOUT = SPIN2(S, N, DT) solves the PDE specified by the SPINOP2 S with N grid
%   points in each direction and time-step DT. It plots a movie of the solution
%   as it computes it. See HELP/SPINOP2 and Example 5.
%
%   UOUT = SPIN2(S, N, DT, PREF) allows one to use the preferences specified by
%   the SPINPREF2 object PREF. See HELP/SPINPREF2 and Example 6.
%
%   UOUT = SPIN2(S, N, DT, 'PREF1', VALUEPREF1, 'PREF2', VALUEPREF2, ...) is an
%   alternative to the previous syntax. See Example 6.
%
%   [UOUT, TOUT] = SPIN2(...) also returns the times chunks TOUT at which UOUT
%   was computed.
%
% Remark 1: Available (case-insensitive) strings PDECHAR are
%
%    - 'GL2' for Ginzburg-Landau equation,
%    - 'GS2' for Gray-Scott equations,
%    - 'Schnak2' for Schnakenberg equations,
%    - 'SH2' for Swift-Hohenberg equation.
%
% Example 1: Ginzburg-Landau equation (spiral waves)
%
%       u = spin2('GL2');
%
%    solves the Ginzburg-Landau equation
%
%        u_t = laplacian(u) + u - (1+1.5i)*u*|u|^2,
%
%    on [0 100]^2 from t=0 to t=100, with a random initial condition. 
%    The movie plots the real part of u.
%
% Example 2: Gray-Scott equations (fingerprints patterns)
%
%       u = spin2('GS2');
%
%    solves the Gray-Scott equations
%
%       u_t = 2e-5*laplacian(u) + 3.5e-2*(1-u) - u*v^2,
%       v_t = 1e-5*laplacian(v) - 9.5e-2*v + u*v^2,
%
%    on [0 1.25]^2 from t=0 to t=8000, with initial condition
%
%       u0(x,y) = 1 - exp(-150*((x-G/2.05)^2 + (y-G/2.05)^2)),
%       v0(x,y) = exp(-150*((x-G/2)^2 + 2*(y-G/2)^2)),
%           with G=1.25.
%
% Example 3: Schnakenberg equations (pattern formation)
%
%       u = spin2('Schnak2');
%
%    solves the Schnakenberg equations
%
%       u_t = laplacian(u) + 3*(.1 - u + u^2*v),
%       v_t = 10*laplacian(v) + 3*(.9 - u^2*v),
%
%    on [0 30]^2 from t=0 to t=800, with initial condition
%
%       u0(x,y) = 1 - exp(-2*((x-G/2.15)^2 + (y-G/2.15)^2)),
%       v0(x,y) = .9/(.1^2+.9^2) + exp(-2*((x-G/2)^2 + 2*(y-G/2)^2)),
%           with G=50.
%
% Example 4: Swift-Hohenberg equation (Rayleigh-Benard convection)
%
%       u = spin2('SH2');
%
%    solves the Swift-Hohenberg equation
%
%       u_t = -2*laplacian(u) - biharmonic(u) - .9*u + u^2 - u^3,
%
%    on [0 20]^2 from t=0 to t=200, with a random initial condition.
%
% Example 5: PDE specified by a SPINOP2
%
%       dom = [0 100 0 100]; tspan = [0 100];
%       S = spinop2(dom, tspan);
%       S.lin = @(u) lap(u);
%       S.nonlin = @(u) u - (1 + 1.5i)*u.*(abs(u).^2);
%       S.init = chebfun2(.1*randn(128, 128), dom, 'trig')
%       u = spin2(S, 64, 2e-1);
%
%   is equivalent to u = spin2('GL2');
%
% Example 6: Using preferences
%
%       pref = spinpref2('plot', 'off', 'scheme', 'pecec433');
%       S = spinop2('sh2');
%       u = spin2(S, 64, 5e-1, pref);
%   or simply,
%       u = spin2(S, 64, 5e-1, 'plot', 'off', 'scheme', 'pecec433');
%
%   solves the Swift-Hohenberg equation using N=64 grid points in each
%   direction, a time-step dt=5e-1, doesn't produce any movie use the
%   time-stepping scheme PECEC433.
%
% See also SPINOP2, SPINPREF2, EXPINT.

% Copyright 2017 by The University of Oxford and The Chebfun Developers.
% See http://www.chebfun.org/ for Chebfun information.

% We are going to parse the inputs and call SOLVEPDE in the following ways,
%
%       SPINOPERATOR.SOLVEPDE(S, N, dt)
%  or
%       SPINOPERATOR.SOLVEPDE(S, N, dt, pref)
%
% where S is a SPINOP2 object, N is the number of grid points in each direction, 
% DT is the time-step and PREF is a SPINPREF2 oject.

if ( nargin == 1 ) % e.g., u = spin2('gl2')
    try spinop2(varargin{1});
    catch
        error('Unrecognized PDE. See HELP/SPIN2 for the list of PDEs.')
    end
    [S, N, dt, pref] = parseInputs(varargin{1});
    varargin{1} = S;
    varargin{2} = N;
    varargin{3} = dt;
    varargin{4} = pref;
elseif ( nargin == 3 ) % e.g., u = spin2(S, 128, 1e-1)
    % Nothing to do here.
elseif ( nargin == 4 ) % e.g., u = spin2(S, 128, 1e-1, pref)
    % Nothing to do here.
elseif ( nargin >= 5 ) % u.g., u = spin2(S, 128, 1e-1, 'plot', 'off')
    % In this case, put the options in a SPINPREF2 object.
    pref = spinpref2();
    j = 4;
    while j < nargin
        pref.(varargin{j}) = varargin{j+1};
        varargin{j} = [];
        varargin{j+1} = [];
        j = j + 2;
    end
    varargin{end + 1} = pref;
    varargin = varargin(~cellfun(@isempty, varargin));
end

% SPIN2 is a wrapper for SOLVPDE:
[uout, tout] = spinoperator.solvepde(varargin{:});

end

function [S, N, dt, pref] = parseInputs(pdechar)
%PARSEINPUTS   Parse the inputs.

pref = spinpref2();
S = spinop2(pdechar);
if ( strcmpi(pdechar, 'GL2') == 1 )
    dt = 2e-1;
    N = 64;
elseif ( strcmpi(pdechar, 'GS2') == 1 )
    dt = 4;
    pref.iterplot = 8;
    N = 64;
elseif ( strcmpi(pdechar, 'Schnak2') == 1 )
    dt = 5e-1;
    pref.iterplot = 10;
    N = 64;
elseif ( strcmpi(pdechar, 'SH2') == 1 )
    dt = 1;
    N = 64;
end

end