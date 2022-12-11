# Input t test cases
t = int(input())
# Iterate
for _ in range(t):
    # get size of array
    n = int(input())
    # input n space seperated integers(i.e. score)
    playerScores = list(map(int, input().split()))[:n]
    # store the maximum product
    maxProduct = playerScores[0]
    #  currMax/currMin stores the max/min product of
    #  subarray that ends with the current number playerScore[i]
    currMax = maxProduct
    currMin = maxProduct
    for i in range(1, n):
        #  multiplied by a negative makes big number smaller, small number bigger
        #  so we redefine the extremums by swapping them
        if playerScores[i] < 0:
            currMax, currMin = currMin, currMax
        #  max/min product for the current number is either the current number itself
        #  or the max/min by the previous number times the current one
        currMax = max(playerScores[i], currMax*playerScores[i])
        currMin = min(playerScores[i], currMin*playerScores[i])

        # Update the maxProduct value by comparing it with the currMax
        maxProduct = max(maxProduct, currMax)
    # Print maxProduct subarray value
    print(maxProduct)
