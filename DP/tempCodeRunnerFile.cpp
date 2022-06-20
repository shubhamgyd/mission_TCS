#include<bits/stdc++.h>
using namespace std;

int main()
{
    string x,y;
    cin>>x>>y;
    int n=x.length();
    int m=y.length();
    for(int i=0;i<n-m;i++)
    {
        string s=x.substr(i,m);
        if(s==y)
        {
            cout<<"yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}