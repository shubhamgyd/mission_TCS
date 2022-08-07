a=0
b=4
for i in range(7):                             #iterate rows
    for j in range(7):                         #iterate columns
        if j==0 or (i==j+2 and j>1):
            print("@",end="")                  #display symbol
        elif((i==a and j==b) and j>0):
            print("@",end="")                  #display symbol
            a=a+1
            b=b-1
        else:
            print(end=" ")
    print()