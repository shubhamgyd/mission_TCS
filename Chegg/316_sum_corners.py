# Function returns the sum of corners of 2D array
def sum_corners(A):
    # get row and columns
    m, n = len(A), len(A[0])
    # here is the sum of corner elements
    return A[0][0] + A[0][n-1] + A[m-1][0] + A[m-1][n-1]


# given 2D array
a = [[1, 2],
     [3, 4]]

# get ans
ans = sum_corners(a)
# print ans
print(ans)
