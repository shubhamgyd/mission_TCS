#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int count(int N,vector<vector<int>> A,vector<vector<int>> B) {
        // code here
        
        int n=N;
        int m=N;
        bool ok=true;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(A[i][j]!=B[i][j])
                {
                    ok=false;
                }
            }
        }
        if(ok) return 0;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
          map<pair<int,int>,int>mp;
            for(int j=0;j<m;j++)
            {
                if(A[i][j]!=B[i][j])
                {
                    pair<int,int>p=make_pair(B[i][j],A[i][j]);
                    pair<int,int>p1=make_pair(A[i][j],B[i][j]);
                    if(mp[p]>0)
                    {
                        cnt++;
                        mp[p]--;
                        // if(mp[p]==0)
                        // {
                        //     mp.erase(p);
                        // }
                    }
                    else
                    {
                        mp[p1]++;
                    }
                }
            }
            if(mp.size()>0)
            {
                return -1;
            }
        }
        return cnt;
        
    }   
};

int main()
{
    int x=log2(4096);
    cout<<x<<endl;
    int ans=15*x*x*x*x*x;
    int a=pow(x,7);
    cout<<ans<<endl;
    cout<<a<<endl;
    return 0;
}