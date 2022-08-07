#include<bits/stdc++.h>
using namespace std;

int maxCost(string s)
{
    int rightZeros=0,leftOnes=0;
    for(char ch:s)
    {
        if(ch=='0') rightZeros++;
    }
    int cost=0;
    for(int i=0;i<s.size()-1;++i)
    {
        if(s[i]=='1') leftOnes++;
        else rightZeros--;
        cost=max(cost,abs(leftOnes-rightZeros));
    }
    return cost;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    cout<<maxCost(s)<<endl;
    return 0;
}