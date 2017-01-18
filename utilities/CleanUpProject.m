function CleanUpProject()
% CleanUpProject   Clean up local customizations of the environment
%   Clean up the environment for the current project. This function undoes
%   the settings applied in "SetUpProject". It is set to Run at Shutdown.

%   Copyright 2013 The MathWorks, Inc.

% Use Simulink Project API to get the current project:
p = slproject.getCurrentProject;

% Get the project root folder:
projectRoot = p.RootFolder;

% Remove paths added for this project. Get the single definition of the
% folders to add to the path:
folders = ProjectPaths();

% Remove these from the MATLAB path:
for jj=1:numel(folders)
    rmpath( fullfile(projectRoot, folders{jj}) );
end

% Reset the location where generated code and other temporary files are
% created (slprj) to the default:
Simulink.fileGenControl('reset');

% Close top level model in case is open
sys = 'slexPowerWindowExample';
if bdIsLoaded(sys)
    close_system(sys);
end

% Close supporting library and clear variables if closing main model
if ~bdIsLoaded(sys)
    saLib = 'slexPowerWindowSALib';
    if bdIsLoaded(saLib)
        close_system(saLib);
    end
    evalin('base','clear(''SL3DBlock'', ''SL3D'', ''CV'', ''DO2'', ''DO3'', ''DPS'')');
    evalin('base','clear(''sysName'', ''PW1'', ''PW23'',''PW45'', ''V1234'', ''V12345'')');    
    evalin('base','clear(''V0'', ''V1'', ''V2'', ''V23'', ''V3'', ''V45'', ''V5'')');    
end

