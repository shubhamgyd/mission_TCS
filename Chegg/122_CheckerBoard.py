# checkerboard size
matrixSize = 8

# Initially fill it with zeros
checkerBoard = [[0]*matrixSize for i in range(matrixSize)]


# There are 8 rows in checkerBoard
for i in range(0, 8, 1):
    # There are 8 columns in checkerBoard
    for j in range(0, 8, 1):
        # If row number is even then fill 1 at all odd number columns
        if (i % 2 == 0):
            if (j % 2 == 1):
                checkerBoard[i][j] = 1
        # If row number is odd then fill 1 at all even number columns
        if (i % 2 == 1):
            if (j % 2 == 0):
                checkerBoard[i][j] = 1


# Print checkerBoard
for i in range(8):
    for j in range(8):
        print(checkerBoard[i][j], end=" ")
    # New line
    print()
