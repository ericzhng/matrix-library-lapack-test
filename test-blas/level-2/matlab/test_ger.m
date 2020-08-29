
clear;clc;

x = [3 2 1 4]';
y = [1 2 3]';

A = [1 2 3;
    2 2 4;
    3 2 2;
    4 2 1];

alpha = 1.0;

B = A + alpha * x * y';

disp(B)
