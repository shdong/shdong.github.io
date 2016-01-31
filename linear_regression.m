x = load('ex2x.dat');
y = load('ex2y.dat');

figure % open a new figure window
plot(x, y, 'o');
ylabel('Height in meters')
xlabel('Age in years')


fprintf('Running Gradient Descent ...\n')

m = length(y); % store the number of training examples
x = [ones(m, 1), x]; % Add a column of ones to x
theta = zeros(2, 1); % initialize fitting parameters

% Some gradient descent settings
iterations = 1500;
alpha = 0.07;

% compute and display initial cost
% J = 1/(2*m) sum(||X*theta-y||^2)
% computeCost(X, y, theta)
J = 0;
for i = 1:m
    err = theta(1)*x(i,1)+theta(2)*x(i,2)-y(i);
    J  = J+ err*err;
end
J = J/(2*m)   % show the value of J


% run gradient descent
%theta = gradientDescent(X, y, theta, alpha, iterations);
for iter = 1:iterations
    for j=1:2
        sum = 0;
        for i = 1:m
            sum=sum+(theta(1)*x(i,1)+theta(2)*x(i,2)-y(i))*x(i,j);    
        end
        theta(j)=theta(j)-alpha*sum/m;
    end
end

% print theta to screen
fprintf('Theta found by gradient descent: ');
fprintf('%f %f \n', theta(1), theta(2));

% Plot the linear fit
hold on; % keep previous plot visible
plot(x(:,2), x*theta, '-')
legend('Training data', 'Linear regression')
hold off % don't overlay any more plots on this figure


% Predict values for population sizes of 35,000 and 70,000
predict1 = [1, 3.5] *theta;
fprintf('For age = 3.5, we predict a profit of %f\n',...
    predict1);
predict2 = [1, 7] * theta;
fprintf('For age = 7, we predict a profit of %f\n',...
    predict2);

fprintf('Program paused. Press enter to continue.\n');
%pause;

% ploat the cost function surface
J_vals = zeros(100, 100);   % initialize Jvals to 100x100 matrix of 0's
theta0_vals = linspace(-3, 3, 100);
theta1_vals = linspace(-1, 1, 100);
for i = 1:length(theta0_vals)
	  for j = 1:length(theta1_vals)
          t = [theta0_vals(i); theta1_vals(j)];      
          
          for k=1:m 
              err = t(1)*x(k,1)+t(2)*x(k,2)-y(k);
              J_vals(i,j)  = J_vals(i,j)+ err*err;
          end
          J_vals(i,j)=J_vals(i,j)/(2*m)  ; 
          
          % J_vals(i,j)= computeCost(x, y, t);
      end
end

% Plot the surface plot
% Because of the way meshgrids work in the surf command, we need to 
% transpose J_vals before calling surf, or else the axes will be flipped
J_vals = J_vals';
figure;
surf(theta0_vals, theta1_vals, J_vals)
xlabel('\theta_0'); ylabel('\theta_1')

figure;
% Plot the cost function with 15 contours spaced logarithmically
% between 0.01 and 100
contour(theta0_vals, theta1_vals, J_vals, logspace(-2, 2, 15))
xlabel('\theta_0'); ylabel('\theta_1')

