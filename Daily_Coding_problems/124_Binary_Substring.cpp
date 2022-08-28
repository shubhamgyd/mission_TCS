/*
Given a binary string s, return the number of contiguous substrings that contains the same
 number of zeroes and ones.
Note: Each substring’s zeroes and ones must be grouped together.

Ex: Given the following string s…

s = "101", return 2 ("10" and "01").
Ex: Given the following string s…

s = "1011101", return 4 ("10", "01", "10", "01". "101" does not count since the zeroes 
and ones are not grouped together).
*/

#include<bits/stdc++.h>
using namespace std;

int countSubstring(string& S, int& n)
{
    // To store the total count of substrings
    int ans = 0;
 
    int i = 0;
 
    // Traversing the string
    while (i < n) {
 
        // Count of consecutive 0's & 1's
        int cnt0 = 0, cnt1 = 0;
 
        // Counting subarrays of type "01"
        if (S[i] == '0') {
 
            // Count the consecutive 0's
            while (i < n && S[i] == '0') {
                cnt0++;
                i++;
            }
 
            // If consecutive 0's ends then check for
            // consecutive 1's
            int j = i;
 
            // Counting consecutive 1's
            while (j < n && S[j] == '1') {
                cnt1++;
                j++;
            }
        }
 
        // Counting subarrays of type "10"
        else {
 
            // Count consecutive 1's
            while (i < n && S[i] == '1') {
                cnt1++;
                i++;
            }
 
            // If consecutive 1's ends then check for
            // consecutive 0's
            int j = i;
 
            // Count consecutive 0's
            while (j < n && S[j] == '0') {
                cnt0++;
                j++;
            }
        }
 
        // Update the total count of substrings with minimum
        // of (cnt0, cnt1)
        ans += min(cnt0, cnt1);
    }
 
    // Return answer
    return ans;
}

int main()
{
    string str;
    cin>>str;
    int cnt=0;
    
}