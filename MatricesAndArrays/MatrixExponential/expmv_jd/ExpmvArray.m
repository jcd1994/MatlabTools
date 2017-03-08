classdef ExpmvArray
    %EXPMVARRAY Class for easily handling different input types for EXPMV
    
    properties
        
        A       % Matrix to be exponentiated
        n       % Size of matrix A is [n,n]
        type	% Type of matrix
        Class	% Class of Amatrix
        
    end
    
    methods
        
        %==================================================================
        % Constructor
        %==================================================================
        function E = ExpmvArray( A, n, Class )
            
            if nargin < 3, Class = []; end
            if nargin < 2, n = []; end
            if nargin < 1, error('Must provide A matrix'); end
            
            if issparse( A )
                
                if nargin < 3 || isempty( Class )
                    Class	=   'double';
                elseif ~strcmpi( Class, 'double' )
                    warning( 'A class must be ''double'' for sparse matrices. Overriding.' );
                    Class	=   'double';
                end
                
                n       =	handle_n_input(A,n,size(A));
                Class	=   handle_Aclass_input(Class);
                E.type	=   'sparse';
                
            elseif isa( A, 'function_handle' )
                
                if nargin < 3 || isempty(n) || isempty( Class )
                    error( 'Must provide matrix size and class for function handle' );
                end
                
                n       =	handle_n_input(A,n);
                Class	=   handle_Aclass_input(Class);
                E.type	=   'function';
                
            elseif isa( A, 'Toeplitz3D' )
                
                n       =   size(A,1);
                Class	=   class(A);
                E.type	=   'Toeplitz3D';
                
            elseif isa( A, 'matfun' )
                
                n       =   size(A,1);
                Class	=   class(A);
                E.type	=   'matfun';
                
            elseif isa( A, 'double' )
                
                n       =   handle_n_input(A,n,size(A));
                Class	=	handle_Aclass_input(Class,'double');
                E.type	=   'Array';
                
            elseif isa( A, 'single' )
                
                n       =   handle_n_input(A,n,size(A));
                Class	=	handle_Aclass_input(Class,'single');
                E.type	=   'Array';
                
            else
                
                % Unknown type; throw error
                error( 'Unsupported matrix type.' );
                
            end
            
            E.A         =   A;
            E.n         =   n;
            E.Class	=   Class;
            
        end
        
        
        %==================================================================
        % Matrix multiplication
        %==================================================================
        function b = mtimes(E,x)
            
            if isa( E, 'ExpmvArray' )
                
                if ~isfloat(x)
                    error( 'RHS multiplication only implemented for float arrays.' );
                end
                
                switch upper(E.type)
                    case 'SPARSE'
                        clx	=   class(x);
                        if ~strcmpi(clx,'double'), x = double(x); end
                        b	=   E.A * x;
                        if ~strcmpi(class(b),clx), b = cast(b,clx); end
                    case 'FUNCTION'
                        b	=   E.A( x );
                    otherwise
                        b	=   E.A * x;
                end
                
            else
                error( 'LHS multiplication is left purposely undefined.' );
            end
            
        end
        
        %==================================================================
        % Array multiplication
        %==================================================================
        function F = times(E,t)
            
            if isa( t, 'ExpmvArray' )
                F	=	times(t,E);
            else
                if ~isscalar(t)
                    error( 'Array Multiplication only defined for scalar t.' );
                end
                
                F	=   E;
                switch upper(F.type)
                    case 'SPARSE'
                        F.A	=	F.A .* double(t);
                    case 'FUNCTION'
                        F.A	=   @(x) t .* F.A(x);
                    otherwise
                        F.A	=   F.A .* t;
                end
                
            end
            
        end
        
        %==================================================================
        % Matrix Absolute Value
        %==================================================================
        function F = abs(E)
            
            F	=   E;
            switch upper(F.type)
                case 'FUNCTION'
                    % Do not have access to matrix for taking abs-val
                    error( 'Cannot take absolute value of function type!' );
                otherwise
                    F.A	=   abs(E.A);
            end
            
        end
        
        %==================================================================
        % Matrix trace
        %==================================================================
        function Tr = trace(E)
            
            switch upper(E.type)
                case 'SPARSE'
                    Tr	=	full( trace( E.A ) );
                case 'FUNCTION'
                    error( 'Cannot call trace on function type.' );
                otherwise % Double, Single, or Toeplitz3D
                    Tr	=	trace( E.A );
            end
            
        end
        
        %==================================================================
        % Matrix p-norm (only for p == 1)
        %==================================================================
        function N = norm(E,p)
            
            if nargin < 2, p = 1; end
            
            if p ~= 1
                error( 'Only 1-norm is implemented.' );
            end
            
            switch upper(E.type)
                case 'FUNCTION'
                    N	=   EstimateFunctionNorm(E);
                otherwise
                    N	=   norm(E.A,1);
            end
                
            
        end
        
        %==================================================================
        % Shift by constant diagonal matrix
        %==================================================================
        function F = shift(E,mu)
            
            F	=   E;
            switch upper(F.type)
                case 'SPARSE'
                    F.A     =	F.A - mu.*speye(F.n);
                case 'FUNCTION'
                    F.A     =   @(x) F.A(x) - mu.*x;
                case 'ARRAY'
                    F.A     =	F.A - mu.*eye(F.n,'like',F.A);
                otherwise % Toeplitz3D or other class
                    F.A     =   shift(F.A,mu);
            end
            
        end
        
        %==================================================================
        % Balance Matrix
        %==================================================================
        function [D,F,b] = balance(E,b)
            
            if nargin < 2, b = []; end
            
            switch upper(E.type)
                case 'SPARSE'
                    % Balance function does not work for sparse matrices
                    D	=   [];
                    F	=   E;
                case 'FUNCTION'
                    % Do not have access to matrix for balancing
                    D	=   [];
                    F	=   E;
                case 'TOEPLITZ3D'
                    % Toeplitz matrix is already balanced
                    D	=   [];
                    F	=   E;
                otherwise
                    % Balance Double or Single matrix
                    [D,B] = balance(E.A);
                    if norm(B,1) < norm(E.A,1)
                        F	=   E;
                        F.A	=   B;
                        if ~isempty(b)
                            b	=	D\b;
                        end
                    else
                        D	=   [];
                        F	=   E;
                    end
            end
                        
        end
        
        %==================================================================
        % Class of A matrix
        %==================================================================
        function Class = class(E)
            Class	=   E.Class;
        end
        
        %==================================================================
        % size
        %==================================================================
        function Asize = size(E,dim)
            if nargin < 2
                Asize	=   [E.n,E.n];
            elseif ( dim == 1 || dim == 2 )
                Asize	=   E.n;
            elseif ( dim > 2 && dim == round(dim) )
                Asize	=   1;
            else
                error( 'Invalid dimension: %0.2f', dim );
            end
        end
        
        %==================================================================
        % length
        %==================================================================
        function Asize = length(E)
            Asize	=   E.n;
        end
        
        %==================================================================
        % isequal
        %==================================================================
        function bool = isequal(E,F)
            % Quick checks
            bool	=	isequal( E.n, F.n )             &&	...
                        strcmpi( E.type, F.type )       &&	...
                        isequal( E.Class, F.Class );
            
            % Check actual matrices
            if bool
                bool	=	bool && isequal( E.A, F.A );
            end
        end
        
        %==================================================================
        % isfloat
        %==================================================================
        function bool = isfloat(E)
            bool	=	isfloat(E.A);
        end
        
    end
    
end

function n = handle_n_input(A,n,Asize)

if nargin < 3, Asize = [n,n]; end

if isempty( n )
    
    [m,n]	=   size(A);
    if m ~= n
        error( 'A matrix must be square.' );
    end
    
else
    
    if ( ~isscalar(n) && ~isequal(n,Asize) ) || ( isscalar(n) && ~isequal([n,n],Asize) )
        warning( 'Matrix size is different than indicated. Defaulting to actual size.' );
        n	=   Asize;
    end
    
    if ~isscalar(n) && ~( isequal( size(n), [1,2] ) && n(1) == n(2) )
        error( 'A matrix must be square.' );
    elseif ~isscalar(n)
        n	=   n(1);
    end
    
end

end

function Class = handle_Aclass_input(InputClass,Class)

if nargin < 2 || isempty(Class)
    Class       =	InputClass;
end

if isempty(InputClass)
    InputClass	=   Class;
end

if ~strcmpi( InputClass, Class )
    warning( 'Input matrix class different than actual class. Defaulting to actual class.' );
    InputClass	=   Class;
end

if ~( strcmpi(InputClass,'double') || strcmpi(InputClass,'single') )
    error( 'Unsupported class for matrix A. Must be ''double'' or ''single''.' );
end

end

function Anorm = EstimateFunctionNorm( E )

Anorm	=	-inf;
x0      =	zeros(E.n,1);
ni      =   1;

% Always at least 10 random columns sampled, and at most the max between
% the number of columns and 100 * (10000/(number of columns))
iimax	=   min( E.n, max( ceil( 10000/E.n * 100 ), 10 ) );

for ii = 1:iimax
    x0(ni)	=   0;
    ni      =   randi(E.n);
    x0(ni)	=   1;
    
    An      =	sum(abs(E.A(x0)));
    if An > Anorm
        Anorm	=	An;
    end
end

end
