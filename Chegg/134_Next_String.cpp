#include <iostream>
#include <map>
#include <vector>
using namespace std;

void solve(string m, int n)
{
    // Vector to store the resultant strings
    vector<string> result;
    // previous string is m
    string prev = m;
    // Iterate n times
    for (int i = 0; i < n; i++)
    {
        // to store next string
        string nextStr = "";
        int j = 0;
        int len = prev.length();
        // Iterate previous string to get the next string
        while (j < len)
        {
            int k = j;
            // to store the frequency of current char
            int countFreq = 0;
            // count the frequency of current char
            while (k < len and prev[j] == prev[k])
            {
                k++;
                countFreq++;
            }
            // add the frequency into newStirng
            nextStr += to_string(countFreq);
            // add the number into newString
            nextStr.push_back(prev[j]);
            // go to the next char
            j = k;
        }
        // push the newStirng into result
        result.push_back(nextStr);
        // mark the current string as a previous string
        prev = nextStr;
    }
    // print all next n strings
    for (auto it : result)
    {
        cout << it << " ";
    }
    cout << endl;
}

int main()
{
    cout << endl;
    cout << endl;
    // Input string m and integre n
    string m;
    int n;
    cin >> m >> n;
    // Function call to get next n string
    solve(m, n);
    return 0;
}