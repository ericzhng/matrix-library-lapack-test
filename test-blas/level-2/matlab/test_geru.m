
clear;clc;

x = [1+1i, 2+2i, 1+2i].';
y = [1+1i, 3+3i, 1+2i].';

A = [1+1i,   2+1i,    2+4i;
     2+2i,   2+2i,    1+5i;
     3+3i,   2+3i,    1+2i];

alpha = 1.0;

B = A + alpha * x * y.';

disp(B)