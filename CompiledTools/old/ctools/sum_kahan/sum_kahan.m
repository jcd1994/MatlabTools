function c = sum_kahan(x)
%SUM_KAHAN Computes max(abs(x(:))) for single/double complex/real arrays x.

% sum_kahan is not compiled; compile it
if isunix
    build_sum_kahan;
elseif ispc
    build_sum_kahan_win;
else
    c = sum_kahan_brute(x);
    return
end

% call the built mex routine
c = sum_kahan(x);

end

function c = sum_kahan_brute(x)

persistent isfirstcall
if isempty(isfirstcall)
    isfirstcall = true;
end

if isfirstcall
    warning('only unix and pc are supported; calculating directly using sum(x(:)).');
    isfirstcall = false;
end

c = sum(x(:));

end