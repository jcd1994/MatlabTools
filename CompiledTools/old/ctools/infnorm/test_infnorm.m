function test_infnorm
%TEST_INFNORM Tests the function infnorm(x)

n = 100;
s = num2str(n);
main_test([s,' real double'],n,true, 'double',50,[1,4]);
main_test([s,' cplx double'],n,false,'double',50,[1,4]);
main_test([s,' real single'],n,true, 'single',50,[1,4]);
main_test([s,' cplx single'],n,false,'single',50,[1,4]);

end

function main_test(label,n,isreal,type,varargin)

test_time = tic;

if isreal
    
    for ii = 1:n
        x  = randn(randi(varargin{:}),type);
        c1 = infnorm(x);
        c2 = max(abs(x(:)));
        assert( abs(c1-c2) < 10 * eps( max(c1,c2) ) );
    end
    
else
    
    for ii = 1:n
        x  = randnc(randi(varargin{:}),type);
        c1 = infnorm(x);
        c2 = max(abs(x(:)));
        assert( abs(c1-c2) < 10 * eps( max(c1,c2) ) );
    end
    
end

display_toc_time(toc(test_time),label);

end