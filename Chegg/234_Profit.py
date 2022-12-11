# Read n and p
n, p = input().split()
# Typecast str to int
n = int(n)
# Read the investment prices
a = list(map(str, input().split()))[:n]
# Read profit prices
b = list(map(str, input().split()))[:n]
# typecast str to int of investment prices
for i in range(len(a)):
    a[i] = int(a[i][1:])
# typecast str to int of profit
for i in range(len(b)):
    b[i] = int(b[i][1:])
# get totalprofit
totalProfit = 0
# keep track on we have invested in ith project or not
visited = [0]*n
# available money
money = int(p[1:])
# Iterate until we invest
while True:
    # Check we can invest or not
    canInvest = 0
    minInvestment = float('inf')
    # get profit of min value price project
    profit = 0
    # get index of invested project
    ind = 0
    # Iterate projects
    for i in range(n):
        # Check we have not invested earlier in this project and the invested money required to this project
        # is less than or equal to the available money
        if visited[i] == 0 and money >= a[i]:
            # get all details 
            profit = b[i]
            ind = i
            canInvest = 1
    # if we can invest then get totalProfit
    # get initial money back + profit of ith project
    # and mark ith project as visited
    if canInvest == 1:
        totalProfit += profit
        money += profit
        visited[ind] = 1
    # else break loop
    else:
        break

# Display total Profit
totalProfit = "$"+str(totalProfit)
print(totalProfit)



# Time Complexity:O(n*n)
# Explanation:
#             We are iterating n*n times to check we can invest in any project or not, Hence overall time complexity:O(n*n)