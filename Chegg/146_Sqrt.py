import math
# To find the square root of numbers
# get beautiful number
while True:
    beautiful_number = input("tell me a beautiful number: ")
    # convert it into float
    beautiful_number = float(beautiful_number)
    # print number and its square root
    print('The beautiful number %.3f squared root is %.3f' %
          (beautiful_number, math.sqrt(beautiful_number)))
    # If user want to find more
    nextNumber = str(
        input("\nWant to find square root of other beautiful numbers(Y or N)"))
    if nextNumber == 'Y':
        print("\n")
        continue
    # else break
    else:
        break
