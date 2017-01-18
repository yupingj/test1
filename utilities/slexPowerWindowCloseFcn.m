% slexPowerWindowCloseFcn CloseFcn for slexPowerWindowExample
%  This is a helper function for Power Window Controller Project main model.  
%  It is not meant to be called directly.

% Copyright 2013 The MathWorks, Inc.

try
    % clear and close the GUI just in case it is open
    Simulink.sdi.clear;
    Simulink.sdi.close;
catch
    % do not interrupt if SDI fails
end
