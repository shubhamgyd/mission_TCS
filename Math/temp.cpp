#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<string>ans;
    string str;
    getline(cin,str);
    stringstream ss(str);
    string word;
    while(ss>>word)
    {
        ans.push_back(word);
    }
    reverse(ans.begin(),ans.end());
    string finalAns="";
    for(auto it:ans)
    {
        finalAns+=it+" ";
    }
    finalAns.pop_back();
    cout<<finalAns<<endl;
    return 0;
}