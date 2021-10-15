
#include <bits/stdc++.h>
using namespace std;

int Mod(string str,int n)
{
    int r=0;
    for(int i=0;i<str.length();i++)
    {
        r=r*10+(str[i]-'0');
        r%=n;
    }
    return r;
}

string solve(int n)
{
    queue<string>q;
    set<int>st;

    string str="1";
    q.push(str);

    while(!q.empty())
    {
        auto curr=q.front();
        q.pop();

        int temp=Mod(curr,n);

        if(temp==0)
        {
            return curr;
        }

        else if(st.find(temp)==st.end())
        {
            st.insert(temp);
            q.push(curr+"0");
            q.push(curr+"1");
        }
    }
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.out", "w", stdout);
#endif
    int n;
    cin>>n;
    cout<<solve(n)<<endl;
	return 0;
}
// Time Complexity :O(2^n)