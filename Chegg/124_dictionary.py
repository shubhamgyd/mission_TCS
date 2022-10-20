import os
import random
accounts = {'sgpham': {'Pin': 9999, 'Name': 'Giang Pham', 'C': 1000, 'S': 3000},
            'qspham': {'Pin': 8888, 'Name': 'Son Giang', 'C': 2000, 'S': 4000}}

pin = 0

ans = ''

# Allow 3 invalid pin entries

tries = 1
pin_tries = 1
max_tries = 3
pin_found = False

username = input("Welcome to Cactus Bank. Please enter your username: ")

if username not in accounts:
    print(f"{username}, Didn't find your username.")
    ans = input("Do you want to create an account (Y/N)? ").lower()
    if ans[0] != 'y':
        print("Thank you for visiting Catcus Bank. Come back soon.")
        tries = max_tries + 1
    else:
        newUser = dict()
        newUser[username] = dict()
        ans1 = int(input(
            'Enter 1 to create a pin yourself or 2 and the system will create a pin for you: '))
        if ans1 == 1:
            while pin_tries <= max_tries:
                pin = int(
                    input('Select a number between 1 and 9999 as your pin: '))
                print(pin)
                if pin > 0 and pin < 10000:
                    newUser[username]["Pin"] = pin
                    pin_found = True
                    pin_tries = max_tries + 1
                else:
                    print('Invalid pin entered.')
                    pin_tries += 1
                    if pin_tries > max_tries:
                        print('Please try later....')
            print("Your pin is: ", pin)
            newUser[username]["Pin"] = pin
            tries = 1
            pin_found = True
        if ans1 == 2:
            pin = random.randint(1, 9999)
            print("Your pin is: ", pin)
            newUser[username]["Pin"] = pin
            tries = 1
            pin_found = True
        else:
            print("Invalid option! Thank you for visiting Catcus Bank. Come back soon.")
            tries = max_tries + 1
    if pin_found:
        print("Please remember your pin.")
        print("The system will require you to enter it again.")
        input("Press Enter to continue...")
        # os.system("cls') for windows
        os.system('cls')
        name = input("Please enter your name:")
        while True:
            try:
                checking = float(
                    input('Enter the amount you will deposit to the checking account:'))
                if checking < 0:
                    raise TypeError
            except TypeError:
                print("A negative number was enter. The current balance will be 0.0")
                checking = 0.8
            except ValueError:
                print("Invalid number entered. The current balance will be 0.0")
                checking = 0.8
            break
        while True:
            try:
                saving = float(
                    input("Enter the amount you will deposit to the saving account."))
                if saving < 0:
                    raise TypeError
            except TypeError:
                print("A negative number was enter. The current balance will be 0.0")
                saving = 0.0
            except ValueError:
                print('Invalid number entered. The current balance will be 0.8')
                saving = 0.0
            break
        newUser[username]['Name'] = name
        newUser[username]['C'] = checking
        newUser[username]['S'] = saving
        accounts.update(newUser)
        print(accounts)
