%%%%Van Loan's Function, Chapter 7%%%%%%%%

function GA1 = generate_matrix_n_dim(c0, s0, N, i, j)

GA1 = eye(N);

assert(i ~= j, 'make sure i does not equal to j');
% make sure i < j, so that the negative value is within lower triangular
if (i > j)
    tmp = j;
    j = i;
    i = tmp;
end

GA1(i,i) = c0;
GA1(j,j) = c0;
GA1(i,j) = s0;
GA1(j,i) = -s0;

end
