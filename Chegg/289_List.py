n = 0
queries = [[]]
res = [[0]*n]*n
for i in range(len(queries)):
    r1 = queries[i][0]
    c1 = queries[i][1]
    r2 = queries[i][2]
    c2 = queries[i][3]
    res[r1][c1] = res[r1][c1]+1
    if (c2+1 < n):
        res[r1][c2+1] = res[r1][c2+1]+1
    if (r2+1 < n):
        res[r2+1][c1] = res[r2+1][c1]-1
    if (r2+1 < n and c2+1 < n):
        res[r2+1][c2+1] = res[r2+1][c2+1]+1

for i in range(n):
    for j in range(1, n):
        res[i][j] += res[i][j-1]

for i in range(1, n):
    for j in range(0, n):
        res[i][j] += res[i-1][j]
return res
