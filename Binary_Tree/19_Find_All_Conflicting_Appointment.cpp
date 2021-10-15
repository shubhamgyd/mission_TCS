#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n=5;
    int s[n];
    int f[n];
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
        cin>>f[i];
    }
    for(int i=1;i<n;i++)
    {
        int k=0;
        while(k<i)
        {
            if(s[i]<f[k])
            {
                cout<<s[i]<<" "<<f[i]<<" Conflicts with "<<s[k]<<" "<<f[k]<<endl;
                break;
            }
            k++;
        }
    }
    
}