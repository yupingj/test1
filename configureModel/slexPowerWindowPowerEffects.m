% slexPowerWindowPowerEffects                     
%  Simulink(R) Power Window Controller and Detailed Plant Model
%  A more detailed plant model that includes power effects in the electrical and 
%  mechanical domains is used to validate that the force exerted by the window on
%  a trapped object never exceeds 100 N. 

% Copyright 2013 The MathWorks, Inc.

% Setting up the model
    % CV: Control Variable. 
    % The control variable value gets passed to the model variant subsystem
    % and based on the condition met, the variant subsystem activates only
    % blocks corresponding to the specified control variable value. In this
    % case, CV = 2, setting up the model to the Detailed Plant Model
    % Configuration.

CV = 2;
slexPowerWindowInitialization
