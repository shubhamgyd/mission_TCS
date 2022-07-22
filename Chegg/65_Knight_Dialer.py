# numpay import to make 2d array
import numpy as np
Mod = (10**9 + 7)
singleMove = np.zeros((10, 10), dtype=np.int64)
# pre jumps
# which representing single move
for i, j in ((1, 8), (1, 6), (2, 7), (2, 9), (3, 4), (3, 8), (4, 9), (4, 0), (6, 7), (6, 0)):
    singleMove[i][j] = 1
    singleMove[j][i] = 1
class Solve:
    def kDialer(n) -> int:
        # because number of moves is the length of string minus 1
        n-=1

        # now multiplying that move matrix by itself represents 2 moves
        # doing that n times, represents 2**n moves
        currentMove = singleMove
        sumationMoves = np.ones((10,), dtype=np.int64)
        # till valid jumps
        while n > 0:
            # if odd
            if n & 1:
                sumationMoves = np.matmul(sumationMoves, currentMove)
                sumationMoves = np.mod(sumationMoves, Mod)
            # divide by 2
            n >>= 1
            #  if even
            if n > 0:
                currentMove = np.matmul(currentMove, currentMove)
                currentMove = np.mod(currentMove, Mod)
        # take mod
        return np.sum(sumationMoves) % Mod



n=int(input("Enter Number: "))
ans=Solve.kDialer(n)
print("Distinct phone numbers of length "+str(n)+ ": "+str(ans))