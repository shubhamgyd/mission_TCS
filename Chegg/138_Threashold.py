file = open("TestCases.txt", 'w')

# Function to find the totalThreasholdCount


def getThreasholdCount(arr, threshold):
    # get count
    cnt = 0
    # Iterate array
    for i in range(len(arr)):
        for j in range(i+1, len(arr)):
            # check condition
            if arr[i] > arr[j]*threshold:
                cnt = cnt+1
    # return count
    return cnt


# append data into file
def appendDataToFile(arr, ans, threashold):
    # Write array into file
    file.write("[")
    for i in range(len(arr)):
        file.write(str(arr[i]))
        if i < len(arr)-1:
            file.write(",")
    file.write("]")
    # New line
    file.write("\n")
    # write threshold value
    file.write(str(threashold))
    # new line
    file.write("\n")
    # write answer
    file.write(str(ans))
    # new line
    file.write("\n")


# Test : 1
# Given array
arr = [1, 1, 1, 1, 1, 1, 1, 1, -1, 1]
# Threshold value
threshold = 1
# get answer
ans = getThreasholdCount(arr, threshold)
# appendData
appendDataToFile(arr, ans, threshold)


# Test : 2
# Given array
arr = [1, 1, 1, 1, 1, 1, 1, 1, -1, 1]
# Threshold value
threshold = -1
# get answer
ans = getThreasholdCount(arr, threshold)
# appendData
appendDataToFile(arr, ans, threshold)


# Test : 3
# Given array
arr = [-10, -10, 4]
# Threshold value
threshold = -2
# get answer
ans = getThreasholdCount(arr, threshold)
# appendData
appendDataToFile(arr, ans, threshold)


# Test : 4
# Given array
arr = [100, 1, 100, 1]
# Threshold value
threshold = 0
# get answer
ans = getThreasholdCount(arr, threshold)
# appendData
appendDataToFile(arr, ans, threshold)


# Test : 5
# Given array
arr = [-1, 100, 100, 100, 100, 100]
# Threshold value
threshold = -1
# get answer
ans = getThreasholdCount(arr, threshold)
# appendData
appendDataToFile(arr, ans, threshold)


# Test : 6
# Given array
arr = [-100, 100, 100, 100, 100, 100]
# Threshold value
threshold = -1
# get answer
ans = getThreasholdCount(arr, threshold)
# appendData
appendDataToFile(arr, ans, threshold)

# close file
file.close()
