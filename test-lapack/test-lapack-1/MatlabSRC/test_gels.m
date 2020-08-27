clc;close all;
clear variables;

A = [76 25 11;
   27 40 51;
   18 60 32];

b = [10, 7, 43]';
cp = [0.1382, -0.6515, 1.4357]';

c = A \ b

A*cp

rank(A)

cond = cond(A)
rcond_ori = rcond(A)
rcond_trans = rcond(A')


[L, U, P] = lu(A)

[Q, R, E] = qr(A)

[U,S,V] = svd(A)
U*S*V' - A




