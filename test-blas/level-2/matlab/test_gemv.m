
% comparison with BLAS gemv function
A = [ 0.84019   0.47740   0.01630
     0.39438   0.62887   0.24289
     0.78310   0.36478   0.13723
     0.79844   0.51340   0.80418
     0.91165   0.95223   0.15668
     0.19755   0.91620   0.40094
     0.33522   0.63571   0.12979
     0.76823   0.71730   0.10881
     0.27777   0.14160   0.99892
     0.55397   0.60697   0.21826];

X = [0.512932
    0.839112
    0.612640];

Y = [0.296032
    0.637552
    0.524287
    0.493583
    0.972775
    0.292517
    0.771358
    0.526745
    0.769914
    0.400229];

alpha = 1.0;
beta = 1.0;

res = alpha * A * X + beta * Y;

disp(res);

