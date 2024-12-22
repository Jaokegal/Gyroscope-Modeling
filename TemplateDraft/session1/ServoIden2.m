function [K,D,omega]=ServoIden2(v_m,dot_theta_l)

%second-order transfer function identification for the servo unit:
%P(s)=K/(s(s^2+Ds+w^2))

%input_argument:
%v_m: input voltage to the servo (unit: v) from DataA
%dot_theta_l: angular speed of the servo (unit: rad/s) from DataA

%output_argument:
%K,tau, omega: transfer function parameters

%the sampling time T of the AD-DA converter is: 0.002 sec.
T=0.002;

%kind reminder: dot(y)=( y(t+1) - y(t) )/T
%kind reminder: dot(dot(y))=( y(t+2) + y(t) -2*y(t+1) )/ T^2











