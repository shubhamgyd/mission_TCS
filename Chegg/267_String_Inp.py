# Read until valid input
while True:
    # Read favorite food
    favoriteFood = input("Enter your favorite food: ")
    # if invalid input
    if favoriteFood != "broccoli":
        print("Try again")
    # else valid input
    else:
        print("Good choice")
        break
