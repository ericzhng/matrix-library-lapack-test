close all; clc;
clear variables;

A = [76 25 11;
   27 40 51;
   18 60 32];

b = [10, 7, 43]';

% solution
c = A \ b;
c

% condition numbers
rank(A)
cond = cond(A)
rcond_ori = rcond(A)
rcond_trans = rcond(A')


% decomposition
[L, U, P] = lu(A)

[Q, R, E] = qr(A)

[U,S,V] = svd(A)

err = U*S*V' - A




