%% E6
clf

phi = dlmread('phi.data');


%% Plot dipole solution 
L = 1;
Lint = 0.0001;
poleDisp = 0.1*L;

X = 0:Lint:L;

phiDipole = @(x) -(log(abs(x - L/2 - poleDisp)) - log(abs(x - L/2 + poleDisp)))/(2*pi);

Y = phiDipole(X); 

plot(X,Y, X, phi)
