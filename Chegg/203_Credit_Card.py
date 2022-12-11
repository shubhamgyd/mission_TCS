def isValid(number):
    # If length of card number is less than 13 or greater than 16 then is is invalid
    if len(number) < 13 or len(number) > 16:
        return False

    # if card number is not start with 4,5,6 or 37 then it is invalid
    if number[0] != '4' and number[0] != '5' and number[0] != '6' and number[0:2] != "37":
        return False

    # get sumOfDoubleEvenPlaces from right to left
    result1 = sumOfDoubleEvenPlace(number)
    # get sumOfOddPlaces from right to left
    result2 = sumOfOddPlace(number)

    # If addition of both result is divisible by 10 then it is valid else not valid
    if (result1+result2) % 10 == 0:
        return True
    return False


# Get sumOfDoubleEvenPlaces
def sumOfDoubleEvenPlace(cardNumber):
    # Reverse cardNumber
    reverseCardNumber = cardNumber[::-1]
    # Keep track on sumOfDigits
    sumOfDigits = 0
    # start from index 1 - because string indexing start from 0 and increment by 2
    for i in range(1, len(reverseCardNumber), 2):
        # convert char to int
        num = int(reverseCardNumber[i])
        # multiply by 2
        num = num*2
        # get sum of digits if it is greater than equal to 10 then is must added it to single digit sum
        sumOfDigits = sumOfDigits+getDigit(num)
    # return sumOfDigits
    return sumOfDigits


# Function which return the sum of digits of a given number
def getDigit(number):
    # If number is less than 10 then return itself
    if number < 10:
        return number
    # Else return sum of digits present at unit place and ten's place
    sumOfTwo = 0
    # sum of unit place
    sumOfTwo = sumOfTwo+number % 10
    number = number//10
    # sum of tens place
    sumOfTwo = sumOfTwo+number % 10
    # reeturn sum
    return sumOfTwo


# Function which returns the sum of digits present at odd places
def sumOfOddPlace(cardNumber):
    # Reverse number
    reverseCardNumber = cardNumber[::-1]
    # Get sum
    sumOfOdds = 0
    # Iterate and get sum of digits present at odd places
    for i in range(0, len(reverseCardNumber), 2):
        sumOfOdds = sumOfOdds+int(reverseCardNumber[i])
    # Return sum
    return sumOfOdds


def main():
    # Input of number of cards
    n = int(input("How many credit card numbers do you want to check? "))
    for _ in range(n):
        # Input of card number
        card = input("Enter a credit card number: ")
        # Validate card number
        if isValid(card) == True:
            print(f'{card} is valid')
        else:
            print(f'{card} is invalid')

# Call main to validate card numbers
main()
