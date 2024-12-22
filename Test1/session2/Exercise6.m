clear
clc

%Identified Parameters
K= 1.5519;
tau= 0.0547;
Kg=1/5.2;

%=====================================
Mp1=0.05;
tp1=0.1;

% Get D and omega of corresponding PT2 System
D1 = abs(log(Mp1))/(sqrt((log(Mp1))^2 + pi^2));
omega1 = pi/(tp1*sqrt(1-D1^2));


% Get Kp and Ki by comparing with PT2 system parameters
Ki1 = omega1^2*tau/(K*Kg);
Kp1 = (2*D1*omega1*tau-1)/(K*Kg);

% Define the tranfser function


G1= tf([tau, 1, 0],[tau, (K*Kp1*Kg+1), (K*Ki1*Kg)]);
%===========================================

Mp2=0.05;
tp2=0.2;


% Get D and omega of corresponding PT2 System
D2 = abs(log(Mp2))/(sqrt((log(Mp2))^2 + pi^2));
omega2 = pi/(tp2*sqrt(1-D2^2));


% Get Kp and Ki by comparing with PT2 system parameters
Ki2 = omega2^2*tau/(K*Kg);
Kp2 = (2*D2*omega2*tau-1)/(K*Kg);

% Define the tranfser function


G2=tf([tau, 1, 0],[tau, (K*Kp2*Kg + 1), (K*Ki2*Kg)]);

%===========================================
Mp3=0.1;
tp3=0.2;

% Get D and omega of corresponding PT2 System
D3 = abs(log(Mp3))/(sqrt((log(Mp3))^2 + pi^2));
omega3 = pi/(tp3*sqrt(1-D3^2));


% Get Kp and Ki by comparing with PT2 system parameters
Ki3 = omega3^2*tau/(K*Kg);
Kp3 = (2*D3*omega3*tau-1)/(K*Kg);

% Define the tranfser function

G3=tf([tau, 1, 0],[tau, (K*Kp3*Kg + 1), (K*Ki3*Kg)]);

%===========================================
%===========================================

%plot and comparison 
figure(1)
hold on
step(G1)
step(G2)
step(G3)
legend('case1','case2','case3')