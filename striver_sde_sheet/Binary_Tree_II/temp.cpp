#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<string>str;
    cin.ignore();
    for(int i=0;i<n;i++)
    {
        string s;
        getline(cin,s);
        str.push_back(s);
    }
    
    string word,word1;
    cin>>word>>word1;
    // word, (index,line no);
    map<string,pair<int,int>>mp;
    map<int,map<int,string>>wordTracker;
    for(int i=0;i<n;i++)
    {
        stringstream ss(str[i]);
        string word;
        int cnt=0;
        while(ss>>word)
        {
            mp[word]={cnt,i};
            wordTracker[i][cnt]=word;
            cnt++;
        }
    }
    int col=mp[word].first;
    int wordCol=mp[word1].first;
    int diff=col-wordCol;
    int line=mp[word1].second;
    diff++;
    string ans=wordTracker[line][col+diff];
    cout<<ans<<endl;
    return 0;
}