# Gauss-Elimination-algorithm---C-language-

We want to solve a System of linear equations: Ax = b using "Gauss elimination" method (algorithm). 
The algorithm is implemented in C language 
The idea of the Gaussian elimination method is to solve the system of equations in two stages. The first stage, called Gaussian elimination (triangularization) aims at transforming the system of equations so that the solution remains unchanged, but the matrix of coefficients has in the end a special structure, namely the upper triangular. The second stage is the retrosubstitution (regressive substitution) in which the components of the solution vector are calculated in turn, starting with the one with the highest index.

Results:

-------------------------------------------
The initial matrix A has the values:
1.00 2.00 -1.00 
-2.00 3.00 1.00
4.00 -1.00 -3.00

-------------------------------------------
The initial vector b (free terms) has the values:
-1.00 0.00 -2.00
-------------------------------------------
The new matrix A has the values (after Gauss elimination):
1.00 2.00 -1.00
0.00 7.00 -1.00
0.00 -0.00 -0.29

-------------------------------------------
The new vector b has the values:
-1.00 -2.00 -0.57
-------------------------------------------
The solution of the system:
x[2] = 2.00
x[1] = 0.00
x[0] = 1.00
