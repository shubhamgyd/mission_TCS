#include<bits/stdc++.h>
using namespace std;

int solve(string s)
{
    transform(s.begin(),s.end(),s.begin(),::tolower);
    unordered_map<char, int> unmp;
    int odd = 0, left = 0, right = s.size() - 1, result = 0;
    for (char ch : s)
    {
        unmp[ch]++;
    }
 
    for (auto i : unmp)
    {
        if (i.second % 2 == 1)
        {
            odd++;
        }
    }
 
    if (odd > 1)
    {
        return -1;
    }
 
    while (left < right) 
    {
        int l = left, r = right;
        while (s[l] != s[r])
        {
            r--;
        }
        if (l == r) 
        {
            swap(s[r], s[r + 1]);
            result++;
            continue;
        }
        else 
        {
            while (r < right) 
            {
                swap(s[r], s[r + 1]);
                result++;
                r++;
            }
        }
        left++, right--;
    }
    return result;
}

int main()
{
    string str;
    cin>>str;
    int ans=solve(str);
    cout<<ans<<endl;
    return 0;
}