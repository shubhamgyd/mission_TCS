# Helper function which find next k elements are smaller or not
def hotels(n,k,a):
    # store the indices
    ans=[]
    # iterate array
    for j in range(n):
        # if k elements are available
        if j+k<=n-1:
            cnt=0
            # count if next k elements are smaller than current element or not
            for l in range(j+1,j+k+1):
                # if smaller then increase the count
                if a[l]<a[j]:
                    cnt=cnt+1
            # if total count is k
            # then append the index to answer
            if cnt==k:
                ans.append(j)
        # if not sufficient k elements are available
        # then check all next remaining elements are strictly shorter than current element or not
        else:
            cnt=0
            # count if next k elements are smaller than current element or not
            for l in range(j+1,n):
                # if smaller then increase the count
                if a[l]<a[j]:
                    cnt=cnt+1
            # if all remaining elements are strictly lesser than the current element
            # append its index
            if cnt==n-j-1:
                ans.append(j)
    # return ans
    return ans

# no of test cases
for i in range(int(input())):
    # input of n,k
    n,k=map(int,input().split())
    # input of list
    a = list(map(int,input().strip().split()))[:n]
    # getting ans
    ans=hotels(n,k,a)
    # printing ans
    for num in ans:
        print(num,end=" ")
    print()
