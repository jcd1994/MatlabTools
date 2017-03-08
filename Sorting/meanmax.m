function y = meanmax( x, n, dim )
%MEANMAX Returns the mean value of the top 'n' maximum values of 'x' along
%dimension 'dim'

if isvector(x)
    x = sort(x);
    y = mean( x(end-n+1:end) );
    return
end

x = sort( x, dim );
switch ndims(x)

    case 2
        switch dim
            case 1
                y = mean( x(end-n+1:end,:), dim );
            otherwise
                y = mean( x(:,end-n+1:end), dim );
        end
        
    case 3
        switch dim
            case 1
                y = mean( x(end-n+1:end,:,:), dim );
            case 2
                y = mean( x(:,end-n+1:end,:), dim );
            otherwise
                y = mean( x(:,:,end-n+1:end), dim );
        end

    case 4
        switch dim
            case 1
                y = mean( x(end-n+1:end,:,:,:), dim );
            case 2
                y = mean( x(:,end-n+1:end,:,:), dim );
            case 3
                y = mean( x(:,:,end-n+1:end,:), dim );
            otherwise
                y = mean( x(:,:,:,end-n+1:end), dim );
        end

end

end