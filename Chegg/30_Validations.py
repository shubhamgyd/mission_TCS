
# regex library for validations of characters
import re

#initial condition 
game_active=True


# run program until user want
while game_active:

    # uner input
    number=input("Please Enter a number: ")

    # Make own character set and pass 
    # this as argument in compile method
    regex = re.compile('[@_!#$%^&*()<>?/\|}{~:]')

    # if input string contains any alphabet but not any special character
    # prompt a python exception and take input again
    if any(c.isalpha() for c in number) and (regex.search(number)==None):
        print("Caught a python exception. Please re-enter a valid number\n")


    # if input string contains any special character but not contain any alphabets
    # then prompt a type-1 python exception
    elif(regex.search(number)!=None) and not (any(c.isalpha() for c in number)):
        print("Caught a user-defined exception <Type-1>. Please re-enter a valid number\n")

    # if unput string contains both specail characters and alphabets
    # then promt a type-2 python exception
    elif( ( regex.search(number)!=None) and any(c.isalpha() for c in number) ):
        print("Caught a user-defined exception <Type-2>. Please re-enter a valid number\n")
    

    else:
        # eval parse the expression arguement and evaluated it's python expression
        n=eval(number)

        # print absoluter value
        print("Absolute value of your number is: ",abs(n))

        # flag to keep track on user want to terminate the program or not
        terminate=False

        # promt until user don't enter valid input
        while True:
            Next=input("Do you want to continue?(yes/no): ")
            # according to conditon program are accepting only lower case characers
            # if it found any  upper character in input string then it will ask to user again
            # and again
            if not any(c.isupper() for c in Next):
                if Next=="y" or Next=="yes":
                    terminate=False
                    break
                else:
                    terminate=True
                    break

        # if user want to terminate the program
        if(terminate==True):
            print("Exiting the program..!!!")
            break
    
