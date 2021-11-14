import numpy as np

a = int(input("enter number of rows: "))
b = int(input("enter number of columns: ")) 

matrix = lambda : [list(map(int,input().strip().split())) for _ in range(a)]
for i in range(2):
    print("matrix: ", i + 1)
    if i==0:
        matA=np.array(matrix())
    elif i==1:
        matB=np.array(matrix())

print("matrix a is: ")
print(matA)
print("matrix b is: ")
print(matB)
res = np.dot(matA, matB)

print("Multiplication of matrix a and b is : \n",res)
