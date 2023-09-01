# import collections

# def split_pairs(arr):
#     if len(arr) % 2 == 1: # odd length
#         return False
#     counter = collections.Counter(arr) #  'num': freq - '1': 2
#     prev_freq = None
#     for num,cur_freq in counter.items():
#         if prev_freq and prev_freq != cur_freq:
#             return False
#         prev_freq = cur_freq
#     return True

# arr = [1, 1, 2, 2]
# print(split_pairs(arr)) # True
# arr = [3, 3, 4, 4]
# print(split_pairs(arr)) # True
# arr = [1, 4, 5, 4, 5, 1]
# print(split_pairs(arr)) # True



from collections import defaultdict 
import bisect

def minoperations (N, A, K): # Write your code here
    dic=defaultdict(list) 
    for i,v in enumerate(A):
        temp=i%K
        idx=bisect.bisect_right(dic[temp],v) 
        if(idx==len(dic[temp])):
            dic[temp].append (v) 
        else:
            dic[temp][idx]=v
    res=0
    for key,val in dic.items():
        l=(N-1-key)//K+1
        res+=l-len(val)
    return res

T= int(input())
for _ in range(T):
    N = int(input())
    A=list(map(int, input().split()))
    K = int(input())
    out_=minoperations (N, A, K) 
    print(out_)