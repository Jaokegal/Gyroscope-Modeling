function error=ModelEvaluation2(K,D,omega,v_m,dot_theta_l)

%%Use DateB to evaluate your identified model:
%P(s)=K/(s(s^2+Ds+w^2))

%%input_argument:
%K, D and omega: the estimates of the model parameters
%v_m: input voltage to the servo (unit: v) from DataB
%dot_theta_l: angular speed of the servo (unit: rad/s) from DataB


%%output_argument:
%2-norm of the fitting residual vectors


%the sampling time T of the AD-DA converter is: 0.002 sec.
T=0.002;

%%%%%Please complete the following codes %%%%%%%%%%%%%%%%
