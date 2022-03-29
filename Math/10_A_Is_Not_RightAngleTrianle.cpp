#include<iostream>
using namespace std;

int solve(int a)
{
    int ans=0;
    long long lim=(long long)(a*a);
    for(int x=1;x*x<=lim;x++)
    {
        if(a%x==0)
        {
            //x*y=a;
            long long y=lim/x;
            if(x<y && x%2==y%2)
            {
                long long C=(x+y)/2;
                long long B=(x-y)/2;
                // a*a+b*b==c*c
                ans++;
            }
        }
    }
    return ans;
}


int main()
{
    int a;
    cin>>a;
    int ans=solve(a);
    cout<<ans<<endl;
    return 0;
}