function [ ir2 ] = ir2( x, y, z, a )
%IR2 returns a^2/r^2 but with points corresponding to r<a set to 0

r2 = x.^2 + y.^2 + z.^2;
ix = r2 < a^2;
ir2 = a^2./r2;
ir2(ix) = 0;

end

