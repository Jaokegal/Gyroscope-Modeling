clear
clc

%Identified Parameters
K=
tau=
Kg=1/5.2;

%=====================================
Mp1=0.05;
tp1=0.1;

% Get D and omega of corresponding PT2 System



% Get Kp and Ki by comparing with PT2 system parameters


% Define the tranfser function

G1=

%===========================================

Mp2=0.05;
tp2=0.2;


% Get D and omega of corresponding PT2 System



% Get Kp and Ki by comparing with PT2 system parameters


% Define the tranfser function

G2=

%===========================================
Mp3=0.1;
tp3=0.2;

% Get D and omega of corresponding PT2 System



% Get Kp and Ki by comparing with PT2 system parameters


% Define the tranfser function

G3=

%===========================================
%===========================================

%plot and comparison
figure(1)
hold on
step(G1)
step(G2)
step(G3)
legend('case1','case2','case3')