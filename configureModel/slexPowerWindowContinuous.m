% slexPowerWindowContinuous                       
%  Simulink(R) Power Window Controller Hybrid System Model
%  This model demonstrates the use of Stateflow(R) in conjunction with Simulink to
%  model both discrete event reactive behavior and continuous time behavior. A low 
%  order plant model is used to validate the roll-up and roll-down behavior. 

% Copyright 2013 The MathWorks, Inc.

% Setting up the model
    % CV: Control Variable. 
    % The control variable value gets passed to the model variant subsystem
    % and based on the condition met, the variant subsystem activates only
    % blocks corresponding to the specified control variable value. In this
    % case, CV = 1, setting up the model to the Hybrid System Model
    % Configuration.

CV = 1;
slexPowerWindowInitialization


