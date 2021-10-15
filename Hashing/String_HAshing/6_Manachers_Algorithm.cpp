#include<bits/stdc++.h>
using namespace std;


void Manachers(string s)
{
    int n=s.length();
    vector<int> d1(n);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
            k++;
        }
        d1[i] = k--;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }



    vector<int> d2(n);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
        while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
            k++;
        }
        d2[i] = k--;
        if (i + k > r) {
            l = i - k - 1;
            r = i + k ;
        }
    }
    for(auto it:d1)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    for(auto it:d2)
    {
        cout<<it<<" ";
    }
    cout<<"\n\n"<<endl;
}
// Time Complexity: O(n)
// Space Complexity: O(n)


int main()
{
    string s;
    cin>>s;
    int  n=s.length();
    Manachers(s);
    vector<int> d1(n),  d2(n);
    for (int i = 0; i < n; i++) {
        d1[i] = 1;
        while (0 <= i - d1[i] && i + d1[i] < n && s[i - d1[i]] == s[i + d1[i]]) {
            d1[i]++;
        }

        d2[i] = 0;
        while (0 <= i - d2[i] - 1 && i + d2[i] < n && s[i - d2[i] - 1] == s[i + d2[i]]) {
            d2[i]++;
        }
    }

    // Time Complexity:O(n^2)
    // Space Complexity: O(n^2)

    for(auto it:d1)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    for(auto it:d2)
    {
        cout<<it<<" ";
    }
}



















/*
#include <bits/stdc++.h>
using namespace std;
#define SIZE 100000 + 1

int P[SIZE * 2];

// Transform S into new string with special characters inserted.
string convertToNewString(const string &s) {
    string newString = "@";

    for (int i = 0; i < s.size(); i++) {
        newString += "#" + s.substr(i, 1);
    }

    newString += "#$";
    return newString;
}

string longestPalindromeSubstring(const string &s) {
    string Q = convertToNewString(s);
    int c = 0, r = 0;                // current center, right limit

    for (int i = 1; i < Q.size() - 1; i++) {
        // find the corresponding letter in the palidrome subString
        int iMirror = c - (i - c);

        if(r > i) {
            P[i] = min(r - i, P[iMirror]);
        }

        // expanding around center i
        while (Q[i + 1 + P[i]] == Q[i - 1 - P[i]]){
            P[i]++;
        }

        // Update c,r in case if the palindrome centered at i expands past r,
        if (i + P[i] > r) {
            c = i;              // next center = i
            r = i + P[i];
        }
    }

    // Find the longest palindrome length in p.

    int maxPalindrome = 0;
    int centerIndex = 0;

    for (int i = 1; i < Q.size() - 1; i++) {

        if (P[i] > maxPalindrome) {
            maxPalindrome = P[i];
            centerIndex = i;
        }
    }

    cout << maxPalindrome << "\n";
    return s.substr( (centerIndex - 1 - maxPalindrome) / 2, maxPalindrome);
}

int main() {
    string s = "kiomaramol\n";
    cout << longestPalindromeSubstring(s);
    return 0;
}
*/