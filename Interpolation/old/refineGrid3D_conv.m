function [ Vk ] = refineGrid3D_conv( V, K )
%REFINEGRID3D_CONV Returns the interpolated values on a refined grid formed
% by repeatedly dividing the intervals K times in each dimension.

Vk	=   V;
for k = 1:K
    Vk	=   refineGrid3D_conv_Once( Vk );
end

end

function Vk	=   refineGrid3D_conv_Once( V )

Vsize	=   size(V);
Vksize	=   2*Vsize-1 + 4;

Vk	=   zeros( Vksize, 'single' );

% insert inner values
Vk( 3:2:end-2, 3:2:end-2, 3:2:end-2 )	=   V;

% pad sides with inside values
Vk( [1,end],   3:2:end-2, 3:2:end-2 )	=   V([1,end],:,:);
Vk( 3:2:end-2, [1,end],   3:2:end-2 )	=   V(:,[1,end],:);
Vk( 3:2:end-2, 3:2:end-2, [1,end]   )	=	V(:,:,[1,end]);

% pad edges with inside values
Vk( [1,end],   [1,end],   3:2:end-2 )	=   V([1,end],[1,end],:);
Vk( [1,end],   3:2:end-2, [1,end]   )	=   V([1,end],:,[1,end]);
Vk( 3:2:end-2, [1,end],   [1,end]   )	=   V(:,[1,end],[1,end]);

% pad corners with inside values
Vk( [1,end],   [1,end],   [1,end]   )   =   V([1,end],[1,end],[1,end]);

for ii = 3:2:Vksize(1)-2
    for jj = 3:2:Vksize(2)-2
        for kk = 3:2:Vksize(3)-2
            
            %==============================================================
            % 6 Close Neighbours
            %==============================================================
                        
            Vkhalf      =   0.5 * Vk(ii,jj,kk);
            
            Vk(ii-1,jj  ,kk  )	=   Vkhalf + 0.5 * Vk(ii-2,jj  ,kk  );
            Vk(ii+1,jj  ,kk  )	=   Vkhalf + 0.5 * Vk(ii+2,jj  ,kk  );
            Vk(ii  ,jj-1,kk  )	=   Vkhalf + 0.5 * Vk(ii  ,jj-2,kk  );
            Vk(ii  ,jj+1,kk  )	=   Vkhalf + 0.5 * Vk(ii  ,jj+2,kk  );
            Vk(ii  ,jj  ,kk-1)	=   Vkhalf + 0.5 * Vk(ii  ,jj  ,kk-2);
            Vk(ii  ,jj  ,kk+1)	=   Vkhalf + 0.5 * Vk(ii  ,jj  ,kk+2);
            
            %==============================================================
            % 12 Intermediate Neighbours
            %==============================================================
            
            Vkquart     =   0.5 * Vkhalf;
            
            Vk(ii-1,jj-1,kk  )	=   Vkquart + ...
                0.25 * Vk(ii-2,jj  ,kk  ) + 0.25 * Vk(ii-2,jj-2,kk  ) + 0.25 * Vk(ii  ,jj-2,kk  );
            Vk(ii+1,jj-1,kk  )	=   Vkquart + ...
                0.25 * Vk(ii+2,jj  ,kk  ) + 0.25 * Vk(ii+2,jj-2,kk  ) + 0.25 * Vk(ii  ,jj-2,kk  );
            Vk(ii-1,jj+1,kk  )	=   Vkquart + ...
                0.25 * Vk(ii-2,jj  ,kk  ) + 0.25 * Vk(ii-2,jj+2,kk  ) + 0.25 * Vk(ii  ,jj+2,kk  );
            Vk(ii+1,jj+1,kk  )	=   Vkquart + ...
                0.25 * Vk(ii+2,jj  ,kk  ) + 0.25 * Vk(ii+2,jj+2,kk  ) + 0.25 * Vk(ii  ,jj+2,kk  );
            
            Vk(ii-1,jj  ,kk-1)	=   Vkquart + ...
                0.25 * Vk(ii-2,jj  ,kk  ) + 0.25 * Vk(ii-2,jj  ,kk-2) + 0.25 * Vk(ii  ,jj  ,kk-2);
            Vk(ii+1,jj  ,kk-1)	=   Vkquart + ...
                0.25 * Vk(ii+2,jj  ,kk  ) + 0.25 * Vk(ii+2,jj  ,kk-2) + 0.25 * Vk(ii  ,jj  ,kk-2);
            Vk(ii-1,jj  ,kk+1)	=   Vkquart + ...
                0.25 * Vk(ii-2,jj  ,kk  ) + 0.25 * Vk(ii-2,jj  ,kk+2) + 0.25 * Vk(ii  ,jj  ,kk+2);
            Vk(ii+1,jj  ,kk+1)	=   Vkquart + ...
                0.25 * Vk(ii+2,jj  ,kk  ) + 0.25 * Vk(ii+2,jj  ,kk+2) + 0.25 * Vk(ii  ,jj  ,kk+2);
            
            Vk(ii  ,jj-1,kk-1)	=   Vkquart + ...
                0.25 * Vk(ii  ,jj-2,kk  ) + 0.25 * Vk(ii  ,jj-2,kk-2) + 0.25 * Vk(ii  ,jj  ,kk-2);
            Vk(ii  ,jj+1,kk-1)	=   Vkquart + ...
                0.25 * Vk(ii  ,jj+2,kk  ) + 0.25 * Vk(ii  ,jj+2,kk-2) + 0.25 * Vk(ii  ,jj  ,kk-2);
            Vk(ii  ,jj-1,kk+1)	=   Vkquart + ...
                0.25 * Vk(ii  ,jj-2,kk  ) + 0.25 * Vk(ii  ,jj-2,kk+2) + 0.25 * Vk(ii  ,jj  ,kk+2);
            Vk(ii  ,jj+1,kk+1)	=   Vkquart + ...
                0.25 * Vk(ii  ,jj+2,kk  ) + 0.25 * Vk(ii  ,jj+2,kk+2) + 0.25 * Vk(ii  ,jj  ,kk+2);
            
            %==============================================================
            % 8 Furthest Neighbours
            %==============================================================
            
            Vkeighth	=   0.5 * Vkquart;
            
            Vk(ii-1,jj-1,kk-1)	=   Vkeighth + ...
                0.125 * Vk(ii-2,jj  ,kk  ) + 0.125 * Vk(ii-2,jj-2,kk  ) + 0.125 * Vk(ii  ,jj-2,kk  ) + ...
                0.125 * Vk(ii-2,jj  ,kk-2) + 0.125 * Vk(ii-2,jj-2,kk-2) + 0.125 * Vk(ii  ,jj-2,kk-2) + 0.125 * Vk(ii  ,jj  ,kk-2);
            Vk(ii+1,jj-1,kk-1)	=   Vkeighth + ...
                0.125 * Vk(ii+2,jj  ,kk  ) + 0.125 * Vk(ii+2,jj-2,kk  ) + 0.125 * Vk(ii  ,jj-2,kk  ) + ...
                0.125 * Vk(ii+2,jj  ,kk-2) + 0.125 * Vk(ii+2,jj-2,kk-2) + 0.125 * Vk(ii  ,jj-2,kk-2) + 0.125 * Vk(ii  ,jj  ,kk-2);
            Vk(ii-1,jj+1,kk-1)	=   Vkeighth + ...
                0.125 * Vk(ii-2,jj  ,kk  ) + 0.125 * Vk(ii-2,jj+2,kk  ) + 0.125 * Vk(ii  ,jj+2,kk  ) + ...
                0.125 * Vk(ii-2,jj  ,kk-2) + 0.125 * Vk(ii-2,jj+2,kk-2) + 0.125 * Vk(ii  ,jj+2,kk-2) + 0.125 * Vk(ii  ,jj  ,kk-2);
            Vk(ii+1,jj+1,kk-1)	=   Vkeighth + ...
                0.125 * Vk(ii+2,jj  ,kk  ) + 0.125 * Vk(ii+2,jj+2,kk  ) + 0.125 * Vk(ii  ,jj+2,kk  ) + ...
                0.125 * Vk(ii+2,jj  ,kk-2) + 0.125 * Vk(ii+2,jj+2,kk-2) + 0.125 * Vk(ii  ,jj+2,kk-2) + 0.125 * Vk(ii  ,jj  ,kk-2);
            Vk(ii-1,jj-1,kk+1)	=   Vkeighth + ...
                0.125 * Vk(ii-2,jj  ,kk  ) + 0.125 * Vk(ii-2,jj-2,kk  ) + 0.125 * Vk(ii  ,jj-2,kk  ) + ...
                0.125 * Vk(ii-2,jj  ,kk+2) + 0.125 * Vk(ii-2,jj-2,kk+2) + 0.125 * Vk(ii  ,jj-2,kk+2) + 0.125 * Vk(ii  ,jj  ,kk+2);
            Vk(ii+1,jj-1,kk+1)	=   Vkeighth + ...
                0.125 * Vk(ii+2,jj  ,kk  ) + 0.125 * Vk(ii+2,jj-2,kk  ) + 0.125 * Vk(ii  ,jj-2,kk  ) + ...
                0.125 * Vk(ii+2,jj  ,kk+2) + 0.125 * Vk(ii+2,jj-2,kk+2) + 0.125 * Vk(ii  ,jj-2,kk+2) + 0.125 * Vk(ii  ,jj  ,kk+2);
            Vk(ii-1,jj+1,kk+1)	=   Vkeighth + ...
                0.125 * Vk(ii-2,jj  ,kk  ) + 0.125 * Vk(ii-2,jj+2,kk  ) + 0.125 * Vk(ii  ,jj+2,kk  ) + ...
                0.125 * Vk(ii-2,jj  ,kk+2) + 0.125 * Vk(ii-2,jj+2,kk+2) + 0.125 * Vk(ii  ,jj+2,kk+2) + 0.125 * Vk(ii  ,jj  ,kk+2);
            Vk(ii+1,jj+1,kk+1)	=   Vkeighth + ...
                0.125 * Vk(ii+2,jj  ,kk  ) + 0.125 * Vk(ii+2,jj+2,kk  ) + 0.125 * Vk(ii  ,jj+2,kk  ) + ...
                0.125 * Vk(ii+2,jj  ,kk+2) + 0.125 * Vk(ii+2,jj+2,kk+2) + 0.125 * Vk(ii  ,jj+2,kk+2) + 0.125 * Vk(ii  ,jj  ,kk+2);
            
        end
    end
end

% Crop Vk to 2*size(V)-1
Vk	=   Vk(3:end-2,3:end-2,3:end-2);

end

%==========================================================================
% MEX Build Script
%==========================================================================
%{

InitialVars     =	whos;
InitialVarNames	=	{InitialVars.name};

SINGLE	=   zeros(1,'single');
DOUBLE	=   zeros(1,'double');
FUNC	=   'refineGrid3D_conv';
ARGS	=	{	coder.typeof( SINGLE, [512,512,512],	[1,1,1] ),	...
                coder.typeof( DOUBLE, [1,1],            [0,0]	)	};

CurrentDirectory	=   cd;
goto(FUNC), codegen refineGrid3D_conv -args ARGS
cd(CurrentDirectory)

fprintf( 'Code generation completed for:\t%s\n', FUNC );
clearvars('-except',InitialVarNames{:});

%}