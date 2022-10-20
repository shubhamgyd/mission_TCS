# input first number
x = int(input("Enter first number: "))

# input second number
y = int(input("Enter second number: "))

# vector to store numbers
vector = []
# append first number
vector.append(x)

# 2nd element
# according to the formula
# x*y^n
res = (x*(y**2))
# append second number
vector.append(res)
# now from 3rd element
i = 3
# Iterate until result is less than or equal too 1000 or n is reaches to 100
while i < 100 and res <= 10000:
    # get ith element
    res = (x*(y**i))
    # append into the list
    vector.append(res)
    # next element
    i = i+1

# print vector of elements
print(vector)
