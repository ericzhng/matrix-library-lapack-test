function [Q, R] = qrf_elem_reflection(A, tau)

[M, N] = size(A);

Q = eye(M);
for k = 1:N
   v = zeros(M,1);
   v(k) = 1;
   v(k+1:M) = A(k+1:M, k);
   tau1 = tau(k);
   H = eye(M) - tau1 * (v * v');
   Q = Q*H;
end

% R = zeros(size(A));

R = triu(A);
R = R(:, 1:N);

end
