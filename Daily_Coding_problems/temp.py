import math
from os import stat
def lockerMusic( n: int):
    cnt=2
    state=["O"]*n
    for i in range(2,n+1):
            if (math.log(i,cnt))%2==0:
                state[i-1]="O"
                cnt+=1
            else:
                state[i-1]="C"
    ct=0;
    for i in range(0,n):
        if state[i]=="O":
            ct=ct+1
    print(ct)
    print(state)

lockerMusic(67)