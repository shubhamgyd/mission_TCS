/*
Find the lexicographically smallest possible subsequence of s of length k having atleat x 'b'.
Example:
Lets assume n=6, length of string, k is 4, x is 2 and s="aababb".
Now the subsequence of length 4 that has atleat 2 b's are {aabb,abab,abbb,babb}
Lexicographically smallest among them is aabb,which is the required answer.
Constraints:
1<=n<=10^5,
1<=x<=k<=n
x<=number of b's in s.
string consists of lowercase alphabets "a" and "b"
Input Format:
n: Integer denoting length of the string
k: Represents an integer denoting the length of output string
x: Represent the integer denoting the minimum required number of 'b' in the output string.
str: string of length n
Output Format:
Print the lexicographic smallest possible subsequence of length k.
Sample Input:
4 3 2 baba
Sample Output:
bab

If anyone can provide solutions or related questions on LC would be great.
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k,x;
    cin>>n>>k>>x;
    string str;
    cin>>str;
}