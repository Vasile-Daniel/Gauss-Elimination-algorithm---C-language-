

"""
We consider an algebric linear system Ax = b 
We want to solve this system using "Gauss elimination" method 
As an example we consider the system:
             |  1,  2, -1 |   | x_0 |   | -1 |
A*X = B <=>  | -2,  3,  1 | * | x_1 | = |  0 |
             |  4, -1, -3 |   | x_2 |   | -2 | 
"""

a = [[1,2,-1], [-2, 3, 1], [4, -1, -3]]
b = [-1, 0, -2]
x = 3*[0]

length = len(a)
print(f"The length is {length}.")

########################
# print the matrix 'a'   
########################

linie = "-------------"
print(linie)
for i in range(length):
    for j in range(length):
        if j == length-1: print(f"{a[i][j] : > 2}")
        else: print(f" {a[i][j] : > 2}", end = " ")
print(linie)
###################################################
# Stage 1: Gaussian elimination (triangularization)
###################################################
n = length -1

for k in range(length):
    for i in range (k+1, length):
        p = - a[i][k]/a[k][k]
        for j in range(k, length):
            a[i][j] = a[i][j] + p* a[k][j]
        b[i] = b[i] + p*b[k]
##################################################
######### print the new matrix a #################
##################################################
print("After triangularisation")
linie = "--------------------"
print(linie)
for i in range(length):
    for j in range(length):
        if j == length-1: 
            print(f"{round(a[i][j],3) : > 6}")
        else: 
            print(f" {round(a[i][j],3) : > 6}", end = " ")
print(linie)
print(f"b = {b}" )
########################################################
# Stage 2: Retrosubstitution (regressive substitution) #
########################################################
print(linie)
print("The solution of the sistem")
x[n] = b[n] / a[n][n]
print(f"x[{n}] = {x[n]}")
i = n-1
while( i>=0 ):
    s = 0
    for j in range(i,n+1):
        s = s + a[i][j]*x[j]
    x[i] = (b[i]-s)/a[i][i]
    print(f"x[{i}] = {x[i]}")
    i = i-1



    
        


