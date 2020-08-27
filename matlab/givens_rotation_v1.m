%%%%Van Loan's Function, Chapter 7%%%%%%%%

function [c, s] = givens_rotation_v1(x)

% Pre:
%   x1, x2   scalars
% Post:
%   c,s     c^2+s^2=1 so -s*x1 + c*x2 = 0
%

x1 = x(1);
x2 = x(2);

if x2 == 0
    c = 1;
    s = 0;
else
    if abs(x2) >= abs(x1)
        cotangent = x1/x2;
        s = 1/sqrt(1+cotangent^2);
        c = s*cotangent;
    else
        tangent = x2/x1;
        c = 1/sqrt(1+tangent^2);
        s = c*tangent;
    end
end

end