global count 
count = 0

def solve(arr, i, idx, n):
    global count
    if idx == n:
        return

    if arr[idx] % i != 0:
        arr[idx] += 1
        count += 1
        solve(arr, i, idx, n)
        arr[idx] -= 1

    else:
        solve(arr, i ,idx + 1, n)
    




arr = [3, 8, 7, 6, 4]
#arr.sort()
if arr[0] == arr[-1]:
    print(0)
    #return 
    

n = len(arr)
'''
solve(arr, , 0, n)
print (count)
print(arr)
'''

ans = float('inf')
for i in range(2, 50):
    count = 0
    solve(arr, i, 0, n)
    ans = min(ans, count)

print(ans)