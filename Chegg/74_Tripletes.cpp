#include<iostream>
#include<vector>
#include <cmath>
#include <valarray>
#include<algorithm>
using namespace std;

// Utility Function which returns the perfect squares less than or equal to n
vector<int> perfectSquares(int n)
{
    // stores the perfect squares
    vector<int>squares;
    int curr= 1, i = 1;
    // unitl less than or equal to n
    while (curr <= n)
    {
        squares.push_back(curr);
        curr = pow(++i, 2);
    }
    // return list
    return squares;
}

int tripletsCount(int n)
{
    // storing the perfectSquares upto n^2
    vector<int> squares = perfectSquares(pow(n, 2));
 
    int tripletCount = 0;
    // Iterate from 1 to n
    for(int a = 1; a <= n; a++)
    {
        // Getting a^2
        int aSquare = pow(a, 2);
 
        for(int i = 0; i < squares.size(); i++)
        {
            // getting c^2
            int cSquare = squares[i];
 
            // Since, a^2 + b^2 = c^2

            // getting b^2
            int bSquare = abs(cSquare - aSquare);

            // getting b
            int b = sqrt(bSquare);

            // getting c
            int c = sqrt(cSquare);


            // Go to next conditions
            if (c < a || (find(squares.begin(),squares.end(),bSquare) ==squares.end()))
            {
                continue;
            }
 

            // according to the condition 
            // if triplets satisfy the following conditions
            // 1. c^2=a^2+b^2
            // 2. c=a^2-b 
            if ((b >= a) and (b <= c)  and (aSquare + bSquare == cSquare) and c==(aSquare-b))
            {
                // Increment the tripletCount
                tripletCount++;
            }
        }
    }
    // Return the total tripletCount
    return tripletCount;
}

int main()
{
    // User Input
    int n;
    cin>>n;
    // Storing ans
    int ans=tripletsCount(n);
    // Printing ans
    cout<<ans<<endl;
}

// Time Complexity:O(nlogn)
// Space Complexity:O(1)