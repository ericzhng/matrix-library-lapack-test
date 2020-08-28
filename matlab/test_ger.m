
clear;clc;

x = [1,2,3]';
y = [2,3,1]';

A = [2, 3, 1;
     3,1,2;
     1,2,1];

alpha = 1.0;

B = A + alpha * x * y';

disp(B)
