#include<bits/stdc++.h>
using namespace std;




string repeatLimitedString(string s,int  k)
{
 
    int frequency_array[26];
    memset(frequency_array,0,sizeof(frequency_array));
    for (int i = 0;i < s.length(); i++) {
        frequency_array[s[i] - 'a']++;
    }
    string ans = "";

    for (int i = 25; i >= 0;) {

        if (frequency_array[i] > k) {
 
            int temp = k;
            string st(1, i + 'a');
            while (temp > 0) {
                ans += st;
                temp--;
            }
 
            frequency_array[i] -= k;
            int j = i - 1;
            while ( j >= 0 && frequency_array[j] <= 0) {
                j--;
            }
            if ( j >= 0 && frequency_array[j] > 0) {
                string str(1, j + 'a');
                ans += str;
                frequency_array[j] -= 1;
            }
            else {
                break;
            }
        }
        else if (frequency_array[i] > 0) {
            int temp = frequency_array[i];
            frequency_array[i] -= temp;
            string st(1, i + 'a');
            while (temp > 0) {
                ans += st;
                temp--;
            }
        }

        else {
            i--;
        }
    }
    return ans;
}