# Print Full stair case pattern
def staircase(n):
    for i in range(0, n+1):
        # Print n-i spaces before #
        for j in range(0, n-i):
            print(end=" ")
        # Print i # in current line
        for k in range(1, i+1):
            print("# ", end="")
        # carriage return
        print("\r")


# M a i n    P r o g r a m
staircase(int(input('n: ')))
