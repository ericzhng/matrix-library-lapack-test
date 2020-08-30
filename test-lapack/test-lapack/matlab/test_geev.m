clear; clc;

A = [3.1-1.8j, 1.3+0.2j, -5.7-4.3j;
    1.0, -6.9+3.2j, 5.8+2.2j;
    3.4-4j, 7.2+2.9j, -8.8+3.2j];

[V, D, W] = eig(A);
b = diag(D)

V

W

% compute error for left and right eigenvalues
err1 = A * V - V * D
err2 = W' * A - D * W'
