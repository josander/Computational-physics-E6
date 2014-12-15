%% E6

phi = importdata('phi.data');

plot(phi);
%% Plot dipole solution 
L = 1;
Lint = 0.0001;
poleDisp = 0.2*L;

X = 0:Lint:L;

phiDipole = @(x) -(log(abs(x - L/2 - poleDisp)) - log(abs(x - L/2 + poleDisp)));

Y = phiDipole(X); 

plot(X,Y)
