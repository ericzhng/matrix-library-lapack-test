function [c,s,r] = givens_rotation_v2(x)

a = x(1);
b = x(2);

if b == 0
    c = sign(a);
    if(c == 0)
        c = 1.0; % Unlike other languages, MatLab's sign function returns 0 on input 0.
    end
    s = 0;
    r = abs(a);
elseif a == 0
    c = 0;
    s = sign(b);
    r = abs(b);
elseif abs(a) > abs(b)
    t = b/a;
    u = sign(a)*sqrt(1+t*t);
    c = 1/u;
    s = c*t;
    r = a*u;
else
    t = a/b;
    u = sign(b)*sqrt(1+t*t);
    s = 1/u;
    c = s*t;
    r = b*u;
end

end
