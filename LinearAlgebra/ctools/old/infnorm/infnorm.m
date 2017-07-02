function c = infnorm(x)
%INFNORM Computes max(abs(x(:))) for single/double complex/real arrays x.
    
    isSingle	=   isa(x,'single');
    isDouble	=   isa(x,'double');
    if ~(isSingle || isDouble), error('x must be double or single.'); end
    
    %----------------------------------------------------------------------
    
    if isDouble
        c = infnorm_cd(x);
    else
        c = infnorm_cs(x);
    end
    
end
