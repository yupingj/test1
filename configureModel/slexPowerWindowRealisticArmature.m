% slexPowerWindowRealisticArmature                     
%  Simulink(R) Power Window Controller With Data Acquisition Effects
%  In moving to an implementation, additional effects that may affect the control 
%  have to be accounted for. This model includes phenomena such as signal 
%  conditioning to measure the armature current and quantization of the measurement. 

% Copyright 2013 The MathWorks, Inc.

% Setting up the model
    % CV: Control Variable. 
    % The control variable value gets passed to the model variant subsystem
    % and based on the condition met, the variant subsystem activates only
    % blocks corresponding to the specified control variable value. In this
    % case, CV = 4, setting up the model to the Data Acquisition Effects
    % Configuration.

CV = 4;
slexPowerWindowInitialization
