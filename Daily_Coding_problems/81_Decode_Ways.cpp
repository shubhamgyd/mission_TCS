/*
This question is asked by Microsoft. Given a message that is encoded using the following 
encryption method…

A -> 1
B -> 2
C -> 3
...
Z -> 26
Return the total number of ways it can be decoded.
Note: ‘0’ has no mapping and a character following a ‘0’ also has no mapping (i.e. “03”)


Ex: Given the following message…

message = "23", return 2.
The message can be decrypted as "BC" (i.e. 2 -> B, 3 -> C)
The message can also be decrypted as "W" (i.e. 23 -> W)
Ex: Given the following message…

message = "1234", return 3.
Thanks,
The Daily Byte

*/

#include<bits/stdc++.h>
using namespace std;


int main()
{
    string str;
    cin>>str;
    int n=str.length();
    int r1=1;
    int r2=1;
    for(int i=1;i<n;i++)
    {
        if(str[i]=='0')
        {
            r1=0;
        }
        if(str[i-1]=='1' || str[i-1]=='2' && str[i]<='6')
        {
            r1+=r2;
            r2=r1-r2;
        }
        else
        {
            r2=r1;
        }
    }
    if(str.empty() || str[0]=='0') cout<<0<<endl;
    cout<<r1<<endl;
    return 0;
}
// Time Complexity:(|s|) 
// Auxilary Space  :O(1)