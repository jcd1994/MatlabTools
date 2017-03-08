function [] = GUI_12()
% Demonstrate how to control the mouse pointer from a GUI.
% Just for fun, show how to manipulate the mouse pointer.  To close the 
% figure, use the regular window x in the upper right corner.
% Note, I have had reports that nothing happens when this is run on Mac
% computers.
%
% Author:  Matt Fig
% Date:  7/15/2009

S.fh = figure('units','pixels',...
              'position',[300 300 300 160],...
              'menubar','none',...
              'name','GUI_12',...
              'numbertitle','off',...
              'resize','off');
S.UN = get(0,'units');  % We need to temporarily change this.
S.pb = uicontrol('style','push',...
                 'units','pix',...
                 'position',[20 30 260 100],...
                 'string', 'Push Me To Close Figure',...
                 'fontsize',12,'fontweight','bold',...
                 'callback',{@pb_call,S});
set(S.fh,'WindowButtonMotionFcn',{@fh_wbmf,S})          



function [] = fh_wbmf(varargin)
S = varargin{3};  % Get the structure.
set(0,'units','normalized') % Temporary, see below.
% Move the mouse pointer to a random position.
set(0, 'PointerLocation', [rand rand])  
set(0,'units',S.UN)  % Undo change to user's system.  Good courtesy.