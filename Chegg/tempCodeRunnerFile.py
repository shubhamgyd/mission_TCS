import random
l = []
for i in range(1, 11):
    temp = []
    num = random.randint(1, 50)
    temp.append(num)
    temp.append(i)
    l.append(temp)
l.sort()
for i in l:
    print(i[1], i[0])
