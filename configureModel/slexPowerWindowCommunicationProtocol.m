% slexPowerWindowCommunicationProtocol                    
%  Simulink(R) Power Window Controller With CAN Communication
%  The commands to control window movement are typically communicated over 
%  a controller area network (CAN). In this model, the switches that may 
%  be located in the center console of the vehicle and that produce the 
%  commands are included. 

% Copyright 2013 The MathWorks, Inc.

% Setting up the model
    % CV: Control Variable. 
    % The control variable value gets passed to the model variant subsystem
    % and based on the condition met, the variant subsystem activates only
    % blocks corresponding to the specified control variable value. In this
    % case, CV = 5, setting up the model to the CAN Communication
    % Configuration.
    
if ~ispc
   errordlg(getString(message('simdemos:slexPowerWindow:InvalidOperatingSystem')),...
            getString(message('simdemos:slexPowerWindow:InvalidOperatingSystemTitle')));
   break;
end
CV = 5;
slexPowerWindowInitialization
