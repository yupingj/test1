% slexPowerWindowRealisticArmatureSim                    
%  Simulink(R) Power Window Controller With Data Acquisition Effects
%  In moving to an implementation, additional effects that may affect the control 
%  have to be accounted for. This model includes phenomena such as signal 
%  conditioning to measure the armature current and quantization of the measurement. 

% Copyright 2013 The MathWorks, Inc.

mdlName = 'slexPowerWindowExample';
runDesc = 'Realistic Armature';

% Simulating the model
slexPowerWindowRealisticArmature
simout = sim(mdlName,'SaveOutput','on', ...
                     'SaveFormat', 'StructureWithTime', ...
                     'LimitDataPoints','off', ...
                     'InspectSignalLogs','on', ...
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
