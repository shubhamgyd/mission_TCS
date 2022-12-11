import random 
# Function which returns the maximum number
def FindMaxNumber(array):
    mx=0
    # iterate array and update element with the mx
    for num in array:
        mx=max(mx,num)
    # return mx
    return mx

# main method to gnerate 10 integers in between ranges
def main():
    # array of size 10
    array=[0]*10
    # Iterate 10 times and generate number
    for i in range(10):
        # generate random integer
        num=random.randint(1,100)
        # append into array
        array[i]=num
    # print array
    print("\nGenerate Array: "+str(array))
    # get maximum nummber
    maxNum=FindMaxNumber(array)
    # print maximum number
    print("Max Num: "+str(maxNum))

main()

    
    