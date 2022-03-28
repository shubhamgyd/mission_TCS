from datetime import datetime, timedelta

def getPrimes(n):
    for i in range(2, n + 1):
        if primeFun(i):
            prime.append(i)

def primeFun(n):
    if n <= 1 :
        return False
    for i in range(2, n):
        if n % i == 0:
            return False
    return True
dated, dayofW, n= input().split()
n= int(n)
prime=[]
getPrimes(365)
daysdic={0:"Mon", 1:"Tue", 2:"Wed", 3:"Thu", 4:"Fri", 5:"Sat", 6:"Sun"}
dated=datetime.strptime(dated, "%Y%m%d")
days=-1
for i in prime:
    date= dated + timedelta(i)
    if primeFun(date.month) and daysdic[date.weekday()]==dayofW:
        days=i
        break
if days==-1:
    print("No", 0)
elif days<=n:
    print("Yes", days)
else:
    print("No", days)