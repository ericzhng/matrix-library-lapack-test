
% comparison with BLAS gemv function

% initial matrix:
%  | 1.0  1.0  1.0  0.0 |
%  | 2.0  2.0  2.0  2.0 |
%  | 3.0  3.0  3.0  3.0 |
%  | 4.0  4.0  4.0  4.0 |
%  | 0.0  5.0  5.0  5.0 |

A = [ 1.0  1.0  1.0  0.0;
      2.0  2.0  2.0  2.0;
      3.0  3.0  3.0  3.0;
      4.0  4.0  4.0  4.0;
      0.0  5.0  5.0  5.0 ];
[M,N] = size(A);

% saving a band structure matrix
kl = 3;
ku = 2;

% saving as general double band matrix
%   BLAS-general-band storage mode
%         |  .    .   1.0  2.0 |
%         |  .   1.0  2.0  3.0 |
%         | 1.0  2.0  3.0  4.0 |
% A    =  | 2.0  3.0  4.0  5.0 |
%         | 3.0  4.0  5.0   .  |
%         | 4.0  5.0   .    .  |
%         |  .    .    .    .  |
%         |  .    .    .    .  |

X =  [1.0, 2.0, 3.0, 4.0]';
Y =  [1.0, 2.0, 3.0, 4.0, 5.0]';

alpha = 2.0;
beta = 10.0;

res = alpha * A * X + beta * Y;

disp(res)

