/*
This question is asked by Apple. Given two binary strings (strings containing only 1s and 0s) 
return their sum (also as a binary string).
Note: neither binary string will contain leading 0s unless the string itself is 0

Ex: Given the following binary strings...

"100" + "1", return "101"
"11" + "1", return "100"
"1" + "0", return  "1"
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str1,str2;
    cin>>str1>>str2;
    int num1=stoi(str1,0,2);
    int num2=stoi(str2,0,2);
    int result=num1+num2;
    string ans="";
    int cnt = 0;
    while (result != 0) {
        int rem = result % 2;
        unsigned long long c = pow(10, cnt);
        ans += to_string(rem * c);
        result /= 2;
        // Count used to store exponent value
        cnt++;
    }
    cout<<ans<<endl;
    return 0;
}
// Time Complexity:O(length of stirng)
// Space Complexity:O(n)
