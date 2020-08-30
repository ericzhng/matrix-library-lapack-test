close all; clc;
clear variables;

A = [1,  2,  3,  4;
     6,  7,  9,  9;
     11, 12, 19, 14;
     16, 17, 18, 12];

b = [1, 3, 5, 6]';

% solution
c = A \ b;
c
