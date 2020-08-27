# matrix-library-lapack-test
Tests and examples for BLAS and LAPACK packages

## BLAS/LAPACK Testing Examples

### Introduction



### Some Notes and References

> BLAS function "dgemm" stores matrix in column-wise format in Fortran.

- The mixed language linking for gcc linking Fortran is as below:
  - lg2c is for g77
  - lgfortran is for gfortran (if gcc is later than 4.0)

-  The following link explains C/Fortran cross linking:
http://northstar-www.dartmouth.edu/doc/solaris-forte/manuals/fortran/prog_guide/11_cfort.html

- This explains detailed implementation of the functions and storage:
https://www.ibm.com/support/knowledgecenter/SSFHY8_6.2/reference/am5gr_hstbmv.html
