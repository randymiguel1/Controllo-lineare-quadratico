clear;
close all;
clc;
%% Parametri del sistema
m = 500;
b = 20;
g = 9.81;
V = 2000;
p_a = 1.184;
theta_a = 298;
c = 718;
k = 2.5;

% Parametri di equilibrio del sistema
theta = theta_a/(1-(m/(V*p_a)));
x_0 = [550;0;150];
x_eq = [600;0;theta];
u_eq = k*(theta - theta_a);
f_w = 0;

%% Linearizzazione
modello = 'mongolfiera_linearizzato';           

%configurazione per la realizzaione della linearizzazione
opspec = operspec(modello);

%ingresso
opspec.Inputs.Known = 1;
opspec.Inputs.u = u_eq;

pto_op = findop(modello,opspec); %punto di lavoro

modello_linearizzato = linearize(modello,pto_op);% modello linearizzato nel punto di lavoro

[Ac,Bc,Cc,Dc] = ssdata(modello_linearizzato);

tsim = 50; %tempo di simulazione
Tc = 0.01; % tempo di campionamento
N = floor(tsim/Tc); %numero di iterazioni

modello_linearizzato_continuo = ss(Ac,Bc,Cc,Dc);
autovalori_sistema = eig(Ac);
modello_linearizzato_discreto = c2d(modello_linearizzato_continuo,Tc);

[Ad,Bd,Cd,Dd] = ssdata(modello_linearizzato_discreto);
R_matrice = ctrb(Ad,Bd);          %calcolo la matrice di raggiungibilita
O_matrice = obsv(Ad,Cd);          %calcolo la matrice di ossevarbilita
R_matrice_rank = rank(R_matrice); %calcolo del rango della matrice di raggiungibilita
O_matrice_rank = rank(O_matrice); %calcolo del rango della matrice di osservabilita

%%////////////////////////// Controllo LQ orizzonte tempo finito///////////////////
%//////////////////////////////////////////////////////////////////////////////////

%impostiamo i pesi Q,R,S e M

%matrice con 1 righe (voglio pesare l'altezza) e 3 colonne (numeri di stati) 
Cn = [1 0 0];
  
%matrice con 2 righe (1 stati da pesare e 1 attuatore)  
Cz = [1 0 0
      0 0 0];
  
%parametro di taratura del controllo LQ  
sqrtrho = 1/1000;

%matrice con 2 righe (1 stati da pesare + 1 attuatore) e una colonna (1 attuatore) 
Dzu = [0 ;sqrtrho];

S = Cn'*Cn;
Q = Cz'*Cz;
R = Dzu'*Dzu;
M = Dzu'*Cz;

%% Fase off-line
[P,F] = offline_LQ(Ad,Bd,Q,R,S,M,N);

%% Fase on-line
%costo ottimo
J_opt_fin = x_0'*P(:,:,1)*x_0;

risultato_tempo_infinito = sim('controllo_LQ_finito');
figure(1)
subplot(321)
plot(risultato_tempo_infinito.stati.time,risultato_tempo_infinito.stati.signals.values(:,1));
yline(600,'--r','LineWidth',2);
grid;
title('altezza (Controllo LQ Tempo Finito)');
xlabel('sec.');
ylabel('m');

subplot(323)
plot(risultato_tempo_infinito.stati.time,risultato_tempo_infinito.stati.signals.values(:,2));
yline(0,'--r','LineWidth',2);
grid;
title('velocita');
xlabel('sec.');
ylabel('m/s');

subplot(325)
plot(risultato_tempo_infinito.stati.time,risultato_tempo_infinito.stati.signals.values(:,3));
yline(theta,'--r','LineWidth',2);
grid;
title('temperatura del aria all interno del pallone');
xlabel('sec.');
ylabel('gradi K');

%%////////////////////// Controllo LQ orizzonte di tempo infinito///////////
%///////////////////////////////////////////////////////////////////////////

[F_inf,P_inf,autovalori] = lqr(modello_linearizzato_discreto,Q,R);
autovalori_sistemi_LQ_infinito = eig(Ad-Bd*F_inf);

risultato_tempo_infinito = sim('controllo_LQ_infinito');
figure(1)
subplot(322)
plot(risultato_tempo_infinito.stati.time,risultato_tempo_infinito.stati.signals.values(:,1));
yline(600,'--r','LineWidth',2);
grid;
title('altezza (Controllo LQ Tempo Infinito)');
xlabel('sec.');
ylabel('m');

subplot(324)
plot(risultato_tempo_infinito.stati.time,risultato_tempo_infinito.stati.signals.values(:,2));
yline(0,'--r','LineWidth',2);
grid;
title('velocita');
xlabel('sec.');
ylabel('m/s');

subplot(326)
plot(risultato_tempo_infinito.stati.time,risultato_tempo_infinito.stati.signals.values(:,3));
yline(theta,'--r','LineWidth',2);
grid;
title('temperatura del aria all interno del pallone');
xlabel('sec.');
ylabel('gradi K');

%% ////////////LQ inseguimento di traiettoria tempo finito/////////////
%//////////////////////////////////////////////////////////////////////

%matrice del generatore di segnale a tempo continuo di un gradino
Arc = 0;
Brc = 0;
Crc = 1;
Drc = 0;

generatore_rif = ss(Arc,Brc,Crc,Drc);
generatore_rif_td = c2d(generatore_rif,Tc);
[Ar_d,Br_d,Cr_d,Dr_d] = ssdata(generatore_rif_td);

[nr,nr] = size(Ar_d);
[nx,nu] = size(Bd);

%impostiamo i pesi Q,R e S
%scelta di S
Sy = 1;
S_t = [Cd'; -Cr_d']*Sy*[Cd -Cr_d];

%scelta di Q 
Qy = 100;
Q_t = [Cd'; -Cr_d']*Qy*[Cd -Cr_d];

%scelgo di R
sqrtrho_inseguimento = 1/1000;
R_inseguimento = sqrtrho_inseguimento;

%costruzzione del modello nello stato aumentato
A_aug = [Ad zeros(nx,nr); 
         zeros(nr,nx) Ar_d];
     
B_aug = [Bd; zeros(nr,nu)];

[P_aug,F_aug] = offline_LQ(A_aug,B_aug,Q_t,R_inseguimento,S_t,M,N);

F_fb = F_aug (:,1:nx);
F_ff = F_aug (:, nx+1:end);

risultato_inseguimento_tempo_finito = sim('controllo_LQ_inseguimento');
figure(2)
subplot(211)
plot(risultato_inseguimento_tempo_finito.stati.time,risultato_inseguimento_tempo_finito.stati.signals.values(:,1),'--',risultato_inseguimento_tempo_finito.stati.time,risultato_inseguimento_tempo_finito.stati.signals.values(:,2));
grid;
title('altezza (LQ inseguimento Tempo Finito)');
xlabel('sec.');
ylabel('m');


%% ////////////LQ inseguimento di traiettoria tempo infinito///////////
%//////////////////////////////////////////////////////////////////////

F_fb_in = F_fb(1,:);
F_ff_in = F_ff(1,:);

risultato_inseguimento_tempo_infinito = sim('controllo_LQ_inseguimento_infinito');
figure(2)
subplot(212)
plot(risultato_inseguimento_tempo_infinito.stati.time,risultato_inseguimento_tempo_infinito.stati.signals.values(:,1),'--',risultato_inseguimento_tempo_infinito.stati.time,risultato_inseguimento_tempo_infinito.stati.signals.values(:,2));
grid;
title('altezza (LQ inseguimento Tempo Infinito)');
xlabel('sec.');
ylabel('m');

%% ////////////inseguimento di traiettoria LQ con efetto integrale/////
%//////////////////////////////////////////////////////////////////////

%matrici di stato del modello originale con l'integratore Td
A_integratore = [Ad Bd; 
         zeros(nu,nx) eye(nu)];
     
B_integratore = [Bd; eye(nu)];

%modello nello stato augmentato con integratore
A_aug_acc = [A_integratore zeros(nx+nu,nr);
             zeros(nr,nx+nu) Ar_d];
         
B_aug_acc = [B_integratore; zeros(nr,nu)];

%matrici di peso Q,R,S
Qy = 100;
Q_acc = [[Cd zeros(1,nu)]' ; -Cr_d']*Qy*[[Cd zeros(1,nu)] -Cr_d];
Sy = 1;
S_acc = [[Cd zeros(1,nu)]' ; -Cr_d']*Sy*[[Cd zeros(1,nu)] -Cr_d];

sqrtrho_acc = 1/1000;
R_acc = sqrtrho_acc;

%calcolo di P e F nello stato augmnetato con integratore
[P_aug_acc,F_aug_acc]=offline_LQ(A_aug_acc,B_aug_acc,Q_acc,R_acc,S_acc,M,N);

%estraggo componente di fb e ff del guadagno nello stato augmentato con
%integratore
F_aug_acc_fb = F_aug_acc(:,1:nx+nu);
Fv_aug_acc = F_aug_acc(:,nx+nu+1:end);

%estraggo i guadagni di fb e ff nel tempo infinito
F_aug_acc_fb_infinito = F_aug_acc_fb(1,:);
Fv_aug_acc_infinito = Fv_aug_acc(1,:);

risultato_integratore = sim('controllo_LQ_integratore');
figure(3)
subplot(211)
plot(risultato_integratore.stati.time,risultato_integratore.stati.signals.values(:,1),'--',risultato_integratore.stati.time,risultato_integratore.stati.signals.values(:,2));
grid;
title('altezza (LQ integratore)');
xlabel('sec.');
ylabel('m');

%% ////////////Model Following Problem/////////////////////////////////
%//////////////////////////////////////////////////////////////////////
%matrici del modello di riferimento 1/(s+1)
A_tilde = -1;
B_tilde = 1;
C_tilde = 1;
D_tilde = 0;

[nmf,nmf] = size(A_tilde); %dimensioni di stati del modello di riferimento

%matrici di stato del generatore di riferimento
Ar_mf = [A_tilde B_tilde*Crc;
         zeros(nr,nr) Arc];
[nmfr,nmfr] = size(Ar_mf);%dimensioni degli stati del modello di generatore di riferimento 
     
Br_mf = zeros(nr+nmf,1);

Cr_mf = [C_tilde zeros(1,nr)];

Dr_mf = 0;
 
generatore_rif_mf = ss(Ar_mf,Br_mf,Cr_mf,Dr_mf);    %modello tempo continuo del generatore di riferimento
generatore_rif_mf_td = c2d(generatore_rif_mf, Tc);  %modello tempo discreto del generatore di riferimento

[Ar_mf_d,Br_mf,Cr_mf,Dr_mf] = ssdata(generatore_rif_mf_td); %modello spazio di stato tempo discreto del generatore di riferimento

%Modello del stato augmentato "model following"
A_aug_mf = [Ad zeros(nx,nmfr);
            zeros(nmfr,nx) Ar_mf_d];
B_aug_mf = [Bd; zeros(nmfr,nu)];

% Devo definire i pesi Q, R, S del controllo LQ in forma di inseguimento
% Qy e uguale alla matrice indentita in questo caso
Q_mf = [Cd';-Cr_mf']*[Cd -Cr_mf]; 
S_mf = Q_mf;

sqrtrho_mf = 1/1000;
R_mf = sqrtrho_mf;

%calcolo P e F nello stato augmentato del "model following"
[P_aug_mf,F_aug_mf]=offline_LQ(A_aug_mf,B_aug_mf,Q_mf,R_mf,S_mf,M,N);

%estraggo la componente di fb e ff
F_aug_mf_fb = F_aug_mf(:,1:nx);
F_aug_mf_ff = F_aug_mf(:,nx+1:end);

%estraggo la componente di fb e ff tempo infinito
F_aug_mf_fb_infinito = F_aug_mf_fb(1,:);
F_aug_mf_ff_infinito = F_aug_mf_ff(1,:);


risultato_model_following = sim('controllo_model_following');
figure(3)
subplot(212)
plot(risultato_model_following.stati.time,risultato_model_following.stati.signals.values(:,1),risultato_model_following.stati.time,risultato_model_following.stati.signals.values(:,2),'--','LineWidth',2);
grid;
title('altezza (Mode Following)');
xlabel('sec.');
ylabel('m');

%% ///////Controllo LQ tc sull'orizzonte di tempo infinito tramite LMI///////////////////////
%////////////////////////////////////////////////////////////////////////////////////////////

%Scelgo tutti i parametri del controllo LQ prima calcolati
%matrice del sistema continuo Ac con dimensioni (nx)x(nx)
%matrice del sistema continuo Bc con dimensioni (nx)x(nu)
%matrice di uscita fittizia Cz con dimensioni (nz)x(nx)
[nz,nx] = size(Cz);
%prametro di taratura R
%matrice di uscita fittizia Dzu con dimensioni (nz)x(nu)


%imposto il solver come silenzioso
ops = sdpsettings('verbose',0,'solver','lmilab');

%Definisco le variabili LMI alplha, Y, K
alpha = sdpvar(1);
Y = sdpvar(nx);
K = sdpvar(nu,nx);

%Definisco i vincoli della LMI
V1 = [1 x_0';          %vincolo upper bound normalizzato
      x_0 Y] >= 0;
  
V2 = Y >= 0;            %Positivita sul Y

V3 = [Y*Ac'-K'*Bc'+Ac*Y-Bc*K   Y*Cz'-K'*Dzu';          % Diseguaglianza di Riccati tempo continuo
      Cz*Y - Dzu*K            -alpha*eye(nz)] <=0;
  
V_c = [V1, V2, V3];  

risulato = optimize(V_c,alpha,ops);

% Mi calcolo F e X (variabili originali)
F_lmi_tc = double(K)*inv(double(Y));

X_lmi_tc = double(alpha)*inv(double(Y));

autovalori_sistema_ritroazionato_tc = eig(Ac - Bc*F_lmi_tc);

risultato_LQ_infinito_tc_LMI = sim('controllo_LQ_infinito_tc_LMI');
figure(4)
subplot(211)
plot(risultato_LQ_infinito_tc_LMI.stati.time,risultato_LQ_infinito_tc_LMI.stati.signals.values(:,1));
yline(600,'--r','LineWidth',2);
grid;
title('altezza (LQ infinito tc LMI)');
xlabel('sec.');
ylabel('m');


%% ////////////Controllo LQ td sull'orizzonte di tempo infinito tramite LMI//////////////////
%////////////////////////////////////////////////////////////////////////////////////////////

%Scelgo tutti i parametri del controllo LQ prima calcolati
%matrice del sistema continuo Ad con dimensioni (nx)x(nx)
%matrice del sistema continuo Bd con dimensioni (nx)x(nu)
%matrice di uscita fittizia Cz con dimensioni (nz)x(nx)
[nz,nx] = size(Cz);
%matrice di uscita fittizia Dzu con dimensioni (nz)x(nu)
%prametro di taratura R

%imposto il solver come silenzioso
ops = sdpsettings('verbose',0,'solver','lmilab');

%Definisco le variabili LMI alplha, Y, K
alpha = sdpvar(1);
Y = sdpvar(nx);
K = sdpvar(nu,nx);

%Definisco le variabili LMI alplha, Y, K

V1 = [1 x_0';          %vincolo upper bound normalizzato
      x_0 Y] >= 0;

V2 = Y >= 0;            %Positivita sul Y

V3 = [Y            Y*Ad'-K'*Bd'   Y*Cz'-K'*Dzu';           % Diseguaglianza di Riccati tempo discreto
      Ad*Y-Bd*K    Y              zeros(nx,nz);
      Cz*Y-Dzu*K   zeros(nz,nx)   alpha*eye(nz)]>=0;

V_d = [V1, V2, V3];
  

risulato = optimize(V_d,alpha,ops);

% Mi calcolo F e X (variabili originali)
F_lmi_td = double(K)*inv(double(Y));

X_lmi_td = double(alpha)*inv(double(Y));

autovalori_sistema_ritroazionato_td = eig(Ad - Bd*F_lmi_td);

risultato_LQ_infinito_td_LMI = sim('controllo_LQ_infinito_td_LMI');
figure(4)
subplot(212)
plot(risultato_LQ_infinito_td_LMI.stati.time,risultato_LQ_infinito_td_LMI.stati.signals.values(:,1));
yline(600,'--r','LineWidth',2);
grid;
title('altezza (LQ infinito td LMI)');
xlabel('sec.');
ylabel('m');

%% ////////////Controllo LQ integrale senza generatore di riferimento tramite LMI////////////
%////////////////////////////////////////////////////////////////////////////////////////////

%Scelgo tutti i parametri del controllo LQ prima calcolati
%matrice del sistema continuo Ad con dimensioni (nx)x(nx)
%matrice del sistema continuo Bd con dimensioni (nx)x(nu)
%prametro di taratura R

A_aug_lmi = [Ad          zeros(nx,1);   %(nx+1)x(nx+1)
             Cd*Ad       1         ];

B_aug_lmi = [Bd ; Cd*Bd];  %(nx+1)x(nu)

C_aug_lmi = [zeros(1,nx) 1];

%matrice di uscita di prestazione del modello augmentato
Cz_aug_lmi = [C_aug_lmi;     %ottimizo rispetto all'errore di inseguimento 3 stati + 1(errore di inseguimento)
               0 0 0 0];
[nz_aug,nx_aug] = size(Cz_aug_lmi); %estraggo il numero di uscite di prestazione

%parametro di taratura
sqrtrho_lmi_int = 1/1000;
R_lmi_int = sqrtrho_lmi_int;

Dzu_lmi = [0; R_lmi_int];

ops=sdpsettings('verbose',1,'solver','lmilab'); % solver silenzioso e specificato a lmilab

% Definisco le variabili LMI  alpha, Y, K (devo tenere conto dello stato
% aumentato)
%alpha = sdpvar(1);
Y = sdpvar(nx+1);
K = sdpvar(nu,nx+1);

x_0_aug = [20;0;theta;.1];

% Definisco i vincoli del problema LMI
V1=[1        x_0_aug';            % Upper bound normalizzato
    x_0_aug  Y       ] >= 0;

V2=Y >= 0;            % Positivita' sulla Y

% Diseguaglianza di Riccati tempo discreto
V3 = [Y                          Y*A_aug_lmi'-K'*B_aug_lmi'          Y*Cz_aug_lmi'-K'*Dzu_lmi';
      A_aug_lmi*Y-B_aug_lmi*K    Y                                   zeros(nx+1,nz_aug);
      Cz_aug_lmi*Y-Dzu_lmi*K     zeros(nz_aug,nx+1)                  alpha*eye(nz_aug)] >= 0;

% Metto insieme tutti i vincoli
V_lmi_int = [V1,V2,V3];

% Ottimizzo
risultato_lmi_int = optimize(V_lmi_int,alpha,ops);

% Mi calcolo F e X (variabili originali che sono "indipendenti" dallo stato iniziale considerato, e' teorico)
F_lmi_int = double(K)*inv(double(Y));
X_lmi_int = double(alpha)*inv(double(Y));

% estraggo le prime nx colonne da F_lmi
F_lmi_int_fb = F_lmi_int(:,1:nx);

% estraggo il guadango f_nx+1
F_lmi_int_ff = F_lmi_int(:,nx+1);

risultato_LQ_integrale_LMI = sim('controllo_LQ_integrale_LMI');
figure(5)
plot(risultato_LQ_integrale_LMI.stati.time,risultato_LQ_integrale_LMI.stati.signals.values(:,1),risultato_LQ_integrale_LMI.stati1.time,risultato_LQ_integrale_LMI.stati1.signals.values(:,1));
grid;
title('altezza (LQ integrale senza riferimento LMI)');
xlabel('sec.');
ylabel('m');

%% ////////////////////Controllo LQG full state//////////////////////////////////////////////
%////////////////////////////////////////////////////////////////////////////////////////////

F_gen= place(Ac,Bc,[-0.5,-0.4,-0.8]);


risultato_LQG_tc = sim('controllo_LQG_tc');
figure(6)
plot(risultato_LQG_tc.stati.time,risultato_LQG_tc.stati.signals.values(:,1),risultato_LQG_tc.stati1.time,risultato_LQG_tc.stati1.signals.values(:,1));
grid;
legend('con controllo LQG', 'senza controllo LQG');
title('altezza (Controllo LQG)');
xlabel('sec.');
ylabel('m');







