/*
Given a two strings S and T, find the count of distinct occurrences of T in S 
as a subsequence.
Examples: 
 

Input: S = banana, T = ban
Output: 3
Explanation: T appears in S as below three subsequences.
[ban], [ba  n], [b   an]

Input: S = geeksforgeeks, T = ge
Output: 6
Explanation: T appears in S as below three subsequences.
[ge], [     ge], [g e], [g    e] [g     e]
and [     g e]   
*/


#include <bits/stdc++.h>
using namespace std;

int findSubsequenceCount(string S, string T)
{
	int m = T.length(), n = S.length();

	// T can't appear as a subsequence in S
	if (m > n)
		return 0;

	// mat[i][j] stores the count of occurrences of
	// T(1..i) in S(1..j).
	int mat[m + 1][n + 1];

	// Initializing first column with all 0s. An empty
	// string can't have another string as suhsequence
	for (int i = 1; i <= m; i++)
		mat[i][0] = 0;

	// Initializing first row with all 1s. An empty
	// string is subsequence of all.
	for (int j = 0; j <= n; j++)
		mat[0][j] = 1;

	// Fill mat[][] in bottom up manner
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {

			// If last characters don't match, then value
			// is same as the value without last character
			// in S.
			if (T[i - 1] != S[j - 1])
				mat[i][j] = mat[i][j - 1];

			// Else value is obtained considering two cases.
			// a) All substrings without last character in S
			// b) All substrings without last characters in
			// both.
			else
				mat[i][j] = mat[i][j - 1] + mat[i - 1][j - 1];
		}
	}

	/* uncomment this to print matrix mat
	for (int i = 1; i <= m; i++, cout << endl)
		for (int j = 1; j <= n; j++)
			cout << mat[i][j] << " "; */
	return mat[m][n];
}

// Driver code to check above method
int main()
{
	string T = "ge";
	string S = "geeksforgeeks";
	cout << findSubsequenceCount(S, T) << endl;
	return 0;
}









// Recursion 




#include<bits/stdc++.h>
using namespace std;

int solve(string s,string t,int i,int j)
{
    if(i>=s.length())
    {
        // if source and target are empty, there is 1 subsequence. else if source is empty
        // and target is not, 0 subsequence
        return j>=t.length()?1:0;
    }

    // if target is empty, every character source is 1 subsequence.
    if(j>=t.length())
    {
        return 1;
    }

    int count=0;
    // if the character in the source is same as target then there are 2 possibilities.
    // 1.) the current character is part of subsequence or 
    // 2.) Its not, in this case we move on to next character
    if(s[i]==t[j])
    {
        return count=solve(s,t,i+1,j+1)+solve(s,t,i+1,j);
    }
    else
    {
        return count=solve(s,t,i+1,j);
    }
    return count;
}
// Time Complexity :Exponential

int main()
{
    string s,t;
    cin>>s>>t;
    cout<<solve(s,t,0,0)<<endl;
    return 0;
}