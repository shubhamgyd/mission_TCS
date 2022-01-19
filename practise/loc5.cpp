#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<char,int>&a,pair<char,int>&b)
{
    return a.second>b.second;

}

int maximumProduct(int N,string S)
{
    map<char,int>mp;
    for(auto it:S)
    {
        mp[it]++;
    }
    vector<pair<char,int>>res(mp.begin(),mp.end());
    sort(res.begin(),res.end(),cmp);
    int num1=res[0].second;
    int num2=res[1].second;
    return num1*num2;
}

int main()
{
    int n;
    cin>>n;
    string str;
    cin>>str;
    cout<<maximumProduct(n,str)<<endl;
    return 0;
}
