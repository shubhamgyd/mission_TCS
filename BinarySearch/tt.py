import sys,os,io
import math 
from collections import defaultdict
def ii():
    return int(input())
def li():
    return list(map(int,input().split()))
if(os.path.exists('input.txt')):
    sys.stdin = open("input.txt","r") ; sys.stdout = open("output.txt","w") 
else:
    input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

import bisect
def lengthOfLIS(nums):
    x = []
    temp = [0]*(len(nums))
    for i in range(len(nums)):
        if not x:
            x.append(nums[i])
            temp[i]=len(x)
            continue 
        ind = bisect.bisect_left(x,nums[i])
        if ind==len(x):
            x.append(nums[i])
        else:
            x[ind]=nums[i]
        temp[i]=len(x)
    return temp

def lengthOfLDS(nums):
    x = []
    temp = [0]*(len(nums))
    for i in range(len(nums)):
        if not x:
            x.append(nums[i])
            temp[i]=len(x)
            continue 
        ind = bisect.bisect_left(x,nums[i])
        # replace bisect_left by bisect_right for longes non-dec subsequence
        if ind==len(x):
            x.append(nums[i])
        else:
            x[ind]=nums[i]
        temp[i]=len(x)
    return temp[::-1]

def solve():
    n = ii()
    l = li()
    a = lengthOfLIS(l)
    for i in range(n):
        l[i]=-l[i]
    l = l[::-1]
    b = lengthOfLDS(l)
    ans = 0
    for i in range(n-1):
        ans=max(ans,a[i]+b[i+1])
    print(ans)
        


t = 1
t = ii()
for _ in range(t):
    solve()