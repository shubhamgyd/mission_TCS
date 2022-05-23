#include<bits/stdc++.h>
using namespace std;

bool test(int x,int y)
{
    return abs(x%10)==abs(y%10);
}


int main()
{
    int i=1;
    int j=1;
    while(i<=3)
    {
        while(j<=3)
        {
            cout<<i;
            j++;
        }
        i++;
        cout<<j;
        cout<<endl;
        j=1;
    }
}
/*
Time Complexity:O(nlogn)
Auxilary Space : O(1)



Input and Output:
Input:
5
4 2 8 3 1


Output:
1 2 3 4 8 


*/