/*
A frog is attempting to cross a river to reach the other side. Within the river, 
there are stones located at different positions given by a stones array 
(this array is in sorted order). Starting on the first stone (i.e. stones[0]), 
the frog makes a jump of size one potentially landing on the next stone. 
If the frog’s last jump was of size x, the frog’s next jump may be of size x - 1, 
x, or x + 1. Given these following conditions return whether or not the frog can reach 
the other side.
Note: The frog may only jump in the forward direction.

Ex: Given the following stones…

stones = [0, 1, 10], return false.
This question is asked by Amazon. The frog can jump from stone 0 to stone 1, 
but then the gap is too far to jump to the last stone (i.e. the stone at position 10)
Ex: Given the following stones…

stones = [0, 1, 2, 4], return true.
The frog can jump from stone 0, to stone 1, to stone 2, to stone 4.
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>res(n);
    for(int i=0;i<n;i++)
    {
        cin>>res[i];
    }

    bool ok=false;
    int i=0;
    int num=res[0];
    while(i<n)
    {
        
    }
}