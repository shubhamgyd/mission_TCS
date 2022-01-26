/*
Compute the nearest larger number by interchanging its digits updated.
Given 2 numbers a and b find the smallest number greater than b by 
interchanging the digits of a and if not possible print -1.

Input Format
2 numbers a and b, separated by space.
Output Format
A single number greater than b.
If not possible, print -1

Constraints
1 <= a,b <= 10000000


Example 1:

Sample Input:

    459 500

Sample Output:
    549

Example 2:

Sample Input:

    645757 457765

Sample Output:
    465577
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    string num1,num2;
    cin>>num1>>num2;
    sort(num1.begin(),num1.end());
    vector<string>res;
    do
    {
        // cout<<num1<<endl;
       if(num1>num2)
       {
           res.push_back(num1);
       }
    } while (next_permutation(num1.begin(),num1.end()));
    sort(res.begin(),res.end());
    if(res.empty())
    {
        cout<<-1<<endl;
    }
    else
    {
        cout<<res[0]<<endl;
    }
    return 0;
}
// Time Complexity:O(n*n)
// Spcae Complexity:O(n)



// another solution
// C++ program to find nearest greater value
#include <bits/stdc++.h>
using namespace std;

int min1 = INT_MAX;
int _count = 0;

// Find all the possible permutation of Value A.
int permutation(string str1, int i, int n, int p)
{
	if (i == n)
	{
		// Convert into Integer
		int q = stoi(str1);

		// Find the minimum value of A by interchanging
		// the digit of A and store min1.
		if (q - p > 0 && q < min1)
		{
			min1 = q;
			_count = 1;
		}
	}
	else
	{
		for (int j = i; j <= n; j++)
		{
			// Swap two string character
			swap(str1[i], str1[j]);
			permutation(str1, i + 1, n, p);
			swap(str1[i], str1[j]);
		}
	}
	return min1;
}

// Driver code
int main()
{
	int A = 213;
	int B = 111;

	// Convert integer value into string to
	// find all the permutation of the number
	string str1 = to_string(A);
	int len = str1.length();
	int h = permutation(str1, 0, len - 1, B);

	// count=1 means number greater than B exists
	_count ? cout << h << endl : cout << -1 << endl;

	return 0;
}

// This code is contributed by
// sanjeev2552
