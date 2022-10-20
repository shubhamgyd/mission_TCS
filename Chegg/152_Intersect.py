# Given eqautions
# y=d*(x^2)+fx+g
# y=mx+b

# Transform
# mx+b=d*(x^2)+fx+g
# d*(x^2)+(f-m)x+(g-b)=0

import math
print("Python Intersect")
# Input values
# d
d = int(input("Enter constant d:\n"))
# f
f = int(input("Enter constant f:\n"))
# g
g = int(input("Enter constant g:\n"))
# m
m = int(input("Enter constant m:\n"))
# b
b = int(input("Enter constant b:\n"))

# Tranform it into a*(x^2)+bx+c=0

# Transform
# mx+b=d*(x^2)+fx+g
# d*(x^2)+(f-m)x+(g-b)=0


# get a
a1 = d
# get b
b1 = (f-m)
# get c
c1 = (g-b)

# find the discriminant using formula
# b^2-4ac
discriminant = b1*b1-4*a1*c1

# If Roots are real and different.
if discriminant > 0:
    # get x1
    x1 = (-b1 + math.sqrt(discriminant)) / (2*a1)
    # get x2
    x2 = (-b1 - math.sqrt(discriminant)) / (2*a1)
    # get y1
    y1 = m*x1+b
    # get y2
    y2 = m*x2+b
    # print roots
    print("The intersection is/are:")
    print(f'({x1},{y1})')
    print(f'({x2},{y2})')

# If Roots are real and same.
elif discriminant == 0:
    # get x1
    x1 = -b1/(2*a1)
    # get y1
    y1 = m*x1+b
    print("The intersection is/are:")
    # print roots
    print(f'({x1},{y1}\n')
