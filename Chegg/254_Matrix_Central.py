# Given Matrix
Matrix = [[3, 8, 15, 10],
          [37, 4, 9, 61],
          [10, 1, 12, 11],
          [0, 17, 22, 13]]
# get rows
n = len(Matrix)
# get column
m = len(Matrix[0])

# centeal row is at 1 and 2
# so initally set i at 1
i = 1
# get central elements of row i
middle1 = []
# if there are even columns
# then append middle two values into list
if m % 2 == 0:
    middle1.append(Matrix[i][m//2-1])
    middle1.append(Matrix[i][m//2])
# else push middle value into list
else:
    middle1.append(Matrix[i][m//2])

# increase row number(we have two central rows)
i = i+1
# get middle elements of row i
middle2 = []
# if there are even columns
# then append middle two values into list
if m % 2 == 0:
    middle2.append(Matrix[i][m//2-1])
    middle2.append(Matrix[i][m//2])
# else push middle value into list
else:
    middle2.append(Matrix[i][m//2])

# Print central values of row1
print("Central values of middle row1 are: "+str(middle1))
# print central values of row2
print("Central values of middle row2 are: "+str(middle2))
