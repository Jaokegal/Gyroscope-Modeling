clear
clc

%This program is to realize the synthesis of the H infinity control system
%for the gyro system. Particaully, here, we perform the synthesis in a
%tuning ways, the main function to be used here is the hinfstruct

%please use the Matlab function hinfstruct to complete the following codes:

%Identified parameters
Kg=1/5.2;
K=1.5519;
tau=0.0547;


%build a tunable close-loop model
Kp=realp('Kp',1);
Kp.Minimum=0.8696;
Kp.Maximum=10.9896;

Ki=realp('Ki',150);
Ki.Minimum=69.5177;
Ki.Maximum=461.3930;


G=tf([tau, 1, 0],[tau,(K*Kg*Kp+1),K*Ki*Kg]);
G.InputName='x';
G.OutputName='y';

%H infinity norm of the turned system
[CL, gamma, info]=hinfstruct(G);

%tunned values for the parameters
tKp=CL.Blocks.Kp
tKi=CL.Blocks.Ki

%Validate the Controller Design
cl_tf = getIOTransfer(CL,'x','y');

%step response
step(cl_tf)