
# loop will run until the number is valid
while True:
    # input the number from user
    n = int(input("Please input a nonnegative integer? "))

    # initalise the value of a factorial is 1
    factorial=1

    # if given number is negative then show the error and exit from the program
    if n<0:
        print("Please enter a nonnegative integer")
        break

    # else find the factorial of a number
    # Factorial of a number is nothing but the multiplication of numbers from 1 to N
    else:
        # run a for loop from 1 to n
        for i in range(1,n+1):
            # multiply number with the result
            factorial=factorial*i;
        
        # print the final result
        print("Factorial of " ,n ," :",factorial)
        print("\n")


# Time Complexity:O(n)
# Space complexity:O(1)