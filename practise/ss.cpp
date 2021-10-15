#include <bits/stdc++.h>
using namespace std;


int main()
{
// #ifndef ONLINE_JUDGE
//     freopen("inputf.in", "r", stdin);
//     freopen("outputf.out", "w", stdout);
// #endif
    vector<string>res;
    int n;
    cout<<"Enter size of wordset: ";
    cin>>n;
    // cout<<n<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"\nEnter string for wordset: ";
        string str;
        cin>>str;
        res.push_back(str);
    }
    int m;
    cout<<"\nEnter size of sentence: ";
    cin>>m;
    // cout<<m<<endl;
    vector<string>sentence;
    for(int i=0;i<m+1;i++)
    {
        cout<<"\n Enter sentence: ";
        string str1;
        getline(cin,str1);
        cout<<str1<<endl;
        sentence.push_back(str1);
    }
    map<string,int>mp;
    for(int i=0;i<n;i++)
    {
        string str=res[i];
        sort(str.begin(),str.end());
        mp[str]++;
    }
    for(int i=0;i<m+1;i++)
    {
        int ct=0;
        stringstream ss;
        ss<<sentence[i];
        string word;
        while(ss>>word)
        {
            // cout<<word<<" ";
            sort(word.begin(),word.end());
            if(mp[word]>1)
            {
                ct+=mp[word];
            }
        }
        cout<<ct<<endl;
    }

    return 0;

}