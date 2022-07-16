#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string str="";
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            int len=s.length();
            str.push_back(s[len-1]);
        }
        int sz=str.length();
        if(str[sz-1]=='0' or str[sz-1]=='5')
        {
            cout<<"Lucky"<<endl;
        }
        else
        {
            cout<<"Unlucky"<<endl;
        }
    }
}