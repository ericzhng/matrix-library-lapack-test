
function [G, A, c0, s0] = givens_rotation_matrix(A, id)

len = length(A);
i = id(1);
j = id(2);

% make sure i < j, so that the negative value is within lower triangular
assert(i ~= j, 'make sure i does not equal to j');
if (i > j)
    tmp = j;
    j = i;
    i = tmp;
end

% the two values of the matrix to transform
values = A([i, j], i);

[c0, s0] = givens_rotation_v2(values);

G = generate_matrix_n_dim(c0, s0, len, i, j);

A = G * A;

end
