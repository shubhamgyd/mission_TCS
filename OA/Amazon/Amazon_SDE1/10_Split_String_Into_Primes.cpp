#include<bits/stdc++.h>
using namespace std;

vector<bool> pr(1001,true);
void primes()
{
    pr[0]=pr[1]=false;
    
    for(int i=2;i*i<=1000;i++)
    {
        if(pr[i]==true)
        {
            for(int j=i*i;j<=1000;j+=i)
            {
                pr[j]=false;
            }
        }
    }
}

unordered_map<string,int> dp;

int ways(string s)
{
    char arr[50];
    for(int i=0;i<s.length();i++)
    {
        arr[i]=s[i];
        cout<<arr[i];
    }
    cout<<endl;
    if(s.size()==0)
        return 1;
    if(dp.find(s)!=dp.end())
        return dp[s];
        
    int ans=0;
    
    for(int i=1;i<=s.size();i++)
    {
        string to_check=s.substr(0,i);
        int num=stoi(to_check);
        
        if(to_check[0]!='0' and num<=1000 and pr[num]==true)
            ans+=ways(s.substr(i));
    }
    
    return dp[s]=ans;
}

int main()
{
    primes();
    string s;
    cin>>s;
    cout<<ways(s);
}