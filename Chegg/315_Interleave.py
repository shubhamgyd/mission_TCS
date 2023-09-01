
# Function which interleave two lists of same length
def interleave(L1, L2):
    # get final list
    interleaved = []
    # Iterate fron i=0 to len of list
    for i in range(len(L1)):
        # append elements according to the givne condition
        interleaved.append(L1[i])
        interleaved.append(L2[i])
    # return final list
    return interleaved


# list1
L1 = [1, 2, 3]
# list2
L2 = [4, 5, 6]
# print resulting list
print(interleave(L1, L2))