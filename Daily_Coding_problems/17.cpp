/*
This question is asked by Microsoft. Given an array of strings, return the longest common 
prefix that is shared amongst all strings.
Note: you may assume all strings only contain lowercase alphabetical characters.

Ex: Given the following arrays...

["colorado", "color", "cold"], return "col"
["a", "b", "c"], return ""
["spot", "spotty", "spotted"], return "spot"
*/

#include<bits/stdc++.h>
using namespace std;


void solve(vector<string>&res,int n)
{
    sort(res.begin(),res.end());
    string start=res[0];
    string last=res[n-1];
    int end=min(start.length(),last.length());
    int i=0;
    // int j=0;
    while(i<end && start[i]==last[i])
    {
        i++;
    }
    string ans=start.substr(0,i);
    cout<<ans<<endl;
}
// Time Complexity:O(min(length of start,length of end))
// Space Complexity:O(min(common prerfix))

int main()
{
    // Solution 1:
    int n;
    cin>>n;
    vector<string>res(n);
    for(int i=0;i<n;i++)
    {
        cin>>res[i];
    }
    solve(res,n);
    sort(res.begin(),res.end());
    // string start=res[0];
    string end=res[n-1];
    // int i=0;
    // int k=0;
    // int sz1=start.size();
    int sz2=end.size();
    string ans=end;
    for(int i=0;i<n-1;i++)
    {
        string temp="";
        int sz1=res[i].size();
        int j=0;
        int k=0;
        while(k<sz2 && j<sz1)
        {
            if(end[k]!=res[i][j])
            {
                break;
            }
            temp.push_back(end[k]);
            k++;
            j++;
        }
        if(temp<ans)
        {
            ans=temp;
        }
    }
    cout<<ans<<endl;
    return 0;
}
// Time Complexity:O(n*(max length of  common string))
// Space Complexity:O(min common length)