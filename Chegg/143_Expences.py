# to store the revenue and expences of each quarter
dataList = []
# get totalRevenues
totalRevenues = 0
# get totalExpenses
totalExpenses = 0
# get input of 4 quarters
for i in range(1, 5):
    # get revenue of ith quarter
    revenue = int(input(f"Enter the revenues int the {i}th quarter: "))
    # get expenses of ith quarter
    expenses = int(input(f"Enter the expenses int the {i}th quarter: "))
    print("\n")
    # make list of revenue and expenses
    quarterList = [revenue, expenses]
    # add revenue into totalRevenue
    totalRevenues = totalRevenues+revenue
    # add expenses into totalExpenses
    totalExpenses = totalExpenses+expenses
    # add quarter list into data list
    dataList.append(quarterList)

# print data list
print(dataList)
print("\n")
# get profit
profit = totalRevenues-totalExpenses

# print totalRevenue and totalExpenses along with profit.
print(
    f"The total revenues are ${totalRevenues} and the total expenses are ${totalExpenses}. Your profit is ${profit}.")
