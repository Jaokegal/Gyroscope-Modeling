clear
clc

%Identified Parameters
K=;
tau=;
Kg=1/5.2;

%range of Mp 0.02~0.1
Mp_max=0.1;
Mp_min=0.02;

%range of D
D_max=abs(log(Mp_min))/sqrt((log(Mp_min))^2+pi^2);
D_min=abs(log(Mp_max))/sqrt((log(Mp_max))^2+pi^2);

%range of tp 0.1-0.2
tp_max=0.2;
tp_min=0.1;

%range of omega
omega_max=pi/(tp_min*(sqrt(1-D_max^2)));
omega_min=pi/(tp_max*(sqrt(1-D_min^2)));


%range of Ki
Ki_max=(omega_max^2*tau)/(K*Kg)
Ki_min=(omega_min^2*tau)/(K*Kg)

%range of Kp
Kp_max=(tau*2*D_max*omega_max-1)/(K*Kg)
Kp_min=(tau*2*D_min*omega_min-1)/(K*Kg)

