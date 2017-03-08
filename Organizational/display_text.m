function new_msg = display_text( msg, line_width, break_char, is_centered, addspace )
%DISPLAY_TEXT Displays the (potentially very long) string msg such that the
% maximum line length width is line_width. Optionally the message can be
% padded with strings of break_char's or be centered.

if nargin < 5 || isempty(addspace)
    addspace	=	[0,0];
elseif isscalar(addspace)
    addspace	=   round( addspace );
    if addspace < 0,    addspace	=   [ abs(addspace), 0 ];
    else                addspace	=   [ 0, addspace ];
    end
end

msg	=	format_text( msg, line_width, break_char, is_centered );

fprintf( repmat( '\n', 1, round(abs(addspace(1))) ) );

for ii = 1:length(msg)
    fprintf(msg{ii});
end

fprintf( repmat( '\n', 1, round(abs(addspace(2))) ) );

if nargout > 0
    new_msg	=	msg;
end

end

