// In this probelm we are going to computer nCr%p calue
/*
Given three numbers n, r and p, compute value of nCr mod p. 
Example: 

Input:  n = 10, r = 2, p = 13
Output: 6
Explanation: 10C2 is 45 and 45 % 13 is 6
*/

#include<bits/stdc++.h>
using namespace std;
#define int   long long


int32_t main()
{
    int n,r,p;
    cin>>n>>r>>p;
    int fact[n+1];
    int pr=1;
    fact[1]=1;
    for(int i=2;i<=n;i++)
    {
        fact[i]=fact[i-1]*i;
    }
    int val=fact[n];
    int val1=fact[n-r];
    int val2=fact[r];
    int result=(val/(val1*val2))%p;
    cout<<result<<endl;
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/












//Another solution


#include <bits/stdc++.h>
using namespace std;

// Returns nCr % p
int nCrModp(int n, int r, int p)
{
	// Optimization for the cases when r is large
	if (r > n - r)
		r = n - r;

	// The array C is going to store last row of
	// pascal triangle at the end. And last entry
	// of last row is nCr
	int C[r + 1];
	memset(C, 0, sizeof(C));

	C[0] = 1; // Top row of Pascal Triangle

	// One by constructs remaining rows of Pascal
	// Triangle from top to bottom
	for (int i = 1; i <= n; i++) {

		// Fill entries of current row using previous
		// row values
		for (int j = min(i, r); j > 0; j--)

			// nCj = (n-1)Cj + (n-1)C(j-1);
			C[j] = (C[j] + C[j - 1]) % p;
	}
	return C[r];
}

// Driver program
int32_t main()
{
	int n = 10, r = 2, p = 13;
	cout << "Value of nCr % p is " << nCrModp(n, r, p);
	return 0;
}
/*
Time complexity of above solution is O(n*r) and it requires O(r) space. 
There are more and better solutions to above problem
*/