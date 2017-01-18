% slexPowerWindowContinuousSim                     
%  Simulink(R) Power Window Controller Hybrid System Model
%  This model demonstrates the use of Stateflow(R) in conjunction with Simulink 
%  to model both discrete event reactive behavior and continuous time behavior. 
%  A low order plant model is used to validate the roll-up and roll-down behavior. 

% Copyright 2013 The MathWorks, Inc.

mdlName = 'slexPowerWindowExample';
runDesc = 'Continuous';

% Simulating the model
slexPowerWindowContinuous
simout = sim(mdlName,'SaveOutput','on', ...
                     'SaveFormat', 'StructureWithTime', ...
                     'LimitDataPoints','off', ...
                     'InspectSignalLogs','on', ...
                     'ReturnWorkspaceOutputs', 'on');

% Populate SDI with data from simulation
signalIDs = slexPowerWindowSDICreateRun(mdlName, runDesc, simout);

% Display signals of interest in SDI
signalObj = Simulink.sdi.getSignal(signalIDs(3));
signalObj.checked = true;

% View in SDI
Simulink.sdi.view


