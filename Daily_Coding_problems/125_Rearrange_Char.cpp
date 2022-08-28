/*
This problem was asked by IBM.

Given a string with repeated characters, rearrange the string so that no two adjacent 
characters are the same. If this is not possible, return None.

For example, given "aaabbc", you could return "ababac". Given "aaab", return None.
aaabdc
*/

#include<bits/stdc++.h>
using namespace std;



#include <bits/stdc++.h>
using namespace std;
 
char getMaxCountChar(const vector<int>& count)
{
    int max = 0;
    char ch;
    for (int i = 0; i < 26; i++) {
        if (count[i] > max) {
            max = count[i];
            ch = 'a' + i;
        }
    }
 
    return ch;
}
 
string rearrangeString(string S)
{
 
    int n = S.size();
    if (!n)
        return "";
 
    vector<int> count(26, 0);
    for (auto ch : S)
        count[ch - 'a']++;
 
    char ch_max = getMaxCountChar(count);
    int maxCount = count[ch_max - 'a'];
 
    // check if the result is possible or not
    if (maxCount > (n + 1) / 2)
        return "";
 
    string res(n, ' ');
 
    int ind = 0;
    // filling the most frequently occurring char in the even
    // indices
    while (maxCount) {
        res[ind] = ch_max;
        ind = ind + 2;
        maxCount--;
    }
    count[ch_max - 'a'] = 0;
 
    // now filling the other Chars, first filling the even
    // positions and then the odd positions
    for (int i = 0; i < 26; i++) {
        while (count[i] > 0) {
            ind = (ind >= n) ? 1 : ind;
            res[ind] = 'a' + i;
            ind += 2;
            count[i]--;
        }
    }
    return res;
}

/*
Time complexity : O(n)
Auxiliary Space : O(n+26) where 26 is the size of the vocabulary. 
*/



int main()
{
    string str;
    cin>>str;
    int n=str.length();
    priority_queue<pair<int,char>>pq;
    map<char,int>mp;
    for(auto it:str)
    {
        mp[it]++;
    }
    for(auto it:mp)
    {
        pq.push({it.second,it.first});
    }
    string ans="";
    pair<int,char> prev={-1,'#'};
    while(!pq.empty())
    {
        auto k=pq.top();
        pq.pop();
        ans+=k.second;
        if(prev.first>0)
        {
            pq.push(prev);
        }
        k.first--;
        prev=k;
    }
    if(ans.length()!=n)
    {
        cout<<"None"<<endl;
    }
    else
    {
        cout<<ans<<endl;
    }
    return 0;

}
/*
Time complexity : O(n log(n))

Here n is length of the string

Auxiliary Space: O(n)

Extra space is used to store the resultant string, other spaces used are constant.
*/

