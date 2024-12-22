function error=ModelEvaluation1(K,tau,v_m,dot_theta_l)
T=0.002;
Y = dot_theta_l;
PHI = [Y(1:end-1),v_m(1:end-1)];

e = Y(2:end) - PHI * [1-T/tau; K*T/tau];
error = norm(e);
