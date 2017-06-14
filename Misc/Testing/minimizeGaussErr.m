function [ output_args ] = minimizeGaussErr( input_args )
%MINIMIZEGAUSSERR Summary of this function goes here
%   Detailed explanation goes here

x	=   linspace(-5*rand,5*rand,200+randi(200));
h	=   sort(randn(size(x)));
h(floor(length(h)/2):end) = h(floor(length(h)/2):end) + max(h);
a	=   x(1);
b	=   x(end);
M	=   length(x)-1;
dx	=   (b-a)/M;
t	=   linspace(a,b,500);

[sig,C]	=   fminsearch(@costfun,2.0);

    function C = costfun(sig)
        
        E	=   @(t,jj,s)	exp((-0.5/s.^2).*((t-x(jj))/dx).^2)./sqrt(2*pi);
        T	=   @(t,jj)     (1-abs(t-x(jj))/dx).*(abs(t-x(jj))<=dx);
        
        C	=   zeros(numel(sig),1);
        for ii = 1:length(sig)
            y1	=   zeros(size(t));
            y2	=   zeros(size(t));
            for jj = 1:length(x)
                y1	=	y1 + h(jj) * E(t,jj,sig(ii));
                y2	=   y2 + h(jj) * T(t,jj);
            end
            C(ii)	=   sum((y1-y2).^2);
        end
        
        C	=   reshape(C,size(sig));
    end

end