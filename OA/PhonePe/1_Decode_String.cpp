/*
Decode String
You are given an encoded string,the encoded string is read one charector at a time and the following steps are taken

If the charector is a letter,that letter is added to the decoded string
If the charector is a digit,lets say d,the decoded string repeated d-1 times.
Finally, given an integer k, you need to return the kth letter from the decoded string.
Sample Input
ha22,5
asdfg32,7
Sample Output
h
s
Explaination
For the first test case the decoded string will be hahahaha hence the 5th lettor is h.
For the second test case the decoded string will be asdfgasdfgasdfgasdfgasdfgasdfgasdfg, hence the 7th letter be s
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int k;
    cin >> k;
    int n = str.length();
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (isalpha(str[i]))
        {
            cnt++;
        }
        else
        {
            int add = (str[i] - '0') - 1;
            if (cnt + cnt * add == k)
            {
                cout << str[i - 1] << endl;
                return 0;
            }
            else if (cnt + cnt * add > k)
            {
            }
        }
    }
}