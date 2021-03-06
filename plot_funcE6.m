%% E6
clc
clf
clear all

phi10 = dlmread('phi10.data');
phi50 = dlmread('phi50.data');
phi100 = dlmread('phi100.data');


%% Plot dipole solution 

clc
clf
clear all

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
clc

data2D = dlmread('phi_task2.data');
dataSize =size(data2D); 
x = linspace(0,1,length(data2D));

figure(1)
subplot(2,1,1)
plot(x,data2D(:,(dataSize(1)/2 +0.5)))
title('Solution, simulation');

figure(2)
subplot(2,1,1)
surf(data2D,'EdgeColor','none')
title('Grid solution, simulation');
shading interp

%% Sine magic!

gridSize = 21;
gridMid = gridSize/2 +0.5; 
singDif = (gridSize-1)*0.1;
lambda = 1;
epsi = 1;
hSq = 1;

factor = lambda*epsi*hSq;
sineGrid = zeros(gridSize,gridSize);
grid = zeros(gridSize,gridSize);
   
for m=2:gridSize-1
   for n = 2:gridSize-1
       temp = sin(pi*m*(gridMid+singDif)/gridSize)*sin(pi*n*gridMid/gridSize) - sin(pi*m*(gridMid-singDif)/gridSize)*sin(pi*n*gridMid/gridSize); 
       sineGrid(m,n) = temp/((pi*m/gridSize)^2+(pi*n/gridSize)^2);
       
   end
    
    
end
for i=2:gridSize-1
    for j=2:gridSize-1
        for m=2:gridSize-1
            for n=2:gridSize-1
                grid(i,j) = grid(i,j) + (2/gridSize)^2*sineGrid(m,n)*sin(pi*i*m/gridSize)*sin(pi*j*n/gridSize); 
               
            end
        end 
    end 
end

figure(1)
subplot(2,1,2)
plot(grid(:,gridMid))
title('Solution, fourier transform');

figure(2)
subplot(2,1,2)
surf(grid)
title('Grid solution, sine transform');

figure(5)
clf
plot(linspace(0,1,21),grid(:,11));

%%
figure(3)
hold off
clf
dx = linspace(0,1,gridSize);
[eX eY] = gradient(grid);
quiver(dx,dx,eX,eY)
hold on
contour(dx,dx,grid,10)



