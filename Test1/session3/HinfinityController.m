clear
clc

%set the weighting funciton parameters
a=0.001;
b=1;
H=1;

%system parameters
K=1.5519
tau=0.0547
Kg=1/5.2;
 
%generalized platform representation
A=[-1/tau 0  0;
    1     0  0;
    0     H  -a];
B1=[0;
    0;
    H];
B2=[K/tau;
    0;
    0];
C1=[0 0 1;
    0 0 1e-6];
C2=[0 Kg 0];
D11=[0;
    0];
D12=[0;
    b];
D21=Kg;
D22=0;


B=[B1 B2];
C=[C1;
    C2];
D=[D11,D12;
    D21,D22];


Gs=ltisys(A,B,C,D);

%control synthesizing...
[Gopt,contr]=hinflmi(Gs,[1;1],1);
n=contr(1,end);
ac=contr(1:n,1:n);
bc=contr(1:n,n+1);
cc=contr(n+1,1:n);
dc=contr(n+1,n+1);
controller=tf(ss(ac,bc,cc,dc))

%validation
P=tf([0,K],[tau 1 0]);
output=1/(-controller*Kg*P+1);
control=-controller*Kg/(-controller*Kg*P+1);
figure(1)
step(output)
hold on
step(control)