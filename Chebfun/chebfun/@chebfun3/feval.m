function out = feval(f, x, y, z)
%FEVAL  Evaluate a CHEBFUN3 at one or more points.
%   FEVAL(F,X,Y,Z) evaluates the CHEBFUN3 F at the point(s) in (X,Y,Z), 
%   where X, Y, and Z are scalars, vectors or tensors of doubles.
%
%   See also SUBSREF.

% Copyright 2017 by The University of Oxford and The Chebfun Developers.
% See http://www.chebfun.org/ for Chebfun information.

% Empty check:
if ( isempty(f) )
    out = [];
    return
end

if ( isa(x, 'chebfun') && isa(y, 'chebfun') && isa(z, 'chebfun') )
    % Extract chebfun3 along the path x = x(t), y = y(t), z = z(t), i.e.,
    % to construct the 1D chebfun f(x(t), y(t), z(t)).
    out = chebfun(@(t) feval(f, x(t), y(t), z(t)), x.domain);
    return
end

[rX, rY, rZ] = rank(f);

if ( isnumeric(x) && isnumeric(y) && isnumeric(z) )  % f(x, y, z)
    n = size(x);
    if ( length(n) == 2 && min(n) == 1 )
        % Inputs are vectors.
        % TODO: Replace the above with ndims?
        out = vectorCase(f, x, y, z);
        
    elseif ( length(n) == 2 && min(n) > 1 )
        % TODO: Replace the above with ndims?
        out = matrixCase(f, x, y, z);
        if ( size(out) ~= size(x) )
            out = out.';
        end
        
    elseif length(n) == 3 % The inputs are tensors.
        % TODO: Replace the above with ndims?
        out = tensorCase(f, x, y, z, n);
    end
    
elseif ( strcmpi(x, ':') && strcmpi(y, ':') && strcmpi(z, ':') )   % f(:, :, :)
    % Simply return the CHEBFUN3 object itself.
    out = f;

% Developer Note: The following ugly permutaions are necessary to keep 
% consistent with Chebfun2 constructor.
elseif ( isnumeric(x) && strcmpi(y, ':') &&  strcmpi(z, ':') ) % f(x, :, :)
    % Make evaluation points a vector.
    x = x(:);
    % Evaluate:
    core = squeeze(chebfun3.txm(f.core, feval(f.cols, x), 1));
    if ( rY == 1 || rZ == 1 )
        core = core.';
    end
    out = chebfun2(f.tubes * core.' * f.rows.');
    
elseif ( strcmpi(x, ':') && isnumeric(y) &&  strcmpi(z, ':') ) % f(:, y, :)
    % Make evaluation points a vector.
    y = y(:);
    % Evaluate:
    core = squeeze(chebfun3.txm(f.core, feval(f.rows, y), 2));
    if ( rX == 1 )
        core = core.';
    end
    out = chebfun2(f.tubes * core.' * f.cols.');

elseif ( strcmpi(x, ':') && strcmpi(y, ':') && isnumeric(z) ) % f(:, :, z)
    % Make evaluation points a vector.
    z = z(:);
    % Evaluate:
    core = squeeze(chebfun3.txm(f.core, feval(f.tubes, z), 3));
    out = chebfun2(f.rows * core.' * f.cols.');
    
elseif ( strcmpi(x, ':') && isnumeric(y) && isnumeric(z) )  % f(:, y, z)
    core = chebfun3.txm(chebfun3.txm(f.core, feval(f.rows,y), 2), ...
        feval(f.tubes,z), 3);
    out = f.cols * core;
    if ( isa(out, 'chebfun') ) 
        out = simplify(out); 
    end
    
elseif ( isnumeric(x) && strcmpi(y, ':') && isnumeric(z) ) % f(x, :, z)
    core = chebfun3.txm(chebfun3.txm(f.core, feval(f.cols,x), 1), ...
        feval(f.tubes,z), 3)';
    out = f.rows * core;
    if ( isa(out, 'chebfun') ) 
        out = simplify(out); 
    end
    
elseif ( isnumeric(x) && isnumeric(y) &&  strcmpi(z, ':') ) % f(x, y, :)
    core = squeeze(chebfun3.txm(chebfun3.txm(f.core, feval(f.cols, x), ...
        1), feval(f.rows, y), 2));
    out = f.tubes * core;
    if ( isa(out, 'chebfun') )
        out = simplify(out); 
    end
    
end

end

%%
function outVec = vectorCase(f, xVec, yVec, zVec)

[m,n] = size(xVec);
if ( (m == 1) && (n>1) ) % Row vector instead of column vector
    xVec = xVec.';
    yVec = yVec.';
    zVec = zVec.';
end

outVec = zeros(size(xVec));
colsVals = f.cols(xVec); % So, colsVals(:,j) = feval(f.cols(:,j),xVec).
rowsVals = f.rows(yVec);
tubesVals = f.tubes(zVec);
for i = 1:size(xVec, 1) % TODO: How to vectorize this?
    outVec(i) = chebfun3.txm(chebfun3.txm(chebfun3.txm(f.core,...
        colsVals(i,:), 1), rowsVals(i,:), 2), tubesVals(i,:), 3);
end

if ( (m == 1) && (n > 1) )
    outVec = outVec.';
end

end
%%
function out = tensorCase(f, xeval, yeval, zeval, n)
% If the evaluation points are derived from ndgrid, then there is a fast 
% way to evaluate a chebfun3s. Check for this property. 

% Data generated by ndgrid and op = @(x,y,z) op(x,y,z). Useful specially
% when fiberDim = 3.
if ( max(max(max(abs(bsxfun(@minus, xeval, xeval(:, 1, 1)))))) == 0  && ...
        max(max(max(abs(bsxfun(@minus, yeval, yeval(1, :, 1)))))) == 0  && ... 
        max(max(max(abs(bsxfun(@minus, zeval, zeval(1, 1, :)))))) == 0 )
    
    xeval = xeval(:, 1, 1);
    yeval = yeval(1, :, 1).';
    zeval = squeeze(zeval(1, 1, :));

    colsVals = f.cols(xeval); % So, colsVals(:,j) = feval(f.cols(:,j),xVec).
    rowsVals = f.rows(yeval);
    tubesVals = f.tubes(zeval);
    out = chebfun3.txm(chebfun3.txm(chebfun3.txm(f.core, colsVals, 1),...
        rowsVals, 2), tubesVals, 3);        

% Useful specially when fiberDim = 1.
elseif ( max(max(max(abs(bsxfun(@minus, xeval, xeval(1, 1, :)))))) == 0 ...
        && max(max(max(abs(bsxfun(@minus, yeval, yeval(:, 1, 1)))))) == 0  && ... 
        max(max(max(abs(bsxfun(@minus, zeval, zeval(1, :, 1)))))) == 0 )
    xeval = squeeze(xeval(1, 1, :));
    yeval = yeval(:, 1, 1); 
    zeval = zeval(1, :, 1).';
    
    colsVals = f.cols(xeval);
    rowsVals = f.rows(yeval);
    tubesVals = f.tubes(zeval);
    fCore = permute(f.core, [2 3 1]);
    out = chebfun3.txm(chebfun3.txm(chebfun3.txm(fCore, colsVals, 3),...
        rowsVals, 1), tubesVals, 2);

% Useful specially when fiberDim = 2.    
elseif ( max(max(max(abs(bsxfun(@minus, xeval, xeval(1, :, 1)))))) == 0  && ...
        max(max(max(abs(bsxfun(@minus, yeval, yeval(1, 1, :)))))) == 0  && ... 
        max(max(max(abs(bsxfun(@minus, zeval, zeval(:, 1, 1)))))) == 0 )
    
    xeval = xeval(1, :, 1).';
    yeval = squeeze(yeval(1, 1, :));
    zeval = zeval(:, 1, 1);

    colsVals = f.cols(xeval);
    rowsVals = f.rows(yeval);
    tubesVals = f.tubes(zeval);
    fCore = permute(f.core, [3 1 2]);
    out = chebfun3.txm(chebfun3.txm(chebfun3.txm(fCore, colsVals, 2),...
        rowsVals, 3), tubesVals, 1);
       
% Check to see if the input is obtained by meshgrid:            
elseif ( max(max(max(abs(bsxfun(@minus, xeval, xeval(1, :, 1)))))) == 0  && ... 
        max(max(max(abs(bsxfun(@minus, yeval, yeval(:, 1, 1)))))) == 0  && ... 
        max(max(max(abs(bsxfun(@minus, zeval, zeval(1, 1, :)))))) == 0 )
    
    xeval = xeval(1, :, 1).';
    yeval = yeval(:, 1, 1);
    zeval = squeeze(zeval(1, 1, :));
    colsVals = f.cols(xeval); % So, colsVals(:,j) = feval(f.cols(:,j),xVec).
    rowsVals = f.rows(yeval);
    tubesVals = f.tubes(zeval);
    fCore = permute(f.core, [2 1 3]);
    out = chebfun3.txm(chebfun3.txm(chebfun3.txm(fCore, rowsVals, 1),...
        colsVals, 2), tubesVals, 3);
            
else
    % Inputs are not obtained by ndgrid or meshgrid. No specific
    % pattern could be found in them and they might be e.g. random points.
    % This is slow!!! 
    xx1 = chebfun3.unfold(xeval, 1).'; % Transposed to make a long matrix
    yy1 = chebfun3.unfold(yeval, 1).'; % so that it's faster in MATLAB.
    zz1 = chebfun3.unfold(zeval, 1).';
    fevalNew = zeros(n(2)*n(3), n(1));
    for i=1:n(1)
        fevalNew(:,i) = vectorCase(f, xx1(:,i), yy1(:,i), zz1(:,i));
    end
    out = chebfun3.fold(fevalNew.', n, 1, [2 3]);
end

end

%%
function out = matrixCase(f, xeval, yeval, zeval)
% xeval, yeval, and zeval are matrices. First, we check if they obey
% specific patterns from ndgrid or meshgrid.

% Data generated by ndgrid & zz is a multiple of a single scalar
if ( max(max(max(abs(bsxfun(@minus, xeval, xeval(:, 1)))))) == 0  && ...
        max(max(max(abs(bsxfun(@minus, yeval, yeval(1, :)))))) == 0  && ... 
        max(max(max(abs(bsxfun(@minus, zeval, zeval(1, 1)))))) == 0 )
    
    xeval = xeval(:, 1);
    yeval = yeval(1, :)';
    zeval = zeval(1, 1);
    colsVals = f.cols(xeval);
    rowsVals = f.rows(yeval);
    tubesVals = f.tubes(zeval);
    out = chebfun3.txm(chebfun3.txm(chebfun3.txm(f.core, colsVals, 1),...
        rowsVals, 2), tubesVals, 3);
    
% Data generated by ndgrid & yy is a multiple of a single scalar
elseif ( max(max(max(abs(bsxfun(@minus, xeval, xeval(:, 1)))))) == 0  && ...                     
        max(max(max(abs(bsxfun(@minus, yeval, yeval(1, 1)))))) == 0  && ... 
        max(max(max(abs(bsxfun(@minus, zeval, zeval(1, :)))))) == 0 )
    
    xeval = xeval(:, 1); 
    yeval = yeval(1, 1); 
    zeval = zeval(1, :)'; 
    colsVals = f.cols(xeval); 
    rowsVals = f.rows(yeval);
    tubesVals = f.tubes(zeval);
    out = squeeze(chebfun3.txm(chebfun3.txm(chebfun3.txm(f.core, colsVals, 1),...
        rowsVals, 2), tubesVals, 3));

% Data generated by ndgrid & xx is a multiple of a single scalar    
elseif ( max(max(max(abs(bsxfun(@minus, xeval, xeval(1, 1)))))) == 0  && ...                     
        max(max(max(abs(bsxfun(@minus, yeval, yeval(:, 1)))))) == 0  && ... 
        max(max(max(abs(bsxfun(@minus, zeval, zeval(1, :)))))) == 0 )
    
    xeval = xeval(1, 1); 
    yeval = yeval(:, 1); 
    zeval = zeval(1, :)';
    colsVals = f.cols(xeval); 
    rowsVals = f.rows(yeval);
    tubesVals = f.tubes(zeval);
    out = squeeze(chebfun3.txm(chebfun3.txm(chebfun3.txm(f.core,...
        colsVals, 1), rowsVals, 2), tubesVals, 3));
    
% Data generated by meshgrid & zz is a multiple of a single scalar
elseif ( max(max(max(abs(bsxfun(@minus, xeval, xeval(1, :)))))) == 0  && ...
        max(max(max(abs(bsxfun(@minus, yeval, yeval(:, 1)))))) == 0  && ... 
        max(max(max(abs(bsxfun(@minus, zeval, zeval(1, 1)))))) == 0 )
    
    xeval = xeval(1, :)';
    yeval = yeval(:, 1);
    zeval = zeval(1, 1);
    colsVals = f.cols(xeval);
    rowsVals = f.rows(yeval);
    tubesVals = f.tubes(zeval);
    fCore = permute(f.core,[2 1 3]);
    out = chebfun3.txm(chebfun3.txm(chebfun3.txm(fCore, rowsVals, 1), ...
        colsVals, 2) ,tubesVals, 3)';
    
% Data generated by meshgrid & yy is a multiple of a single scalar
elseif ( max(max(max(abs(bsxfun(@minus, xeval, xeval(1, :)))))) == 0  && ...                     
        max(max(max(abs(bsxfun(@minus, yeval, yeval(1, 1)))))) == 0  && ... 
        max(max(max(abs(bsxfun(@minus, zeval, zeval(:, 1)))))) == 0 )
    
    xeval = xeval(1, :)'; 
    yeval = yeval(1, 1); 
    zeval = zeval(:, 1); 
    colsVals = f.cols(xeval); 
    rowsVals = f.rows(yeval);
    tubesVals = f.tubes(zeval);
    out = squeeze(chebfun3.txm(chebfun3.txm(chebfun3.txm(f.core, colsVals, 1),...
        rowsVals, 2), tubesVals, 3));

% Data generated by meshgrid & xx is a multiple of a single scalar    
elseif ( max(max(max(abs(bsxfun(@minus, xeval, xeval(1, 1)))))) == 0  && ...                     
        max(max(max(abs(bsxfun(@minus, yeval, yeval(1, :)))))) == 0  && ... 
        max(max(max(abs(bsxfun(@minus, zeval, zeval(:, 1)))))) == 0 )
    
    xeval = xeval(1, 1);
    yeval = yeval(1, :)';
    zeval = zeval(:, 1);
    colsVals = f.cols(xeval); 
    rowsVals = f.rows(yeval);
    tubesVals = f.tubes(zeval);
    out = squeeze(chebfun3.txm(chebfun3.txm(chebfun3.txm(f.core,...
        colsVals, 1), rowsVals, 2), tubesVals, 3));
    
else
    % Inputs are not obtained by ndgrid or meshgrid.
    % This might be very slow!!!
    out = vectorCase(f, xeval(:), yeval(:), zeval(:));   
    out = reshape(out, size(xeval, 1), size(xeval, 2));
end

end
