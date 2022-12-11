/*
Given a Binary String. Replace all "01" to "10" until it's no more possible.
In 1 second you replace all "01" to "10" in next second keep repeating this procedure.
Return the total seconds to complete this. eg: 0101->1010->1100 ans:2
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int n = str.length();
    int o = 0, z = 0;
    int ans = 0;
    int i = n - 1;
    while (i >= 0)
    {
        if (str[i] == '0')
        {
            while (i >= 0 && str[i] == '0')
            {
                z++;
                i--;
            }
        }
        else
        {
            ans += (z * (o - ans));
            z = 0;
            o++;
            i--;
        }
    }
    ans += (z * (o - ans));
    cout << ans << endl;
    return 0;
}

// Solution : 2

#include <bits/stdc++.h>
using namespace std;

int swapper(string &a)
{
    int i = 0, n = a.length();
    int curr = 0, prev = 0;
    int ones = 0;

    while (i < n)
    {
        if (a[i] == '1')
        {
            prev = i;
            curr = i;
            i++;
            ones++;
            break;
        }
        i++;
    }

    while (i < n)
    {

        if (a[i] == '1')
        {
            if (i - ones)
                curr = max(prev + 1, i - ones);

            ones++;
        }

        i++;
        prev = curr;
    }

    return curr;
}