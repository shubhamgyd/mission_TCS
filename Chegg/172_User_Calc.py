
# parse_user input string
def parse_input(user_input):
    # split the string into list using split
    input_list = user_input.split(' ')
    # get total elements of list
    elements = len(input_list)
    # if list doesn't contains 3 elements
    if elements != 3:
        print("Input does not consist of 3 elements")
        return
    # if operator is not valid
    # operator is located at index 1
    if input_list[1] != "*" and input_list[1] != "/" and input_list[1] != "+" and input_list[1] != "-":
        print(f"Hmmm, {input_list[1]} is not a valid operator")
        return
    # if index 0 or index 2 element is not a integer
    if not input_list[0].isdigit() or not input_list[2].isdigit():
        print("The first and third value must be a numbers")
        return
    # convert index 0 element into float
    first_float = float(input_list[0])
    # convert index 1 element into float
    second_float = float(input_list[2])

    # if operator +
    # return addition of both elements
    if input_list[1] == '+':
        print(first_float+second_float)

    # if operator -
    # return substraction of both elements
    if input_list[1] == '-':
        print(first_float-second_float)

    # if operator *
    # return multiplication of both elements
    if input_list[1] == '*':
        print(first_float*second_float)

    # if operator /
    # return division of both elements
    if input_list[1] == '/':
        print(first_float/second_float)


# Prompt user input
while True:
    # Input string
    user_input = input(">>> ")
    # If user string is quit
    # terminate program
    if (user_input == "quit"):
        break
    # validate the user input string
    parse_input(user_input)
