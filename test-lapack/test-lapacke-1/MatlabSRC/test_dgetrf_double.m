clear;

M = 5;
N = 3;
A = zeros(M, N);

for i = 1:M
    for j = 1:N
        A(i, j) = i;
    end
end

[Q, R] = qr(A);

% https://linux.die.net/man/l/dgeqrf

%      The matrix Q is  represented  as  a  product  of  elementary
%      reflectors
% 
%         Q = H(1) H(2) . . . H(k), where k = min(m,n).
% 
%      Each H(i) has the form
%         H(i) = I - tau * v * v'
% 
%      where tau is a real scalar, and v is a real vector with
%      v(1:i-1) = 0 and v(i) = 1; v(i+1:m) is  stored  on  exit  in
%      A(i+1:m,i), and tau in TAU(i).

A1 =[ -7.4162         -7.4162         -7.4162          0.0000          0.0000;
  0.2376         -0.0000         -0.0000          0.0000          0.0000;
  0.3565         -1.0000          0.0000          0.0000          0.0000;
  0.4753          0.0000          0.0000          0.0000          0.0000;
  0.5941          0.0000          0.0000          0.0000          0.0000];
  
tau = [  1.1348;
  1.0000;
  0.0000;
  0.0000;
  0.0000];

[Q1, R1] = qrf_elem_reflection(A1, tau);

Q
Q1

R
R1