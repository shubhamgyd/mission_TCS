#include<bits/stdc++.h>
using namespace std;

/*
Algorithm:

Let countDer(n) be count of derangements for n elements. Below is the recursive relation to it.  

countDer(n) = (n - 1) * [countDer(n - 1) + countDer(n - 2)]
How does above recursive relation work? 

There are n – 1 way for element 0 (this explains multiplication with n – 1). 
Let 0 be placed at index i. There are now two possibilities, depending on whether or not element i 
is placed at 0 in return. 

1.i is placed at 0: This case is equivalent to solving the problem for n-2 elements as two
 elements have just swapped their positions.
2.i is not placed at 0: This case is equivalent to solving the problem for n-1 elements as 
now there are n-1 elements, n-1 positions and every element has n-2 choices


*/

class Solution{
public:
    long int disarrange(int n){
        // code here
        // if(n<=1)
        // {
        //     return 0;
        // }
        // if(n==2)
        // {
        //     return 1;
        // }
        // return (n-1)*(disarrange(n-1)+disarrange(n-2));
        
        // long long int MOD=1000000007;
        // long int dp[n+1];
        // dp[1]=0;
        // dp[2]=1;
        // for(int i=3;i<=n;i++)
        // {
        //     dp[i]=((i-1)*(dp[i-1]%MOD+dp[i-2]%MOD)%MOD)%MOD;
        // }
        // return dp[n];
        
        if(n==1 || n==2)
        {
            return n-1;
        }
        long long int MOD=1000000007;
        long int a=0;
        long int b=1;
        for(int i=3;i<=n;i++)
        {
            long int curr=((i-1)*(a%MOD+b%MOD)%MOD)%MOD;
            a=b;
            b=curr;
        }
        return b;
    }
    
};

