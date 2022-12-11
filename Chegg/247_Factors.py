# Recursive function to calculate the n to the power 3 of number which is less than or equal to n
def nToPower3(n):
    # base case
    # if n==1 return 1
    # because 1^3=1
    if n==1:
        return 1
    # else return n^3*(nToPower(n-1)) and so on
    return (n**3)*(nToPower3(n-1))

# main method
if __name__ == '__main__':
    # Read n
    n=int(input("Enter number: "))
    # call a function and get answer
    ans=nToPower3(n)
    # print answer
    print(ans)
    