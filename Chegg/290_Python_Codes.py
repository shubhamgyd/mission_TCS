# Function which check all string1 elements in string2 or not
def checkSet(s1, s2):
    # converting string to list
    set1 = list(map(str, s1))
    set2 = list(map(str, s2))
    # Iterate string1 elements
    for ele in set1:
        # Check it is in set2 or not
        # if not then return false
        if ele not in set2:
            return False
    # Return True
    return True


# Example 1
print(checkSet("abc", "akjfhbcdfdg"))

# Example 2
print(checkSet("abc", "bcfjkfh"))


def fun(lis, st):
    # Map of list elements
    listMap = {}
    # Map of set elements
    setMap = {}
    # put all list elements into the list map
    for ele in lis:
        if ele not in listMap:
            listMap[ele] = 1
        else:
            listMap[ele] = listMap[ele]+1
    # Put all set elements into the set map
    for ele in st:
        if ele not in setMap:
            setMap[ele] = 1
        else:
            setMap[ele] = setMap[ele]+1

    # answer elements
    ans = []
    # Iterate list
    for ele in lis:
        # if list element is present in set
        if ele in setMap:
            # check both have the same occurace or not
            # if yes then push into the answer list
            if listMap[ele] == setMap[ele]:
                ans.append(ele)

    return ans


# List
a = [1, 2, 3, 4, 4, 5]
# set of elements
b = [1, 2, 3, 4, 4, 5, 6, 7, 8, 9, 10]
# print answer
print(fun(a, b))

# Function which counts the number of vowels present in the stirng
def countVowels(s):
    cnt = 0
    # Check character by character
    for i in s:
        if (i == 'a' or i == 'e' or i == 'i' or i == 'o' or i == 'u' or i == 'A' or i == 'E' or i == 'I' or i == 'O' or i == 'U'):
            cnt = cnt+1
    return cnt


# given string
string = "Chegg is Better"
# get answer
ans = countVowels(string)
# print answer
print("Number of vowels: ", ans)
