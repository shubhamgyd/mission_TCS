#include<bits/stdc++.h>
using namespace std;
// const int MOD = 1e6;
// const int MAX = 1005;
// int catalan[MAX];
// void init() {
//     catalan[0] = catalan[1] = 1;
//     for (int i=2; i<=1005; i++) {
//         catalan[i] = 0;
//         for (int j=0; j < i; j++) {
//             catalan[i] += (catalan[j] * catalan[i-j-1]) % MOD;
//             if (catalan[i] >= MOD) {
//                 catalan[i] -= MOD;
//             }
//         }
//     }
// }

// int main()
// {
//     init();
//     int t;
//     scanf("%d",&t);
//     while(t)
//     {
//         // int n;
//         // scanf("%d",&n);
//         printf("%d\n",catalan[t]);
//         scanf("%d",&t);
//     }
//     return 0;
// }




int Catalan_Num(int n)
{
    // base case
    if(n<=1)
    {
        return 1;
    }

    int res=0;
    // now according to formula find nth catalan number
    // by using the formula n=catalan(i)8catalan(n-i);
    for(int i=0;i<n;i++)
    {
        res+=Catalan_Num(i)*Catalan_Num(n-i-1);
    }
    return res;
}
// Time Complexity :Exponential (2^n)






// Optimise Solution of catalan number
int Cat(int n)
{
    unsigned int dp[n+1];
    dp[0]=dp[1]=1;

    for(int i=2;i<=n;i++)
    {
        dp[i]=0;
        for(int j=0;j<i;j++)
        {
            dp[i]+=dp[j]*dp[i-j-1];
        }
    }
    return dp[n];
}
// Time Complexity :O(n*n)
// Space Complexity :O(n)




// Optimise Solution of Catalan Number by using binomial coefficient
unsigned int Binomial(unsigned int n,unsigned k)
{
    // let be C(n,k)==C(n,n-k)
    if(k>n-k)
    {
        k=n-k;
    }
    unsigned int ans=1;
    for(int i=0;i<k;i++)
    {
        ans*=(n-i);
        ans/=(i+1);
    }
    return ans;
}



int Cat1(int n)
{
    unsigned int c=Binomial(2*n,n);
    return c/(n+1);
}
// Time Complexity :O(n)
// Space Complexity :O(1)




// Optimise version
// void catalan(int n)
// {
//     cpp_int cat_ = 1;
 
//     // For the first number
//     cout << cat_ << " "; // C(0)
 
//     // Iterate till N
//     for (cpp_int i = 1; i < n; i++)
//     {
//         // Calculate the number
//         // and print it
//         cat_ *= (4 * i - 2);
//         cat_ /= (i + 1);
//         cout << cat_ << " ";
//     }
// }
// Time Complexity :O(n)
// Space Complexity :O(1)