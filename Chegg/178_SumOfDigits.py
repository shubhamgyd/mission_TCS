# utility function which return the sum of digits present in the given number
def sumOfDigits(number):
    # keep track on sum of digits
    sum_digits=0
    # while number is greater than 0
    while number>0:
        # add the unit place digit into sum 
        sum_digits=sum_digits+number%10
        # trim the unit place digit ,coz we have already it into sum
        number=number//10

    # return sum of digits
    return sum_digits

# main function which ask the number from user
if __name__ == '__main__':
    # input number
    number=int(input("Enter number: "))
    # call function to get the the sum of digits present into the entered number
    get_sum_of_digits=sumOfDigits(number)
    # print the sum of digits
    print("Sum of digits: "+str(get_sum_of_digits))
    