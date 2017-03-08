function [ A ] = permuteVec( x, n )
%PERMUTEVEC List of all possible pickings of 'n' elements from 'x' with
%repetition

%% permute vector
x = x(:)';
m = length(x);

A = permuteVec_iter( x, m, n );

%% testing
% A = permuteVec_brute( x, m, n );
% B = permuteVec_iter( x, m, n );
% fprintf('A and B are equal: %d\n\n', isequal(A,B) );
% 
% t1 = timeit( @() permuteVec_brute( x, m, n ) );
% t2 = timeit( @() permuteVec_iter( x, m, n ) );
% display_toc_time( [t1;t2], {'Brute','Iter'} );


end

function A = permuteVec_iter( x, m, n )

A	=	zeros(m^n,n);
for jj = 1:n
    a       =	repmat( x, [m^(n-jj),1] );
    A(:,jj)	=	repmat( a(:), [m^(jj-1),1] );
end

end

function A = permuteVec_brute( x, m, n )

A	=	zeros(m^n,n);
ind	=	1;

for i1 = 1:m
    if n >= 2
        for i2 = 1:m
            if n >= 3
                for i3 = 1:m
                    if n >= 4
                        for i4 = 1:m
                            if n >= 5
                                for i5 = 1:m
                                    if n >= 6
                                        for i6 = 1:m
                                            A(ind,:) = [x(i1),x(i2),x(i3),x(i4),x(i5),x(i6)];
                                            ind = ind + 1;
                                        end
                                    else
                                        A(ind,:) = [x(i1),x(i2),x(i3),x(i4),x(i5)];
                                        ind = ind + 1;
                                    end
                                end
                            else
                                A(ind,:) = [x(i1),x(i2),x(i3),x(i4)];
                                ind = ind + 1;
                            end
                        end
                    else
                        A(ind,:) = [x(i1),x(i2),x(i3)];
                        ind = ind + 1;
                    end
                end
            else
                A(ind,:) = [x(i1),x(i2)];
                ind = ind + 1;
            end
        end
    else
        A(ind,:) = x(i1);
        ind = ind + 1;
    end
end


end


