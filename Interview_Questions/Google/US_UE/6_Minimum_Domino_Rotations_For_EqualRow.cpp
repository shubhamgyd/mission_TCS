/*
In a row of dominoes, tops[i] and bottoms[i] represent the top and bottom halves of the
ith domino. (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)

We may rotate the ith domino, so that tops[i] and bottoms[i] swap values.

Return the minimum number of rotations so that all the values in tops are the same,
or all the values in bottoms are the same.

If it cannot be done, return -1.
*/

#include <bits/stdc++.h>
using namespace std;

/*
Intuition
One observation is that, if A[0] works, no need to check B[0].
Because if both A[0] and B[0] exist in all dominoes,
when you swap A[0] in a whole row,
you will swap B[0] in a whole at the same time.
The result of trying A[0] and B[0] will be the same.


Solution 1:
Count the occurrence of all numbers in A and B,
and also the number of domino with two same numbers.

Try all possibilities from 1 to 6.
If we can make number i in a whole row,
it should satisfy that countA[i] + countB[i] - same[i] = n

Take example of
A = [2,1,2,4,2,2]
B = [5,2,6,2,3,2]

countA[2] = 4, as A[0] = A[2] = A[4] = A[5] = 2
countB[2] = 3, as B[1] = B[3] = B[5] = 2
same[2] = 1, as A[5] = B[5] = 2

We have countA[2] + countB[2] - same[2] = 6,
so we can make 2 in a whole row.

Time O(N), Space O(1)
*/
int minDominoRotations(int A[], int B[], int n)
{
    vector<int> countA(7), countB(7), same(7);

    for (int i = 0; i < n; ++i)
    {
        countA[A[i]]++;
        countB[B[i]]++;
        if (A[i] == B[i])
            same[A[i]]++;
    }
    for (int i = 1; i < 7; ++i)
        if (countA[i] + countB[i] - same[i] == n)
            return n - max(countA[i], countB[i]);
    return -1;
}




// Using hashing
class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        map<int,int>total,upper,down;
        int size=tops.size();
        for(auto it:tops)
        {
            total[it]++;
            upper[it]++;
        }
        for(auto it:bottoms)
        {
            total[it]++;
            down[it]++;
        }
        vector<int>points;
        int mx=INT_MAX;
        for(auto it:total)
        {
            if(it.second>=size)
            {
                points.push_back(it.first);
            }
        }
        bool flag=false;
        for(auto it:points)
        {
            if(upper[it]>down[it])
            {
                
                int ct=0;
                bool ok=true;
                for(int i=0;i<size;i++)
                {
                    
                    if(tops[i]==it)
                    {
                        continue;
                    }
                    if(tops[i]!=it && bottoms[i]==it)
                    {
                        ct++;
                    }
                    else
                    {
                        ok=false;
                        break;
                    }
                }
                // cout<<"ct: "<<ct<<endl;
                if(ok)
                {
                    mx=min(mx,ct);
                    flag=true;
                    break;
                }
                
            }
            else
            {
                int ct=0;
                bool ok=true;
                for(int i=0;i<size;i++)
                {
                    if(bottoms[i]==it)
                    {
                        continue;
                    }
                    if(tops[i]==it && bottoms[i]!=it)
                    {
                        ct++;
                    }
                    else
                    {
                        ok=false;
                        break;
                    }
                }
                if(ok)
                {
                    mx=min(mx,ct);
                    flag=true;
                    break;
                }
            }
            if(flag) break;
        }
        return mx==INT_MAX?-1:mx;
    }
};

int main()
{
    int n;
    cin >> n;
    int tops[n];
    int bottoms[n];
    for (int i = 0; i < n; i++)
    {
        cin >> tops[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> bottoms[i];
    }
    cout << minDominoRotations(tops, bottoms, n) << endl;
}