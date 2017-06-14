function [ ] = test_parfor( )
%TEST_PARFOR Summary of this function goes here
%   Detailed explanation goes here

coder.extrinsic('tic');
coder.extrinsic('toc');

coder.extrinsic('gcp');
coder.extrinsic('feature');
coder.extrinsic('parpool');

if isempty(gcp('nocreate'))
    nCores = feature('numCores');
    parpool('local',nCores);
end

% A = rand(10,10,500000);
A = 2*rand(50,2,'double');

fprintf('Regular loop:\n');
% disp( timeit( @() for_test(A) ) );
tic; B1 = for_test(A); t1 = toc;

fprintf('Parfor loop:\n');
% disp( timeit( @() parfor_test(A) ) );
tic; B2 = parfor_test(A); t2 = toc;

% display_toc_time( [t1;t2], {'Regular','Parfor'} );
fprintf('Regular: %0.6fs\n',t1);
fprintf('Parfor: %0.6fs\n',t2);
fprintf( 'Difference between results:\t%0.16f\n\n', max(B1(:)-B2(:)) );

end

function B = for_test(A)

f = @func;
options = optimset('MaxFunEvals',100000,'Display','none');

B = zeros(size(A,1),1);
for ii = 1:size(A,2)
    for jj = 1:size(A,2)
        B = B + fminsearch(f,A(:,ii),options);
        disp([ii,jj]);
    end
end

% B = zeros(size(A));
% for ii = 1:size(A,3)
%     B(:,:,ii) = A(:,:,ii)^2;
% end

end

function B = parfor_test(A)

f = @func;
options = optimset('MaxFunEvals',100000,'Display','none');

B = zeros(size(A,1),1);
parfor ii = 1:size(A,2)
    for jj = 1:size(A,2)
        B = B + fminsearch(f,A(:,ii),options);
        disp([ii,jj]);
    end
end

% B = zeros(size(A));
% parfor ii = 1:size(A,3)
%     B(:,:,ii) = A(:,:,ii)^2;
% end

end

function y = func(x)
y = sum(x(:).^2);
end