function c = sum_pw(x)
%SUM_PW Computes max(abs(x(:))) for single/double complex/real arrays x.

% sum_pw is not compiled; compile it
if isunix
    build_sum_pw;
elseif ispc
    build_sum_pw_win;
else
    c = sum_pw_brute(x);
    return
end

% call the built mex routine
c = sum_pw(x);

end

function c = sum_pw_brute(x)

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