% slexPowerWindowInitialization
%  This is a helper function for Power Window Controller Project model 
%  configuration scripts. Configures the project based on the control variable 
%  passed to it. It is not meant to be called directly.

% Copyright 2013 The MathWorks, Inc.

%==========================%
% Configuration Definition %
%==========================%
%
% 1. 1st Configuration:
%       Simulink(R) Power Window Controller Hybrid System Model
%           This model demonstrates the use of Stateflow(R) in conjunction
%           with Simulink to model both discrete event reactive behavior 
%           and continuous time behavior. A low order plant model is used 
%           to validate the roll-up and roll-down behavior. 
% 2. 2nd Configuration:
%       Simulink(R) Power Window Controller and Detailed Plant Model
%           A more detailed plant model that includes power effects in the 
%           electrical and mechanical domains is used to validate that the 
%           force exerted by the window on a trapped object never exceeds 
%           100 [N]. 
% 3. 3rd Configuration:
%       Simulink(R) Power Window Controller with VRML Visualization 
%           A virtual reality representation of the window lift-mechanism 
%           allows studying the geometry of the design in combination with 
%           its modeled dynamics.
% 4. 4th Configuration:
%       Simulink(R) Power Window Controller With Data Acquisition Effects
%           In moving to an implementation, additional effects that may 
%           affect the control have to be accounted for. This model includes
%           phenomena such as signal conditioning to measure the armature 
%           current and quantization of the measurement. 
% 5. 5th Configuration:
%       Simulink(R) Power Window Controller With CAN Communication
%           The commands to control window movement are typically 
%           communicated over a controller area network (CAN). In this model,
%           the switches that may be located in the center console of the 
%           vehicle and that produce the commands are included. 
%
%================%
% Initialization %
%================%
%
%=========================================================================%
% Setting all condition variables to false "0" so none of the variant     %
% subsystem blocks is activated when you open the model.                   %
%=========================================================================%
%
DPS   = 0;                   % Driver & Passenger Switch
PW1   = 0;                   % PowerWindow Configuration 1
PW23  = 0;                   % PowerWindow Configuration 2&3
PW45  = 0;                   % PowerWindow Configuration 4&5
DO2   = 0;                   % Detecting Obstacles Configuration 2
DO3   = 0;                   % Detecting Obstacles Configuration 3
SL3D  = 0;                   % Window World Display
%
%==================================%
% Driver Switch & Passenger Switch %
%==================================%
%
%=========================================================================%
% Since the driver and switch blocks are the same for Configuration 1-4   %
% and only different for Configuration 5, two control variables were made.%
% V1234: The control variable for Configuration 1-4                       %
% V5   : The control variable for Configuration 5                         %
% When the user selects a Configuration number between 1-4, the condition %
% variable DPS gets changed to true "1" hence activating V1234. On the    %
% other hand, if Configuration 5 is selected, DPS remains 0 allowing the  % 
% V5 to be activated instead.                                             %
%=========================================================================%
%
if CV == 1 || CV == 2 || CV == 3 || CV == 4
    DPS  = 1;
end
V1234 = Simulink.Variant('DPS == 1');
V5    = Simulink.Variant('DPS == 0');
%
%======================%
% Window System Switch %
%======================%
%
%=========================================================================%
% The window system switch block has three different categories:          %
% Configuration 1 has a unique block, Configuration 2 & 3 share the same  %
% block, Configuration 4 & 5 share the same block.                        %
% V1  : The control variable for Configuration 1                          %
% V23 : The control variable for Configuration 2 & 3                      %
% V45 : The control variable for Configuration 4 & 5                      %
% When the user selects Configuration 1, the condition variable PW1 gets  %
% changed to 1 hence activating V1. Similarly, when the user selects      %
% Configuration 2&3 or 4&5, PW23 or PW45 gets changed to 1 activating V23 %
% or V45, respectively.                                                   %
%=========================================================================%
%
if CV == 1 
    PW1  = 1;
end
if CV == 2 || CV == 3
    PW23  = 1;
end
if CV == 4 || CV == 5
    PW45  = 1;
end
V1  = Simulink.Variant('PW1 == 1');
V23 = Simulink.Variant('PW23 == 1');
V45 = Simulink.Variant('PW45 == 1');
%
%===========================%
% Obstacle Detection System %
%===========================%
%
%=========================================================================%
% The obstacle detection system block has 4 different categories:         %
% Configurations 1,2,3 have a unique block each while Configuration 4 & 5 %
% share the same block. Since one can determine if the user had           %
% selected Configuration 1,4,5 from earlier parts in the code, it is only %
% needed to introduce variants for Configuration 2 & 3.                   %
% V2: The control variable for Configuration 2                            %
% V3: The control variable for Configuration 3                            %
% When the user selects Configuration 2 or 3, the condition variable DO2  %
% or DO3 gets changed to 1 hence activating V2 or V3, respectively.       %
%=========================================================================%
%
if CV == 2
    DO2  = 1;
end
if CV == 3
    DO3  = 1;
end
V2  = Simulink.Variant('DO2 == 1');
V3  = Simulink.Variant('DO3 == 1');

%
%======================%
% Window World Display %
%======================%
%
%=========================================================================%
% The window world block has 2 different categories:                      %
% Simulink(R) 3D Animation(TM) is or is not available.                    %
% If a license of Simulink 3D Animation is available, then the VRML       %
% visualization will be shown.                                            %
% V0:     The control variable for no Simulink 3D Animation license       %
% V12345: The control variable for Simulink 3D Animation license          %
% When the user selects Configuration 2 or 3, the condition variable DO2  %
% or DO3 gets changed to 1 hence activating V2 or V3, respectively.       %
%=========================================================================%

if license('test','virtual_reality_toolbox')
    SL3D = 1;

end
V0      = Simulink.Variant('SL3D == 0');
V12345  = Simulink.Variant('SL3D == 1');

% Open main model and set solver
sysName = 'slexPowerWindowExample';

if isempty(find_system(sysName,'flat'))
    open_system(sysName)
end

if CV == 1
    set_param(sysName,'Solver','ode23')
else
    set_param(sysName,'Solver','ode23tb')
end

% remove dirty flag
set_param(sysName,'Dirty','off')
