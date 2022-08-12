#include<bits/stdc++.h>
using namespace std;

int helper(int ind,string str,int hash[])
{
    // base case
    
}

int main()
{
    cout<<"Enter String: ";
    string str;
    getline(cin,str);
    transform(str.begin(),str.end(),str.begin(),::tolower);
    int hash[26];
    memset(hash,0,sizeof(hash));
    int ans=helper(0,str,hash);
    cout<<"This string contains "<<ans<<" unique letters."<<endl;
    return 0;
}