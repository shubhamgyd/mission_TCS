#include<bits/stdc++.h>
using namespace std;


// Recursive approach
int power(int a,int b)
{
    // base case
    if(b==0)
    {
        return 1;
    }
    int X=power(a,b/2);
    if(b&1)
    {
        return X*X*a;
    }
    else
    {
        return X*X;
    }
}
// Time Complexity:O(logn)
// Space Complexity:O(logn)




// Iterative
int Power(int a,int b)
{
    int ans=1;
    while(b>0)
    {
        if(b&1)
        {
            ans*=a;
        }
        b>>=1;
        a*=a;
    }
    return ans;
}
// Time Complexity:O(logn)
// Space Complexity:O(1)



int main()
{
    int a,b;
    cin>>a>>b;
    int ans=power(a,b);
    cout<<ans<<endl;

    int ans1=Power(a,b);
    cout<<ans1<<endl;
    return 0;
}