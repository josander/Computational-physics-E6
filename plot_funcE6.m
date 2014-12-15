%% E6

phi = dlmread('phi.data');

plot(phi);
%% Plot dipole solution
gridSize = 10;
gridInt = 1;
[x y] = meshgrid(-gridSize:gridInt:gridSize,-gridSize:gridInt:gridSize);


