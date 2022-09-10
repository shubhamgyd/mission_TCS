# Size of mystringarray
n=int(input("Enter size of list: "))
# mystringarray input
mystringarray=list(map(str,input().split(" ")))[:n]

# dictionary to store the string and it's index in mystringarray
wordsAndIndex={}
# indexing starting from 0
index=0
# Iterate the mystringarray
for mystring in mystringarray:
    # if mystring is not present in the dictionary
    if mystring not in wordsAndIndex:
        # then put the mystring along the index
        wordsAndIndex[mystring]=index
    # increment the index
    index=index+1

# Input the string to search
keyToSearch=str(input("Enter string to search: "))

# if key is present in the dictionary
if keyToSearch in wordsAndIndex:
    # then print it's index
    print(wordsAndIndex[keyToSearch])
# else print -1
else:
    print("-1")