# test case input
cases = int(input())
# Iterate t test cases times
for k in range(0, cases):
    # list to store according to Ada
    ada = []
    # list to store according to Charles
    charles = []
    # input of n fabrics
    n = int(input())
    for j in range(n):
        # get string input
        str = input()
        s = ""
        d = ""
        u = ""
        i = 0
        # split strin in words
        fabrics = str.split()
        # get color
        s = fabrics[0]
        # get durability
        d = fabrics[1]
        # get id
        u = fabrics[2]
        # for ada put color and id
        currAda = [s, u]
        # for charles pur durability and id
        currCharles = [d, u]

        # put into original lists
        ada.append(currAda)
        charles.append(currCharles)
    # sort list according to Ada's condition
    ada.sort()
    # sort list according to Charles's condition
    charles.sort()
    ans = 0
    # check in how many positions get common id
    for i in range(n):
        if ada[i][1] == charles[i][1]:
            ans = ans+1
    # Display output
    test = k+1
    print(f"Case #{test}: {ans}")
