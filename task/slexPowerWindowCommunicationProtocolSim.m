% slexPowerWindowCommunicationProtocolSim                
%  Simulink(R) Power Window Controller With CAN Communication
%  The commands to control window movement are typically communicated over 
%  a controller area network (CAN). In this model, the switches that may 
%  be located in the center console of the vehicle and that produce the 
%  commands are included. 

% Copyright 2013 The MathWorks, Inc.

mdlName = 'slexPowerWindowExample';
runDesc = 'Communication Protcol';

% Simulating the model
slexPowerWindowCommunicationProtocol
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
