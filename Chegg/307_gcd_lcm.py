
# get gcd of two numbers
def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)


# Input of a and b
a = input("Enter the first number: ")
b = input("Enter the second number: ")

# Check given number is float or not
res = False
if a.count('.') > 0:
    res = True

res1 = False
if b.count('.') > 0:
    res1 = True

# If any num is float
if res or res1:
    print("A float value is entered which is not acceptable!")
# else get gcd and find lcm of two numbers
else:
    # Type conversion str to int
    a = int(a)
    b = int(b)
    gcdOfNums = gcd(a, b)
    lcmOfNums = (a*b)/gcdOfNums
    print(f'The Greatest Common Divider is: {gcdOfNums}')
    print(f'The Larger Common Multiplier is: {int(lcmOfNums)}')
