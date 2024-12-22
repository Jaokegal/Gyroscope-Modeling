function [K,tau]=ServoIden1(v_m,dot_theta_1)

%%First-order transfer function identification for the servo unit:
%%P(s)=K/(s(tau*s+1));

%%input_argument from DataA:
%v_m: input voltage to the servo (unit: v)
%dot_theta_l: angular speed of the servo (unit: rad/s)

%%output_argument:
%K,tau: transfer function parameters



%the sampling time T of the AD-DA converter is: 0.002 sec.
T=0.002;

%kind reminder: dot(y)=( y(t+1) - y(t) )/T
%kind reminder: dot(dot(y))=( y(t+2) + y(t) -2*y(t+1) )/ T^2

%%%%%Please complete the following codes for least-squires estimation%%%%%%%%






