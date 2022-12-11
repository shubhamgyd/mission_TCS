from math import sqrt
# Function which check whether number is prime or not


def isPrime(n):
    # if n is 1
    # then return false
    if n == 1:
        return False
    # if n is 2 then return true
    if n == 2:
        return True
    # if n is divisble by 2
    # then return false
    if n % 2 == 0:
        return False
    # Check in range from 3 to the square root n +1
    # if n is divisible by any number
    # then return false
    for i in range(3, int(sqrt(n)) + 1):
        if n % i == 0:
            return False
    # if number is prime
    return True


# Infinite loop
while True:
    # Read number
    n = input("\nEnter a positive number: ")
    # if user entered exit
    # then break loop
    if n == "exit":
        break
    # if entered number is number
    if n.isnumeric():
        # convert into int
        n = int(n)
        # if it is negative
        # then show error
        if n < 0:
            print("Please enter a valid positive number!!!")
            print()
        # else
        else:
            # check it is prime or not
            if isPrime(n) == True:
                print("Entered number is prime !!")
                print()
            # else display it is not prime number
            else:
                print("Entered number is not prime!!")
                print()
    # if entered number is any other string
    else:
        print("Please a enter a valid positive number")
        print()
