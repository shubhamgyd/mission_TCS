/*
A Z sequence is defined as:
Zi=P×X(Zi−1)+Q for i>0
Zi = 2 for i=0
X(K) is defined as the number of set bits in the binary form of a number K.
Print the number of set bits in the binary form of ZN
Example
N = 2
P = 1
Q = 3
Approach
So , Z[0] = 2 , Z[1] = PX[2]+Q. Now X[2] = 1 as 2 can be written as 10 in binary form So, Z[1] = 11+3 = 4 . Similarly , Z[2] = PX[4]+Q .Now 4 can be written as 100 . So , Z[2] = 11+3 = 4. Now answer is the number of set bits in Z[2] = 4, so 1.
EXAMPLE:
Sample input
1
3 5 1
Sample output
1
Explanation
Based on expression, sequence will be like 2, 8, 8,...
As N=1 so Z1 is 8 Number of set bits in 8(i.e 1000) is 1
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    
}