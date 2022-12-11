# Given Table
my_table = [[1, 2, 3],
            [4, 5, 6],
            [7, 8, 9]]

# Task 1.1 - Access specific elements form the table
# Task is access value from the second column of the first row

# Here rows are starting from 0 to 2 and
# Column are starting from 0 to 2
# Hence first row become 0 and
# second column becomes 1
# Get value
my_value = my_table[0][1]
# Print value
print("Value of second column of the first row: "+str(my_value))


# Task 1.2: 2D List Transpose
print("Input matrix: ")
# Display Given matrix
for i in range(len(my_table)):
    for j in range(len(my_table[0])):
        print(my_table[i][j], end=" ")
    print()

print()
# Display in the form of list
print("Input matrix in list form: "+str(my_table))

# Traspose the matrix
# Must equal same row and same column
for i in range(len(my_table)):
    for j in range(i+1, len(my_table[0])):
        # swap the (i,j)th cell value with the (j,i)th cell value
        my_table[i][j], my_table[j][i] = my_table[j][i], my_table[i][j]


# Display Transpose value
print("\nOutput matrix: ")
for i in range(len(my_table)):
    for j in range(len(my_table[0])):
        print(my_table[i][j], end=" ")
    print()

print()
print("Output matrix in list form: "+str(my_table))
