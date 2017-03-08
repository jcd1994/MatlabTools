function y = rmsmax( x, n, dim )
%RMSMAX Returns the root-mean-square value of the top 'n' maximum values
%of 'x' along dimension 'dim'

if isvector(x)
    x = sort(x);
    y = rms( x(end-n+1:end) );
    return
end

x = sort( x, dim );
switch ndims(x)

    case 2
        switch dim
            case 1
                y = rms( x(end-n+1:end,:), dim );
            otherwise
                y = rms( x(:,end-n+1:end), dim );
        end
        
    case 3
        switch dim
            case 1
                y = rms( x(end-n+1:end,:,:), dim );
            case 2
                y = rms( x(:,end-n+1:end,:), dim );
            otherwise
                y = rms( x(:,:,end-n+1:end), dim );
        end

    case 4
        switch dim
            case 1
                y = rms( x(end-n+1:end,:,:,:), dim );
            case 2
                y = rms( x(:,end-n+1:end,:,:), dim );
            case 3
                y = rms( x(:,:,end-n+1:end,:), dim );
            otherwise
                y = rms( x(:,:,:,end-n+1:end), dim );
        end

end

end