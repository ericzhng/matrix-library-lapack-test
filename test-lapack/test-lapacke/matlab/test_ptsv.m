
A = [1.0  1.0  0.0  0.0;                                  
	1.0  2.0  1.0  0.0;                                 
	0.0  1.0  4.2  1.0;                 
	0.0  0.0  1.0  1.0];

eig(A)

B = [2.0 -2.0;                                        
	4.0 -3.0;                                          
	5.0  0.0;                                         
	2.0  1.0];

c = A \ B

err = A*c - B