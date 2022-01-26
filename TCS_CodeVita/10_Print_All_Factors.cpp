#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    set<int>st;
    for(int i=1;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            if(n/i==i)
            {
                st.insert(i);
            }
            else
            {
                st.insert(i);
                st.insert(n/i);
            }
        }
    }
    for(auto it:st)
    {
        cout<<it<<" ";
    }
    return 0;
}