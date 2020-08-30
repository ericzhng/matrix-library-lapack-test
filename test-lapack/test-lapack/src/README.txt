LAPACK has a ton of drivers, i.e., higher level routines that solve all linear problems, such as linear solver, linear least square, SVD, eigenvalues, triangular factorizations (LU, Cholesky LLT, etc.), and orthogonal factorizations (QR). 

For more details, please refer to quick reference card in the doc folder.

Here, the tested routines include:
-ev: all eigenvalues

-ls: linear least square, full rank.

-tr f/s: triangular factorizations

-sv: linear solver


Note:
	Be careful that myutils.h might not compile with g++, due to the use of _Generic keyword.


https://www.geeksforgeeks.org/_generic-keyword-c/

A major drawback of Macro in C/C++ is that the arguments are strongly typed checked i.e. a macro can operate on different types of variables(like char, int ,double,..) without type checking.

Therefore we avoid to use Macro. But after the implementation of C11 standard in C programming, we can use Macro with the help of a new keyword i.e. “_Generic”. We can define MACRO for the different types of data types. For example, the following macro INC(x) translates to INCl(x), INC(x) or INCf(x) depending on the type of x:

#define INC(x) _Generic((x), long double: INCl, \
                              default: INC, \
                              float: INCf)(x)
