# Array of A
A = [10, 4, 20, 15, 12, 18]
# Array of B
B = [8, 10, 25, 15, 20]
# Array of C
C = []
# Iterate A and check num is in C or not
for num in A:
    # If number is not present in C
    # then push into C
    if num not in C:
        C.append(num)

# Iterate B and check num is in C or not
for num in B:
    # If number is not present in C
    # then push into C
    if num not in C:
        C.append(num)
# Print(C)
print(C)
