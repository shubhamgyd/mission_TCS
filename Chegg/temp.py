import statistics
lstx = []
lsty = []
lstz = []

file = open("articles.txt", "r")
hvk = file.read()

k = 0
for i in hvk:
    # print(hvk[1])
    j = ord(hvk[k])
    lstx.append()
    k += 1

# print(Isty)
file.close()


def prime(N):
    for i in range(2, N):
        if N % i == 0:
            return lstz.append(N)
    return lsty.append(N)


for N in lstx:
    prime(N)

lstw = []
for i in lsty:
    if i not in lstw:
        lstw.append(i)

# Another list to store the elements by 2nd column wise
modifiedList = []
for i in lstw:
    temp = []
    temp.append(lsty.count(i))
    temp.append(i)
    modifiedList.append(temp)

# sort modified list according to the 2nd column(ascending order)
modifiedList.sort()
# nor print data
for i in modifiedList:
    print("{}\t{}".format(i[1], i[0]))


def soldieratk(num, soldierPosition, posSoldier):
    n = num
    a = soldierPosition
    arr = []
    arr.append(0)
    for i in range(1, n+1):
        arr.append(i)
    for i in range(len(soldierPosition)):
        arr[a[i][0]:a[i][1]+1] = arr[a[i][0]:a[i][1]+1][::-1]
    arr.pop(0)
    return arr[posSoldier-1]


print(lstw)
print("Mean: {}".format(statistics.mean(lsty)), end=" ")
print(' Varience: {}'.format(statistics.variance(lsty)))
