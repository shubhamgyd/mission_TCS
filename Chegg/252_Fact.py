# Function which calculate the factorial of a given number
def fact(n):
    # if n is 1 then return as it is
    if n == 1:
        return 1
    # else multiple  ans by i(1 to n)
    # and return it
    ans = 1
    for i in range(1, n+1):
        ans *= i
    # return factorial of a number
    return ans


# Read n
n = int(input("Enter the value of n: "))
# get factorial of a number
ans = fact(n)
# print factorial of a number
print(f"The factorial value of {n} is "+str(ans))
