function signalIDs = slexPowerWindowSDICreateRun( mdlName, runDesc, simout )
% SLEXPOWERWINDOWSDICREATERUN Create run in open Simulation Data Inspector
%  This is a helper function for Power Window Controller Project tasks.  
%  It is not meant to be called directly.

% Copyright 2013 The MathWorks, Inc.

signalIDs = [];

try
    % populate SDI if there is any data
    if ~isempty(simout.get)
        sdiEngine = Simulink.sdi.Instance.engine;
        
        % construct run name
        dataRunName = ['Run' ' <run_index> : <time_stamp> : ' mdlName ' : ' runDesc];
        [~, ~, signalIDs] = sdiEngine.createRun(dataRunName,'namevalue',{'simout'}, {simout});
    end
catch
    % do not interrupt if SDI fails
end
