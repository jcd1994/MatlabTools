function setdefaultfigprops
%SETDEFAULTFIGPROPS Sets global figure properties for nice default plots.

%Default Figure properties
set(groot,'defaultFigureWindowStyle','docked');
set(groot,'defaultFigureColor','white');

%Default Text properties
set(groot,'defaultTextInterpreter','latex');

%Default Axes properties
set(groot,'defaultAxesTickLabelInterpreter','latex');
set(groot,'defaultAxesFontSize',16);
set(groot,'defaultAxesXGrid','on');
set(groot,'defaultAxesYGrid','on');
set(groot,'defaultAxesXMinorTick','on');
set(groot,'defaultAxesYMinorTick','on');

%Default Line properties
set(groot,'defaultLineLineWidth',3);

%Default Legend properties
set(groot,'defaultLegendInterpreter','latex');
set(groot,'defaultLegendFontSize',16);

%Default Colorbar properties
set(groot,'defaultColorbarTickLabelInterpreter','latex');
set(groot,'defaultColorbarFontSize',16);

end

