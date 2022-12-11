/*
You are given an array A of size N.

Let us define F(i,j,k) as the following:
F(i,j,k) (Ai | Aj) & Ak Here | is bitwise or operator, & is bitwise and operator.
Determine bitwise XOR of F(A, B, C) over all triplets (A, B, C) such that
1< A, B, C ≤N.

Example 1:
Assumptions
N=2
A = [1, 4]
Approach:

The triplets are as follows:
F(1, 1, 1) = 1 F(1, 1, 2) = 0 F(1, 2, 1) = 1 F(1, 2, 2) = 4 F(2, 1, 1) = 1 F(2, 1,2) = 4 F(2, 2, 1) = 0 F(2, 2, 2) = 4
Bitwise XOR of all triplets = 10^1^4^1^0^4=5
Therefore, the answer is 5.

Example 2:
N=1
A = [5]
Approach

There is only triplet possible F(1, 1, 1) = 5
Bitwise XOR of all triplets = 5
Therefore the answer is 5.
*/

#include <bits/stdc++.h>
using namespace std;

/*
These kinds of questions can be solved by considering each bit separately.

For each bit, let n0 be the number of array elements that have that bit set to 0,
and let n1 be the number of elements that have that bit set to 1.

Then it's easy to determine whether or not that bit is set in the answer:

The number of pairs i,j such that the bit is set in A[i]|A[j] is n1*n1 + n1*n0*2
The number of triplets i,j,k with that bit set in F(i,j,k) is then n1*(n1*n1 + n1*n0*2)
Since all the F's are XORed together, the result will have the bit set if it's set in an
odd number of triplets, i.e., if the above expression evaluates to an odd number.
At this point, we could easily solve the problem by counting the 1s and 0s for each bit,
but notice that n1*(n1*n1 + n1*n0*2) evaluates to an odd number exactly when n1 is odd, i.e.,
when the bit appears an odd number of times in the array. To get a number with each bit set if
it's set an odd number of times in the array...

just XOR all the array elements together.
*/

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int ans = nums[0];
    for (int i = 1; i < n; i++)
    {
        ans ^= nums[i];
    }
    cout << ans << endl;
    return 0;
}