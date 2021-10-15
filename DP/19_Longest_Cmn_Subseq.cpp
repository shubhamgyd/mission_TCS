#include<bits/stdc++.h>
using namespace std;

int LongsubSeq(string X,string Y,int n,int m)
{
    //Condition if any one of the strings will be zero , then no common sequence 
    // will generate , simply return zero in this case
    // Basically this is base condition
    if(n==0 || m==0) return 0;  

    //If last char of string matched , then simply remove last char of both strings and add 1
    //and If last char of strings don't matched , then that case we have two cases
    //1. Either remove last char of firsst string { decreasing the length by 1} 
    //and take second string as it is 
    //2. Remove last char of second string {decreasing the lenght by 1}
    // and take first string as it is . 
    // Recursive call both conditions .
    if(X[n-1]==Y[m-1])
    {
        return LongsubSeq(X,Y,n-1,m-1)+1;
    }
    else
    {
        return max(LongsubSeq(X,Y,n,m-1),LongsubSeq(X,Y,n-1,m));
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string X= "abc";  // Initialization Of strings
    string Y= "ahbgdc";
    int n=X.length();   // Lengths of string 
    int m=Y.length();
    cout<<" Longest Common Subsequence: "<<LongsubSeq(X,Y,n,m)<<"\n";
    return 0;
}