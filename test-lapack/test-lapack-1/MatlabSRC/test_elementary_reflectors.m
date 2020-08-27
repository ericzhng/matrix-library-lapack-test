clear variables; clc;

%  not sure how it will work out yet

% LAPACK
% -82.6378        -49.1301        -33.7497
%   0.1702        -58.4058        -44.1202
%   0.1135          0.6013        -25.6976

% Q
%    -0.9197    0.3456    0.1865
%    -0.3267   -0.4100   -0.8515
%    -0.2178   -0.8441    0.4900

tau = [1.9197, 1.4688, 0]';

A = [76 25 11;
   27 40 51;
   18 60 32];

id = [1,2];
[G1, A1, c1, s1] = givens_rotation_matrix(A, id);

id = [1,3];
[G2, A2, c2, s2] = givens_rotation_matrix(A1, id);

% G1 / tau(1) + G2 / tau(2)
