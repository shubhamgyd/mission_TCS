/*
There was a string of size n having certain number of question marks ( k) k can be 0 ,
your task is to return the number of valid strings formed pertaining to the conditions

No 2 adjacent characters should be same
The first and the last character should be same
for example
abbc has answer =0 as first and last character are different
??lz has answer =24 as the first ? has to be z and the next one has 24 choices

note: only lowercase characters are permitted

n<=10^5
*/
#include <bits/stdc++.h>
using namespace std;

// TC: O(26*N) ~ O(N)
// SC: O(26*2) ~ O(1)

int getInBetweenCount(string s)
{

    int n = s.size();

    vector<int> dppre(26, 0);
    dppre[s[0] - 'a'] = 1;

    for (int i = 1; i < n; i++)
    {

        int sum = 0;
        vector<int> dpcur(26, 0);

        sum = accumulate(dppre.begin(), dppre.end(), sum);

        if (s[i] == '?')
        {

            // look for all possibility other than alphabet which is present on previous possition
            for (int j = 0; j < 26; j++)
                dpcur[j] = sum - dppre[j];
        }
        else
        {

            // don't take forward the contribution of the alphabet which is same as current one when it is fixed
            dpcur[s[i] - 'a'] = sum - dppre[s[i] - 'a'];
        }

        dppre = dpcur;
    }

    int ans = 0;
    ans = accumulate(dppre.begin(), dppre.end(), ans);

    return ans;
}

int getCount(string s)
{

    int n = s.size();

    // CASE 1: when both first and last are empty then try every possibility from a to z
    if (s[0] == '?' && s[n - 1] == '?')
    {

        int ans = 0;
        for (char c = 'a'; c <= 'z'; c++)
        {
            s[0] = s[n - 1] = c;
            ans += getInBetweenCount(s);
        }
        return ans;
    }

    // CASE 2: when either of first or last is empty and other one is fixed
    if (s[0] == '?')
    {

        s[0] = s[n - 1];
        return getInBetweenCount(s);
    }

    if (s[n - 1] == '?')
    {
        s[n - 1] = s[0];
        return getInBetweenCount(s);
    }

    // CASE 3: When first and last are not equal
    if (s[0] != s[n - 1])
        return 0;

    // CASE 4: all other places after dealing with first and last
    return getInBetweenCount(s);
}

int main()
{
    string str = "??lz";

    cout << getCount(str);
    return 0;
}