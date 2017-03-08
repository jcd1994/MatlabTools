function angle = angle3D( vec1, vec2, dim, isDegrees )
% ANGLE3D Returns the smallest angle between the
% three dimensional vectors vec1 and vec2
% 
% NOTE: angle is returned in radians, unless isDegrees is true

if nargin < 3
    dim	=   find( size(vec1) == 3, true, 'first' );
end

angle	=	atan2(  norm( cross( vec1, vec2, dim ) ),  ...
                    dot( vec1, vec2, dim )	);

if nargin > 3 && isDegrees
    angle = 180/pi * angle;
end

end

