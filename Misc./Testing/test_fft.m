function [ ] = test_fft( )
%TEST_FFT Summary of this function goes here
%   Detailed explanation goes here

% s = 10 * rand;
% N = 10 + randi(50);
% test2(N,s,[]);

test3

end

function test1

fs = 100; %sampling frequency
dt = 1/fs;
t = dt * (-400:399); %time vector centered around t=0
L = length(t); %number of sample points
%N = 2^nextpow2(L);  %necessary?

y = exp(-(t.^2));
Y = dt * ifftshift(abs(fft(y)));

freq = (-L/2:L/2-1)*fs/L; %freq vector

w = 2*pi*freq;
F = exp(-w.^2/4)*sqrt(pi); %analytical solution

error = max(abs(Y - F));
disp(error);

close all force
figure, hold on;
plot(freq,Y,'r');
plot(freq,F,'b');
xlabel('Frequency, w');
legend('numerical','analytic');
hold off;

end

function test2(N,s,T)

a	= 10; % number of standard deviations in time domain
T	= a * s * 2 / N;
Fs	= 1/T;

t	= T  * (-floor(N/2):ceil(N/2)-1);
f	= Fs * (-floor(N/2):ceil(N/2)-1) / N;

fx = @(t) (1/(s*sqrt(2*pi))) * exp( -t.^2/(2*s^2) );
fW = @(f,s) (1/T)*exp(-s^2*(2*pi*f).^2/2);

x = fx(t);
X = real( fftshift(fft(ifftshift(x))) );
W = fW(f,s);

% close all force
figure, plot(f,X,'b-',f,W,'ro'), xlim([f(1),f(end)]), ylim([0,max(X)]), title('fft')
% figure, plot(t,x), xlim(a*s*[-1,1]), ylim([0,max(x)]), title('time')

% print results
fprintf('Standard dev:\t%0.4f\n', s);
fprintf('Num Points:\t%0.4f\n', N);
fprintf('Max error:\t%0.16f\n', max(abs(X-W)));

end

% from: http://users.ece.gatech.edu/mrichard/Gaussian%20FT%20and%20random%20process.pdf
function test3

% gauss_noise
%
% M-file to create a complex random process with Gaussian pdf, Gaussian
% power spectrum (and therefore Gaussian autocorrelation)
close all
clear all
format compact
% first make sure we have the Gaussian DTFT pair understood correctly.
% Start by generating gaussian window using gausswin. Scale to be a true
% Gaussian pdf. Test variance visually, test peak amplitude and area.
sig = input('Enter window standard deviation (samples): ')
N = input('Enter window length (odd; at least 6 std devs): ')
w = gausswin(N,(N-1)/2/sig)/sqrt(2*pi)/sig;
% sum(w) % this should be 1.0
% max(w)/(1/sqrt(2*pi)/sig) % this should be 1.0
figure
plot((0:N-1),w);
axis([0 N-1 0 1/sqrt(2*pi)/sig])
xlabel('sample'); ylabel('amplitude')

% figure
% plot((0:N-1),w/max(w)/exp(-0.5)); % plot should go through 1.0 at n=sig
% grid; vline((N-1)/2+sig); vline((N-1)/2-sig);
% now let's test the DTFT of our time-domain Gaussian against the
% analytical formula
K = 2^(nextpow2(N)+2);
W = fft(w,K);
omega = 2*pi*(0:K-1)'/K - pi;
Wtest = exp(-omega.^2*sig^2/2);
figure
plot(omega,fftshift(abs(W))); hold on
plot(omega,Wtest,'or'); hold off
grid
xlabel('frequency (radians/sample)'); ylabel('amplitude')
axis([-pi pi 0 1])

end