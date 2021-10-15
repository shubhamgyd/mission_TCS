// In this program we are going to see the prime factorisation of a number
#include<bits/stdc++.h>
using namespace std;

vector<int> factors(int n) {
    vector<int> f;
    for (int x = 2; x*x <=n; x++) 
    {
        while (n%x == 0) 
        {
            //cout<<x<<" ";
            f.push_back(x);
            n /= x;
        }
    }
    if (n > 1) f.push_back(n);
    return f;
}

int main()
{

    // for(int i=101;i<=200;i++)
    // {
    int n;
    cin>>n;
    if(n==1)
    {
        cout<<0<<endl;
        return 0;
    }
    vector<int>v=factors(n);
    sort(v.begin(),v.end());
    for(auto it:v)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    set<int>st;
    for(int i=0;i<v.size();i++)
    {
        if(st.find(n-v[i])!=st.end())
        {
            //return {v[i],n-v[i]};
            cout<<v[i]<<" "<<n-v[i]<<endl;
            break;
        }
        st.insert(v[i]);
    }
    return {};
    //}
    return 0;
}