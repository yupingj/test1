% slexPowerWindowPowerEffectsSim                    
%  Simulink(R) Power Window Controller and Detailed Plant Model
%  A more detailed plant model that includes power effects in the electrical and 
%  mechanical domains is used to validate that the force exerted by the window on 
%  a trapped object never exceeds 100 N. 

% Copyright 2013 The MathWorks, Inc.

mdlName = 'slexPowerWindowExample';
runDesc = 'Power Effects';

% Simulating the model
slexPowerWindowPowerEffects
simout = sim(mdlName,'SaveOutput','on', ...
                     'SaveFormat', 'StructureWithTime', ...
                     'LimitDataPoints','off', ...
                     'ReturnWorkspaceOutputs', 'on');

% Populate SDI with data from simulation
signalIDs = slexPowerWindowSDICreateRun(mdlName, runDesc, simout);

% Display signals of interest in SDI
signalObj(1) = Simulink.sdi.getSignal(signalIDs(1));
signalObj(1).checked = true;
signalObj(2) = Simulink.sdi.getSignal(signalIDs(2));
signalObj(2).checked = true;
signalObj(3) = Simulink.sdi.getSignal(signalIDs(3));
signalObj(3).checked = true;

% View in SDI
Simulink.sdi.view
