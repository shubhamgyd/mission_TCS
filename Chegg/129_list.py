# Task : 1
# Create an empty list by asigning the list to a variable
# way to create a list
c = []
# prints empty list
print(c)


# Task : 2
# We can also create a list by dicrectly assigning the values
c = [-45, 6, 0, 72, 1543]
# prints -> [-45,6,0,72,1543]
print(c)


# Task : 3
# Accessing Elements of a List:
# While accessing a list elements we need to write the name of list followed by index inclised in []
# [] known assubscription operator

# Index of list starts from the 0th position

# i.e.
# c[0]=-45
# c[1]=6
# c[2]=0
# c[3]==72
# c[4]=1543

# Here last index is 4 i.e indexing start from 0 to the length of list-1


# Task : 4
# print element
# prints -45
print(c[0])

# prints 1543
print(c[4])

# error ,becasuse index 5 is not present int list
# i.e. list have index only from 0 to 4
# print(c[5])


# Task: 5
# Determining the length of list using len
# print 5
print(len(c))


# len is a inbuild function in python which determine the length of objects elements associated in it
# using it we can easily find the length of array,list,string etc.

# print 26
print(len("abcdefghijklmnopqrstuvwxyz"))
