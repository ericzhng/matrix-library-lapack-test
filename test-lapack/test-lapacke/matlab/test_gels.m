clear; clc;

% first example
A = [     1.44  -7.84  -4.39   4.53
    -9.96  -0.28  -3.24   3.83
    -7.55   3.24   6.27  -6.64
     8.34   8.09   5.28   2.06
     7.08   2.52   0.74  -2.47
    -5.45  -5.70  -1.19   4.70];

B = [     8.58   9.35
     8.26  -4.43
     8.48  -0.70
    -5.28  -0.26
     5.72  -7.36
     8.93  -2.52	];

c = A \ B

[Q, R] = qr(A)


% second example
A = [1,1,1;
    2,3,4;
    3,5,2;
    4,2,5;
    5,4,3];

B = [-10,-3;
    12,14;
    14,12;
    16,16;
    18,16];

c = A \ B

[Q, R] = qr(A)

