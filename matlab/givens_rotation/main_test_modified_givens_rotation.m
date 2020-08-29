clc;
clear variables

% Matrix rotation
% vector rotation, 2 by 2 
%
x1 = [2 3]';
d = [2 2]';
x = sqrt(d).*x1;

nrm2 = sqrt(sum(x1.^2));

% [c2, s2, r] = givens_rotation_v2(x);

params = [1, 2/3.0, 0, 0, 2/3.0];
h11 = params(2);
h21 = params(3);
h12 = params(4);
h22 = params(5);
if (params(1) == -1)
    H = [h11, h12; h21, h22];
elseif (params(1) == 0)
    H = [1.0, h12; h21, 1.0];
elseif (params(1) == 1)
    H = [h11, 1.0; -1.0, h22];
elseif (params(1) == -2)
    H = [1.0, 0.0; 0.0, 1.0];
end

xr = H * x1;

% comparison with BLAS drot_ function
dx = [1 1 5 2]';
dy = [2 3 2 3]';

dxx = H(1,1) * dx + H(1,2) * dy;
dyy = H(2,1) * dx + H(2,2) * dy;

disp(dxx);
disp(dyy);
