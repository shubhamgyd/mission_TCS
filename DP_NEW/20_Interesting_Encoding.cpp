/*
Problem Name: Interesting encoding
Problem Difficulty: 
Problem Constraints: 1<=n<=5000
Problem Description:
Alice and Bob are planning to send encrypted messages to each other. Alice has decided to assign 'A' 
to code 1, 'B' to the code 2,...... 'Z' to code 26. Now he wonders given an encrypted message how many
 different decoding they can form.

Input Format: The first line consists of an integral value denoting number of test cases 't'. Then 't'
lines follows each containing encrypted string of length 'n'.


Sample Input: 1
25114
Output Format: In each line output the required answer.
Sample Output: 6
*/

#include <cstdio>
#include <cstring>
using namespace std;
int main(){
int L;
char d[5001];
long long dp[5001];
int t; scanf("%d",&t);
while(t--){

    scanf("%s",d);
    // 0 is not valid accoding to the question
    if(d[0]=='0') break;
    L = strlen(d);

    // // Only one decoding possible for first 0 and 1 digit.
    dp[0] = dp[1] = 1;
    for(int i = 2;i<=L;++i){
    dp[i] = 0;


    char c1 = d[i-2]-'0', c2 = d[i-1]-'0';

    // if (i-1)th and (i-2)th digits can form valid character increase dp[i] by dp[i-2]
    // i.e less than 26 and greater than 1
    if(c1==1 || (c1==2 && c2<=6)) dp[i] += dp[i-2];


    // if (i-1)th character is not 0 increase dp[i] by dp[i-1]
    if(c2!=0) dp[i] += dp[i-1];

    }
    printf("%lld\n",dp[L]);
}
return 0;
}