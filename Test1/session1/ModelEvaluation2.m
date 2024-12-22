function error=ModelEvaluation2(K,D,omega,v_m,dot_theta_l)

T=0.002;

Y = dot_theta_l;
PHI = [Y(2:end-1),Y(1:end-2),v_m(1:end-2)];

p1 = -2*D*omega*T +2;
p2 = -1+2*D*omega*T-(omega^2*T^2);
p3 = (K*T^2);

e = Y(3:end) - PHI * [p1;p2;p3];
error = norm(e);

