import os

# Return sum of numbers


def sum(num1, num2):
    result = num1 + num2
    return result

# Returns substraction of numbers


def subtract(num1, num2):
    result = num1 - num2
    return result

# Return multiplication of numbers


def multiply(num1, num2):
    result = num1 * num2
    return result

# Return division of numbers


def divide(num1, num2):
    result = num1 / num2
    return result

# Return power of numbers


def pow(num1, num2):
    result = 1
    for i in range(1, num2+1):
        result = result*num1
    return result

# Print the result


def print_result(num1, num2, operation, result):
    print("{0} {1} {2} = {3}".format(num1, operation, num2, result))
    input("Press enter to continue")


# Print options
def print_menu():
    os.system('cls')
    print("Operations available -\n"
          "1. Add\n"
          "2. Subtract\n"
          "3. Multiply\n"
          "4. Divide\n"
          "5. Power\n"
          "6. Exit")

# Function which calculates the result


def call_calculator(number_1, number_2, option):
    # Type cast string to int
    number_1 = int(number_1)
    number_2 = int(number_2)

    # If addition then call add sum function
    if option == 1:
        operation = '+'
        result = sum(number_1, number_2)
    # If subtraction then call subtract function
    elif option == 2:
        operation = '-'
        result = subtract(number_1, number_2)
    # If multiplication then call multiplication function
    elif option == 3:
        operation = 'x'
        result = multiply(number_1, number_2)
    # If division then call division function
    elif option == 4:
        operation = '/'
        result = divide(number_1, number_2)
    # If power then call power function
    elif option == 5:
        operation = '^'
        result = pow(number_1, number_2)
    # Print the result
    print_result(number_1, number_2, operation, result)


while True:
    # Print menue
    print_menu()
    # Select option
    option = int(input("Select an option:"))
    if (option == 6):
        break
    # Input of numbers
    number_1 = input("Enter first number: ")
    number_2 = input("Enter second number: ")
    # Calculate result
    call_calculator(number_1, number_2, option)
