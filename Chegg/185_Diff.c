#include <stdio.h>
#include <stdlib.h>

// Utility function which finds and returnt the smallest distance between two arrays
int distance(int dataA[], int sizeA, int dataB[], int sizeB)
{
    // Keep track on the smallest distacne
    int dis = INT_MAX;
    // Iterate the arrayA
    for (int i = 0; i < sizeA; i++)
    {
        // Iterate arrayB from 0 th sizeB
        for (int j = 0; j < sizeB; j++)
        {
            // get absolute difference between each pair of A and B
            int tempRes = abs(dataA[i] - dataB[j]);
            // if difference is less than the dis then update dis
            if (tempRes < dis)
            {
                dis = tempRes;
            }
        }
    }
    // return ans
    return dis;
}

int main()
{
    // Size of arrayA and arrayB
    int n, m;
    scanf("%d %d", &n, &m);
    int dataA[n], dataB[m];
    // Read elements of arrayA
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &dataA[i]);
    }
    // Read elements of arrayB
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &dataB[i]);
    }
    // get smallest distance from both arrays
    int ans = distance(dataA, n, dataB, m);
    // Print ans
    printf("%d", ans);
    return 0;
}