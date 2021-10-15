#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin>>n;
    vector<vector<int>>res(n,vector<int>(n));
    string ans="";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int a;
            cin>>a;
            res[i][j]=a;
        }
    }
    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(res[i][j]==0)
            {
                if(i>0 && i<n-1 && j>0 && j<n-1)
                {
                    if(res[i-1][j]==1 && res[i][j-1]==1 && res[i][j+1]==1 && res[i+1][j]==1)
                    {
                        count++;
                    }
                }
            }
        }
    }
    cout<<count<<endl;
    return 0;

}