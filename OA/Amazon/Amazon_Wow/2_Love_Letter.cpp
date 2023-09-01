#include<bits/stdc++.h>
using namespace std;

void leftrotate(string &s, int d)
{
    reverse(s.begin(), s.begin()+d);
    reverse(s.begin()+d, s.end());
    reverse(s.begin(), s.end());
}

void rightrotate(string &s, int d)
{
   leftrotate(s, s.length()-d);
}
int main()
{
    string str;
    getline(cin,str);
    int k;
    cin>>k;
    unordered_map<string,int>mp;
    stringstream ss(str);
    string word;
    while(ss>>word)
    {
        mp[word]++;
    }
    stringstream ss1(str);
    int cnt=0;
    while(ss1>>word)
    {
        rightrotate(word,k);
        if(mp.find(word)!=mp.end()) cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}