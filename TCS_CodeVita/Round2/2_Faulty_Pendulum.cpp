#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin>>n;
    int force;
    string dir;
    cin>>force>>dir;
    vector<int>res(n);
    for(int i=0;i<n;i++)
    {
        cin>>res[i];
    }
    bitset<100000001>canPossible;
    canPossible[0]=true;
    for(int id=0;id<n;id++)
    {
        canPossible|=(canPossible<<res[id]);
    }
    if(canPossible[force])
    {
        cout<<"Possible";
    }
    else
    {
        cout<<"Not Possible";
    }
}