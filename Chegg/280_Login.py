# to store user email and password
database = {}
while True:
    # Take choice for login or signup
    print("1. Login")
    print("2. Sign Up")
    # Read choice
    choice = int(input("Enter Choice: "))
    # If choice is 1
    if choice == 1:
        # Take email and password
        while True:
            email = input("Enter email: ")
            password = input("Enter passowrd: ")
            # Check email is in database or not
            # if present then validate password
            if email in database and database[email] != password:
                print("You have entered wrong email or password!!")
                print("Please try again !!")
            # if email and password matched
            elif email in database and database[email] == password:
                print("Successfull Login !!")
                break
            # Else email is not exist in database
            else:
                print("Look like you don't have account exist, please sign up first")
                break
            print()
    # if choice ==2
    elif choice == 2:
        # Read email and password
        email = input("Enter email: ")
        password = input("Enter passowrd: ")
        # Read password again
        rePassword = input("Please reenter password: ")
        # Validate password
        if password != rePassword:
            print("Password didn't matched please reenter passowrd again !!")
        # add user into database
        else:
            print("User added successfully !!")
            print("Successfully sign up!!")
            database[email] = password
        print()
    else:
        break
