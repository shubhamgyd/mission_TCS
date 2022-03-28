// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     cin>>n;
//     vector<int>res(n);
//     int one=0;
//     int zero=0;
//     for(int i=0;i<n;i++)
//     {
//         cin>>res[i];
//         if(res[i]==1)
//         {
//             one++;
//         }
//         else
//         {
//             zero++;
//         }
//     }
//     if(n%2==1)
//     {
//         if(one>0 && zero>0 && one-zero==1)
//         {
//             cout<<"YES"<<endl;
//         }
//         else
//         {
//             cout<<"NO"<<endl;
//         }
//     }
//     else
//     {
//         if(one>0 && zero>0 && one-zero==0)
//         {
//             cout<<"YES"<<endl;
//         }
//         else
//         {
//             cout<<"NO"<<endl;
//         }
//     }
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;


int main()
{
    string str;
    getline(cin,str);
    map<string,int>mp;
    stringstream ss(str);
    string word;
    while(ss>>word)
    {
        mp[word]++;
    }
    int mx=0;
    string ans="";
    for(auto it:mp)
    {
        if(it.second>mx)
        {
            mx=it.second;
            ans=it.first;
        }
    }
    cout<<ans<<endl;
    return 0;
}