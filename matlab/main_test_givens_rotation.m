clc;
clear variables

% QR decomposition
%   matrix rotation, any N by N matrix
%
A = [6 5 0;
     5 1 4;
     0 4 3];

id = [1,2];
[G1, A1] = givens_rotation_matrix(A, id);

id = [2,3];
[G2, A2] = givens_rotation_matrix(A1, id);

Q = G1' * G2';
R = A2;

err = A - Q*R

% Matrix rotation
% vector rotation, 2 by 2 
%
x = [2 3]';
[G0, y] = plane_rotate(x);

[c1,s1] = givens_rotation_v1(x);
G1 = [c1, s1;
    -s1, c1];

[c2, s2, r] = givens_rotation_v2(x);
G2 = [c2, s2;
    -s2, c2];

disp(G1);
disp(G2);


% comparison with BLAS drot_ function
dx = [2.4, 4.0, 1, 2]';
dy = [1.0, 2.0, 2, 4]';

dxx = c1  * dx + s1 * dy;
dyy = -s1 * dx + c1 * dy;

disp(dxx);
disp(dyy);
