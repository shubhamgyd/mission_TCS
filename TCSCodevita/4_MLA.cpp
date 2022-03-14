#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m1,m2;
    cin>>m1>>m2;
    int N;
    cin>>N;
    map<int,int> mp;
    vector<int> vect;
    for(int i=0;i<N;i++)
    {
        int val;
        cin>>val;
        vect.push_back(val);
        mp[val] = i;
    }
    sort(vect.begin(),vect.end(),greater<int>());
    vector<pair<int,int>>first,second;
    if(m1<m2)
    {
        int turn=0;
        for(int i=0;i<N;i++)
        {
            if(turn==0)
            {
                first.push_back({i,vect[i]});
                turn=1;
            }
            else if(turn==1)
            {
                second.push_back({i,vect[i]});
                turn=0;
            }
        }
        // sort(first.begin(),first.end());
        // sort(second.begin(),second.end());
        for(auto it:first)
        {
            cout<<it.second<<" ";
        }
        cout<<endl;
        for(auto it:second)
        {
            cout<<it.second<<" ";
        }
    }
    else if(m1>m2)
    {
        int turn=0;
        for(int i=0;i<N;i++)
        {
            if(turn==0)
            {
                second.push_back({i,vect[i]});
                turn=1;
            }
            else if(turn==1)
            {
                
                first.push_back({i,vect[i]});
                turn=0;
            }
        }
        // sort(first.begin(),first.end());
        // sort(second.begin(),second.end());
        for(auto it:first)
        {
            cout<<it.second<<" ";
        }
        cout<<endl;
        for(auto it:second)
        {
            cout<<it.second<<" ";
        }
    }
    return 0;
}