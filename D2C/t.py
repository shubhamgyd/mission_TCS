import math
n,cost=map(int,input().split(" "))
pages=[]
prices = list(map(int,input().strip().split()))[:n] 
pages = list(map(int,input().strip().split()))[:n] 

prev=[0]*(cost+1)
curr=[0]*(cost+1)
for i in range(1,n+1):
    for j in range(1,cost+1):
        if prices[i-1]<=j:
            curr[j]=max(prev[j],pages[i-1]+prev[j-prices[i-1]])
        else:
            curr[j]=prev[j]
    prev,curr=curr,prev
print(prev[cost])