% Ficha Teórico-Prática de ATD sobre FT & FS
% Objetivo: Pretende-se ilustrar os conceitos de frequência e efetuar 
% a análise de sinais não periódicos pela Transformada de Fourier e 
% comparar com a análise de sinais periódicos (coincidentes com os 
% não periódicos durante um período) pela Série de Fourier complexa.

% Exercício 1

clear all

disp('FTP - Exercício 1.1');
A = 2;
a = 0.7;
	
syms t;
xt = A*exp(-a*t)*sin(4*pi*t)*(heaviside(t)-heaviside(t-6));
tf=12;
t=0:tf/500:tf-tf/500;
x = double(subs(xt));

figure(1);
plot(t,x);
title('x(t)');
xlabel('t [s]');

disp('FTP - Exercício 1.2');
Xw = fourier(xt);
pretty(simplify(Xw))
w = -15*pi:pi/8:15*pi-pi/8;
X = double(subs(Xw));	

figure(2);
subplot(211);
plot(w,abs(X));
title('Módulo')
ylabel('|X(w)|');
xlabel('w [rad/s]')
subplot(212);
plot(w,unwrap(angle(X)));
title('Fase');
ylabel('<X(w)');
xlabel('w [rad/s]')

disp('FTP - Exercício 1.3');
syms t
xt1 = ifourier(Xw,t);
pretty(simplify(xt1))
t=0:tf/500:tf-tf/500;
x1 = double(subs(xt1));

figure(3);
plot(t,x,'r',t,x1,'-.b');
title('x(t) original e obtido com ifourier');
xlabel('t [s]');

disp('FTP - Exercício 1.4');
t1=0:6/250:6-6/250;
xp = double(subs(xt,t1));
xp = repmat(xp,1,2);

figure(4);
plot(t,x,'r',t,xp,'-.b');
title('x(t) e xp(t)');
xlabel('t [s]');

disp('FTP - Exercício 1.5');
syms m t;
T0 = 6;
w0 = (2*pi)/T0;

cmm = (1/T0)*int(xt*exp(-j*m*w0*t), t, 0, T0);

cmm_Xw = (1/T0)*Xw;

m=-40:40;
cm = double(subs(cmm));
cm_Xw = double(subs(cmm_Xw,m*w0));

figure(5);
subplot(211);
plot(m*w0,abs(cm),'o',m*w0,abs(cm_Xw),'+');
title('Módulo')
ylabel('|cm|');
xlabel('m*w0 [rad/s]')
subplot(212);
plot(m*w0,unwrap(angle(cm)),'o',m*w0,unwrap(angle(cm_Xw)),'+');
title('Fase');

figure(6);
subplot(211);
plot(w,abs(X),m*w0,T0*abs(cm),'o');
title('Módulo')
ylabel('|X(w)| e T0*|cm|');
xlabel('w [rad/s]')
subplot(212);
plot(w,unwrap(angle(X)),m*w0,unwrap(angle(cm)),'o');
title('Fase');
ylabel('<X(w) e <cm');
xlabel('w [rad/s]')

disp('FTP - Exercício 1.6');
disp('Frequência mais relevante de x(t):');
ind=find(abs(abs(X)-max(abs(X)))<0.001);
wp=w(ind(2))
disp('4*pi=')
disp(4*pi)
