/*
This problem was asked by Twitter.

Given a list of numbers, create an algorithm that arranges them in order to form the largest possible integer. 
For example, given [10, 7, 76, 415], you should return 77641510.
*/

#include<bits/stdc++.h>
using namespace std;

bool myCompare(int x, int y)
{
 
    int xy = x, yx = y;
 
    // Count length of x and y
    int countx = 0, county = 0;
 
    // Count length of X
    while (x > 0) {
        countx++;
        x /= 10;
    }
 
    // Count length of Y
    while (y > 0) {
        county++;
        y /= 10;
    }
 
    x = xy;
    y = yx;
 
    while (countx--)
        yx *= 10;
 
    while (county--)
        xy *= 10;
 
    // Append x to y
    yx += x;
 
    // Append y to x
    xy += y;
 
    return xy > yx;
}

bool cmp(string a,string b)
{
    string ab=a.append(b);
    string ba=b.append(a);
    return ab.compare(ba)>0?1:0;
}

int main()
{
    int n;
    cin>>n;
    vector<string>nums(n);
    for(int i=0;i<n;++i){
        cin>>nums[i];
    }
    sort(nums.begin(),nums.end(),cmp);
    string ans="";
    for(auto it:nums)
    {
        ans+=it;
    }
    int zero=0;
    for(char ch:ans) if(ch=='0') zero++;
    if(zero==ans.length()) cout<<0<<endl;
    cout<<ans<<endl;
    return 0;
}
// Time Complexity:O(nlogn)