clear; clc;

% second example
A = [1+1i, 1+2i;
    2+1j, 2+2j;
    3+1j, 3+2j];

[Q, R] = qr(A)

err = Q' * Q + [-1; 0; 0]
