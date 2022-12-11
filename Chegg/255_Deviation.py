import random
import numpy as np

# Declare 4x5 matrix
matrix = [[0]*5]*4
temp = 1
# Get random number and set it at i and jth column
for i in range(4):
    for j in range(5):
        # generate random number
        num = random.randint(10, 100)
        # set at i row and j th col
        matrix[i][j] = num+temp
    temp = temp+1

# given matrix
mat = np.array(matrix)
print("Generated Matrix: ")
print(mat)


# Find standard deviation
standardDeviation = np.std(mat)
print("\nStandard Deviation of given matrix: " + str(standardDeviation))
