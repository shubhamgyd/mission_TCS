/*
For each word in a list of words, if any two adjacent characters are equal, change one of them:
Determine the minimum number of substitutions so the final string contains no adjacent equal
 characters

Example

words [add boook, "break"]

1. add change one d (1 change)

2 boook change the middle o (1 change)

3break no changes are necessary (0 changes)

The return array is [1.1.0)

Function Description

Complete the function minimalOperations in the editor below

minimal Operations has the following parameter(s):

string wordsin) an array of strings

inting each element is the minimum substitutions for words)


*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> res(n);
    for (int i = 0; i < n; i++)
    {
        cin >> res[i];
    }
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        int c = 0;
        int j = 0;
        string str = res[i];
        while (j < str.length())
        {
            int k = j;
            int cnt = 0;
            while (k < str.length() and str[j] == str[k])
            {
                cnt++;
                k++;
            }
            j = k;
            c += (cnt / 2);
        }
        arr[i] = c;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}