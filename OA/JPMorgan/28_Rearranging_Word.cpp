/*
Given a word, return a next greater permutation of word
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    void nextPermutation(string &str)
    {
        if (str.size() == 1)
        {
            return;
        }
        int i = str.size() - 2;
        while (i >= 0 && str[i + 1] <= str[i])
        {
            i--;
        }
        if (i >= 0)
        {
            int j = str.size() - 1;
            while (str[j] <= str[i])
            {
                j--;
            }
            swap(str[j], str[i]);
        }
        reverse(str.begin() + (i + 1), str.end());
    }
};

int main()
{
    string str;
    cin >> str;
    string temp = str;
    Solution obj;
    next_permutation(begin(str), end(str));
    obj.nextPermutation(temp);
    cout << str << endl;
    cout << temp << endl;
    return 0;
}