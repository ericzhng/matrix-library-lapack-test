A = [ 2.3 3.2 3.4 5.5 2.0;
   	4.2 3.4 3.2 4.5 5.6;
  	3.4 8.5 4.3 6.5 9.9;
   	4.6 7.5 3.0 0.3 4.5;
   	0.2 4.4 2.2 5.4 2.4];

b = [2.3, 5.3, 6.0, 5.3, 2.4;
    1.0, 2.3, 2, 3, 4]';

%         [  1.7995 ]
%         [  0.6552 ]
%   A\B = [ -2.6688 ]
%         [  0.9480 ]
%         [ -0.0377 ]

c = A\b
[L,U,P] = lu(A)