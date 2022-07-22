#include<bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string str;
    cin>>str;
    int q;
    cin>>q;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        char ch;
        cin>>ch;
        if(ch=='L')
        {
            for(int i=l;i<=r;i++)
            {
                if(str[i]=='a') str[i]='z';
                else str[i]=--str[i];
            }
        }
        if(ch=='R')
        {
            for(int i=l;i<=r;i++)
            {
                if(str[i]=='z') str[i]='a';
                else str[i]=++str[i];
            }
        }
        // cout<<str<<endl;
    }
    cout<<str<<endl;
    return 0;
}