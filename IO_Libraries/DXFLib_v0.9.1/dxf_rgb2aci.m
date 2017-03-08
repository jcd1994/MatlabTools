function ACI = dxf_rgb2aci(RGB)
%DXF_RGB2ACI Convert RGB color to ACI color.
%   DXF_RGB2ACI(ACI) Converts into m-by-3 RGB matrix into ACI (AutoCAD 
%   Color Index) vector. The routine tries to find RGB color that is 
%   matching best to the ACI color value.
%   
%   See also DXF_POLYLINE
%
%   Copyright 2011 Grzegorz Kwiatek
%   $Revision: 1.0.3 $  $Date: 2011.11.17 $

if size(RGB,2) ~= 3
  throw(MException('dxflib:dxf_rgb2aci','Input matrix must be m-by-3 size.'));
end

ACI = zeros(size(RGB,1),1);

TABLE = [...
1.000	0.000	0.000	;...
1.000	1.000	0.000	;...
0.000	1.000	0.000	;...
0.000	1.000	1.000	;...
0.000	0.000	1.000	;...
1.000	0.000	1.000	;...
1.000	1.000	1.000	;...
0.502	0.502	0.502	;...
0.753	0.753	0.753	;...
1.000	0.000	0.000	;...
1.000	0.500	0.500	;...
0.650	0.000	0.000	;...
0.650	0.325	0.325	;...
0.500	0.000	0.000	;...
0.500	0.250	0.250	;...
0.300	0.000	0.000	;...
0.300	0.150	0.150	;...
0.150	0.000	0.000	;...
0.150	0.075	0.075	;...
1.000	0.250	0.000	;...
1.000	0.625	0.500	;...
0.650	0.163	0.000	;...
0.650	0.406	0.325	;...
0.500	0.125	0.000	;...
0.500	0.313	0.250	;...
0.300	0.075	0.000	;...
0.300	0.188	0.150	;...
0.150	0.038	0.000	;...
0.150	0.094	0.075	;...
1.000	0.500	0.000	;...
1.000	0.750	0.500	;...
0.650	0.325	0.000	;...
0.650	0.488	0.325	;...
0.500	0.250	0.000	;...
0.500	0.375	0.250	;...
0.300	0.150	0.000	;...
0.300	0.225	0.150	;...
0.150	0.075	0.000	;...
0.150	0.113	0.075	;...
1.000	0.750	0.000	;...
1.000	0.875	0.500	;...
0.650	0.488	0.000	;...
0.650	0.569	0.325	;...
0.500	0.375	0.000	;...
0.500	0.438	0.250	;...
0.300	0.225	0.000	;...
0.300	0.263	0.150	;...
0.150	0.113	0.000	;...
0.150	0.131	0.075	;...
1.000	1.000	0.000	;...
1.000	1.000	0.500	;...
0.650	0.650	0.000	;...
0.650	0.650	0.325	;...
0.500	0.500	0.000	;...
0.500	0.500	0.250	;...
0.300	0.300	0.000	;...
0.300	0.300	0.150	;...
0.150	0.150	0.000	;...
0.150	0.150	0.075	;...
0.750	1.000	0.000	;...
0.875	1.000	0.500	;...
0.488	0.650	0.000	;...
0.569	0.650	0.325	;...
0.375	0.500	0.000	;...
0.438	0.500	0.250	;...
0.225	0.300	0.000	;...
0.263	0.300	0.150	;...
0.113	0.150	0.000	;...
0.131	0.150	0.075	;...
0.500	1.000	0.000	;...
0.750	1.000	0.500	;...
0.325	0.650	0.000	;...
0.488	0.650	0.325	;...
0.250	0.500	0.000	;...
0.375	0.500	0.250	;...
0.150	0.300	0.000	;...
0.225	0.300	0.150	;...
0.075	0.150	0.000	;...
0.113	0.150	0.075	;...
0.250	1.000	0.000	;...
0.625	1.000	0.500	;...
0.163	0.650	0.000	;...
0.406	0.650	0.325	;...
0.125	0.500	0.000	;...
0.313	0.500	0.250	;...
0.075	0.300	0.000	;...
0.188	0.300	0.150	;...
0.038	0.150	0.000	;...
0.094	0.150	0.075	;...
0.000	1.000	0.000	;...
0.500	1.000	0.500	;...
0.000	0.650	0.000	;...
0.325	0.650	0.325	;...
0.000	0.500	0.000	;...
0.250	0.500	0.250	;...
0.000	0.300	0.000	;...
0.150	0.300	0.150	;...
0.000	0.150	0.000	;...
0.075	0.150	0.075	;...
0.000	1.000	0.250	;...
0.500	1.000	0.625	;...
0.000	0.650	0.163	;...
0.325	0.650	0.406	;...
0.000	0.500	0.125	;...
0.250	0.500	0.313	;...
0.000	0.300	0.075	;...
0.150	0.300	0.188	;...
0.000	0.150	0.038	;...
0.075	0.150	0.094	;...
0.000	1.000	0.500	;...
0.500	1.000	0.750	;...
0.000	0.650	0.325	;...
0.325	0.650	0.488	;...
0.000	0.500	0.250	;...
0.250	0.500	0.375	;...
0.000	0.300	0.150	;...
0.150	0.300	0.225	;...
0.000	0.150	0.075	;...
0.075	0.150	0.113	;...
0.000	1.000	0.750	;...
0.500	1.000	0.875	;...
0.000	0.650	0.488	;...
0.325	0.650	0.569	;...
0.000	0.500	0.375	;...
0.250	0.500	0.438	;...
0.000	0.300	0.225	;...
0.150	0.300	0.263	;...
0.000	0.150	0.113	;...
0.075	0.150	0.131	;...
0.000	1.000	1.000	;...
0.500	1.000	1.000	;...
0.000	0.650	0.650	;...
0.325	0.650	0.650	;...
0.000	0.500	0.500	;...
0.250	0.500	0.500	;...
0.000	0.300	0.300	;...
0.150	0.300	0.300	;...
0.000	0.150	0.150	;...
0.075	0.150	0.150	;...
0.000	0.750	1.000	;...
0.500	0.875	1.000	;...
0.000	0.488	0.650	;...
0.325	0.569	0.650	;...
0.000	0.375	0.500	;...
0.250	0.438	0.500	;...
0.000	0.225	0.300	;...
0.150	0.263	0.300	;...
0.000	0.113	0.150	;...
0.075	0.131	0.150	;...
0.000	0.500	1.000	;...
0.500	0.750	1.000	;...
0.000	0.325	0.650	;...
0.325	0.488	0.650	;...
0.000	0.250	0.500	;...
0.250	0.375	0.500	;...
0.000	0.150	0.300	;...
0.150	0.225	0.300	;...
0.000	0.075	0.150	;...
0.075	0.113	0.150	;...
0.000	0.250	1.000	;...
0.500	0.625	1.000	;...
0.000	0.163	0.650	;...
0.325	0.406	0.650	;...
0.000	0.125	0.500	;...
0.250	0.313	0.500	;...
0.000	0.075	0.300	;...
0.150	0.188	0.300	;...
0.000	0.038	0.150	;...
0.075	0.094	0.150	;...
0.000	0.000	1.000	;...
0.500	0.500	1.000	;...
0.000	0.000	0.650	;...
0.325	0.325	0.650	;...
0.000	0.000	0.500	;...
0.250	0.250	0.500	;...
0.000	0.000	0.300	;...
0.150	0.150	0.300	;...
0.000	0.000	0.150	;...
0.075	0.075	0.150	;...
0.250	0.000	1.000	;...
0.625	0.500	1.000	;...
0.163	0.000	0.650	;...
0.406	0.325	0.650	;...
0.125	0.000	0.500	;...
0.313	0.250	0.500	;...
0.075	0.000	0.300	;...
0.188	0.150	0.300	;...
0.038	0.000	0.150	;...
0.094	0.075	0.150	;...
0.500	0.000	1.000	;...
0.750	0.500	1.000	;...
0.325	0.000	0.650	;...
0.488	0.325	0.650	;...
0.250	0.000	0.500	;...
0.375	0.250	0.500	;...
0.150	0.000	0.300	;...
0.225	0.150	0.300	;...
0.075	0.000	0.150	;...
0.113	0.075	0.150	;...
0.750	0.000	1.000	;...
0.875	0.500	1.000	;...
0.488	0.000	0.650	;...
0.569	0.325	0.650	;...
0.375	0.000	0.500	;...
0.438	0.250	0.500	;...
0.225	0.000	0.300	;...
0.263	0.150	0.300	;...
0.113	0.000	0.150	;...
0.131	0.075	0.150	;...
1.000	0.000	1.000	;...
1.000	0.500	1.000	;...
0.650	0.000	0.650	;...
0.650	0.325	0.650	;...
0.500	0.000	0.500	;...
0.500	0.250	0.500	;...
0.300	0.000	0.300	;...
0.300	0.150	0.300	;...
0.150	0.000	0.150	;...
0.150	0.075	0.150	;...
1.000	0.000	0.750	;...
1.000	0.500	0.875	;...
0.650	0.000	0.488	;...
0.650	0.325	0.569	;...
0.500	0.000	0.375	;...
0.500	0.250	0.438	;...
0.300	0.000	0.225	;...
0.300	0.150	0.263	;...
0.150	0.000	0.113	;...
0.150	0.075	0.131	;...
1.000	0.000	0.500	;...
1.000	0.500	0.750	;...
0.650	0.000	0.325	;...
0.650	0.325	0.488	;...
0.500	0.000	0.250	;...
0.500	0.250	0.375	;...
0.300	0.000	0.150	;...
0.300	0.150	0.225	;...
0.150	0.000	0.075	;...
0.150	0.075	0.113	;...
1.000	0.000	0.250	;...
1.000	0.500	0.625	;...
0.650	0.000	0.163	;...
0.650	0.325	0.406	;...
0.500	0.000	0.125	;...
0.500	0.250	0.313	;...
0.300	0.000	0.075	;...
0.300	0.150	0.188	;...
0.150	0.000	0.038	;...
0.150	0.075	0.094	;...
0.330	0.330	0.330	;...
0.464	0.464	0.464	;...
0.598	0.598	0.598	;...
0.732	0.732	0.732	;...
0.866	0.866	0.866	;...
1.000	1.000	1.000	;...
];

for i=1:size(RGB,1)
  V = repmat(RGB(i,:),size(TABLE,1),1);
  I = sum( (V-TABLE).^2,2);
  w = find(I == min(I));
  ACI(i) = w(1);
end
