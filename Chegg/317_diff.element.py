# Function which returns the unique elements from both lits
def appears_in_1(L1, L2):
    # return the set of list 
    return set(L1) ^ set(L2)


# List1
L1 = [1, 2, 3, 4, 4, 5, 6]
# List2
L2 = [4, 5, 6, 1, 7, 8, 9]
# print unique elements from both of the lists
print(appears_in_1(L1, L2))
