function c = infnorm(x)
%INFNORM Computes max(abs(x(:))) for single/double complex/real arrays x.

% infnorm is not compiled; compile it
if isunix
    build_infnorm;
elseif ispc
    build_infnorm_win;
else
    c = infnorm_brute(x);
    return
end

% call the built mex routine
c = infnorm(x);

end

function c = infnorm_brute(x)

persistent isfirstcall
if isempty(isfirstcall)
    isfirstcall = true;
end

if isfirstcall
    warning('only unix and pc are supported; calculating directly using max(abs(x(:))).');
    isfirstcall = false;
end

c = max(abs(x(:)));

end