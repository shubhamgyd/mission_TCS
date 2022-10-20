import random

# a


def generateA():
    return random.randint(0, 5)  # using random module

# b


def generateB():
    return random.randint(0, 8)  # using random module

# c


def useBotA():
    num = generateB() % 6
    print("Random number is :", num)  # using generateB function
    return num

# d


def useAtoB():
    num = (generateA()+generateA()) % 9  # using generateA functions
    print("Random number is: ", num)
    return num


print("Call generateA() function.")
print("Random number is: ", generateA())
print("Call generateB() function.")
print("Random Number is: ", generateB())
print("Call useAtoB() function")
useAtoB()
print("Call userBtoA function")
useBotA()
