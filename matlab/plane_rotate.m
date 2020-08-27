%%%%%%%%%%%%%%%The resident function:%%%%%%%
function [G, x] = plane_rotate(x)

%PLANEROT Generate a Givens plane rotation.
%       [G,Y] = PLANEROT(X), where X is a 2-component column vector,
%       returns a 2-by-2 orthogonal matrix G so that Y = G*X has Y(2) = 0.
%       See also QRINSERT, QRDELETE.
if x(2) ~= 0
    r = norm(x);
    G = [x'; -x(2) x(1)]/r;
    x = [r; 0];
else
    G = eye(2);
end

end
