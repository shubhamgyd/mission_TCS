/*
Given an unsorted array of size n. Array elements are in the range of 1 to n. One number from set {1, 2, …n} is missing and one number occurs twice in the array. Find these two numbers.

Examples:

Input: arr[] = {3, 1, 3}
Output: Missing = 2, Repeating = 3
Explanation: In the array, 2 is missing and 3 occurs twice

Input: arr[] = {4, 3, 6, 2, 1, 1}
Output: Missing = 5, Repeating = 1
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    // Solution 1: Brute Force
    // Explanation:
    /*
        1. Initialize two variables missing and repeating
        2. Iterate from 1 to n
        3. In nested for loop check the occurance of i
        4. If i is not present, then store it in missing else if occurance of i is 2 then store it in repeating
        5. Display missing and repeating
        Time Complexity:O(n*n)
        Space Complexity:O(1)
    */

    // Solution 2: Hashing
    // Explanation:
    /*
         1. Put all elements into hashMap
         2. Iterate 1 to n
         3. Check i is present in hashMap or not
         4. If present then check it's occurance
         5. If occurance is 2 then mark as repeating
         6. If i is not present then mark i as a missing
         7. Display missing and repeating

         Time Complexity:O(n+logn)
         Space Complexity:O(n)
    */

    /*
         Method 3 (Use elements as Index and mark the visited places)
         Approach:
         Traverse the array. While traversing, use the absolute value of every element as an index
         and make the value at this index negative to mark it visited. If something is already marked
         negative then this is the repeating element. To find the missing, traverse the array again and
         look for a positive value.

         void printTwoElements(int arr[], int size)
        {
            int i;
            cout << "The repeating element is ";

            for (i = 0; i < size; i++) {
                if (arr[abs(arr[i]) - 1] > 0)
                    arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
                else
                    cout << abs(arr[i]) << "\n";
            }

            cout << "and the missing element is ";
            for (i = 0; i < size; i++) {
                if (arr[i] > 0)
                    cout << (i + 1);
            }
        }

        Time Complexity: O(n)
        Auxiliary Space: O(1) as it is using constant variables
    */

    /*
     Method 4 (Make two equations using sum and sum of squares)
     Approach:

     Let x be the missing and y be the repeating element.
     Let N is the size of the array.
     Get the sum of all numbers using the formula S = N(N+1)/2
     Get the sum of square of all numbers using formula Sum_Sq = N(N+1)(2N+1)/6
     Iterate through a loop from i=1….N
     S -= A[i]
     Sum_Sq -= (A[i]*A[i])
     It will give two equations
     x-y = S – (1)
     x^2 – y^2 = Sum_sq
     x+ y = (Sum_sq/S) – (2)

     Time Complexity: O(n)
    Auxiliary Space: O(1)
    */
}