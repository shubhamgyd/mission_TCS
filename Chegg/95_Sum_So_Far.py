# keep track of total sum so far
totalSoFar=0
# running code infinite times
while True:
    # taking input of a string number
    num=input("Please enter a number or \"stop\": ")
    # if input is stop then terminate program
    if num=="stop":
        break
    # else convert string to integer
    else:
        # convert string to integer using eval
        num=eval(num)
        # adding it to total sum so far
        totalSoFar=totalSoFar+num
        # prining result
        print(f"the total so far is: {totalSoFar}")
