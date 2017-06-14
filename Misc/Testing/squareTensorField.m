function D = squareTensorField( D ) %#codegen
%SQUAREDTI Input is an MxNx3x3 (4D) or MxNxPx3x3 (5D) tensor field matrix.
%The tensor elements will be squared

if ndims(D) == 4
    for ii = 1:size(D,1)
        for jj = 1:size(D,2)
            D(ii,jj,:,:) = squeeze(D(ii,jj,:,:))^2;
        end
    end
elseif ndims(D) == 5
    for ii = 1:size(D,1)
        for jj = 1:size(D,2)
            for kk = 1:size(D,3)
                D(ii,jj,kk,:,:) = squeeze(D(ii,jj,kk,:,:))^2;
            end
        end
    end
end

end

