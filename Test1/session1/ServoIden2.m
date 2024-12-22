function [K,D,omega]=ServoIden2(v_m,dot_theta_l)

T=0.002;

Y = dot_theta_l(3:end);
Phi = [dot_theta_l(2:end-1), dot_theta_l(1:end-2), v_m(1:end-2)];

theta = inv(Phi'*Phi)*Phi'*Y;

K = theta(3)/T^2;

omega = sqrt(-theta(1)-theta(2)+1)/T;

D = (2-theta(1))/(2*sqrt(1-theta(1)-theta(2)));






