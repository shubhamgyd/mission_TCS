# Function which store and count the how many times the substring of length n occurs in a given string
def occurrences(S, n):
    # dictionary to track on the substrings
    result = {}
    # iterate the string
    for i in range(len(S) - n + 1):
        # get substring
        substr = S[i:i+n]
        # store into the dictionary
        result[substr] = result.get(substr, 0) + 1
    # return the dictionary
    return result


# given string
string = "aadfgaadfgakjkhddddddddd"
# length of substring
n = 4
# print dictionary
print(occurrences(string, n))
