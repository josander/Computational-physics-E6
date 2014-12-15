%% E6
clc
clf
clear all

phi10 = dlmread('phi10.data');
phi50 = dlmread('phi50.data');
phi100 = dlmread('phi100.data');


%% Plot dipole solution 
L = 1;
Lint = 0.0001;
poleDisp = 0.1*L;

X = 0:Lint:L;

phiDipole = @(x) -(log(abs(x - L/2 - poleDisp)) - log(abs(x - L/2 + poleDisp)))/(2*pi);

Y = phiDipole(X); 

plot(X, Y, '-b', X, phi10, 'g', X, phi50, '-.r', X, phi100, 'm');

l = legend('Free space','Boundary cond 10', 'Boundary cond 50', 'Boundary cond 100');
set(l,'Interpreter','latex')
print(gcf,'-depsc2','task1.eps')

%%



