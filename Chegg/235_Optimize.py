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

# available money
money = int(p[1:])

# sort the projects according to the investment value
projectList = []
for i in range(n):
    # get ith project and append into the project list
    currentProject = []
    currentProject.append(a[i])
    currentProject.append(b[i])
    projectList.append(currentProject)
# sort all projects
projectList.sort()

for i in range(n):
    # if available money is greater than the ith project investment value
    # then get initial money + profit
    # also add the profit into total profit
    if money >= projectList[i][0]:
        money += projectList[i][1]
        totalProfit += projectList[i][1]


# Display total Profit
totalProfit = "$"+str(totalProfit)
print(totalProfit)


# Time Compexity:O(n*logn)
# Explanation: For sorting required (n*logn time) + we are taking O(n) to iterate projects
# Hence overall time xomplexity :O(n*logn)