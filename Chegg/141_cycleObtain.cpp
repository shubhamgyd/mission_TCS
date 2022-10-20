#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    // Input string
    string str;
    cin >> str;
    // Input distance
    int k;
    cin >> k;
    // get answer
    string ans = "";
    // get length
    int n = str.length();
    ans.resize(n);
    // Iterate string
    for (int i = 0; i < n; ++i)
    {
        // if current character is a
        // then append it as it is
        if (str[i] == 'a')
        {
            ans[i] = 'a';
        }
        // else just append previous character
        // of current
        else
        {
            ans[i] = (--str[i]);
        }
    }
    // print string
    cout << ans << endl;
}