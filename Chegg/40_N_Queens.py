import numpy as np




def solution(n):

    def solveNQueens(row,n):
        if row==n:
            print("here")
            res.append(nQueens)
            a=np.array(nQueens)
            print(a)
            return
        
        for col in range(n):
            if isValid(row,col,n):
                nQueens[row][col] = 'Q';
                solveNQueens(row + 1, n);
                nQueens[row][col] = '.';


    def isValid(row,col,n):
        # check if the column had a queen before.
        for i in range(0,row):
            if nQueens[i][col] == 'Q':
                return False
        

        # check if the 45° diagonal had a queen before.
        for i in range(row-1,-1,-1):
            for j in range(col-1,-1,-1):
                if nQueens[i][j] == 'Q': 
                    return False

        # check if the 135° diagonal had a queen before.
        for i in range(row-1,-1,-1):
            for j in range(col+1,n):
                if nQueens[i][j] == 'Q':
                    return False
        
        return True

    solveNQueens(0,n)
    
    # for i in range(len(res)):
    #     for j in range(len(res[i])):
    #         arr=np.array(res[i])
    #         print(arr)





n=int(input("Enter a number of queens: "))
res=[]
for i in range(n):
    res.append([])
    for j in range(n):
        res[i].append([])
    
nQueens=[]
for i in range(n):
    nQueens.append([])
    for j in range(n):
        nQueens[i].append('.')

s=np.array(nQueens)
ans=solution(n)
# print(ans)
