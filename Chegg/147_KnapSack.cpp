#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Test Cases
    int t;
    // Input Test Cases
    cin >> t;
    while (t--)
    {
        // variables to store capacity and number of items
        int capacity, items;
        // input of capacity of number of items
        cin >> capacity >> items;
        // array of values of n items
        int values[items];
        // array of weight of n items
        int weight[items];
        // input of value and weight of ith items
        for (int i = 0; i < items; i++)
        {
            cin >> values[i] >> weight[i];
        }
        // knapsack table to store maximum value
        int knapSack[items + 1][capacity + 1];
        for (int i = 0; i <= items; i++)
        {
            for (int j = 0; j <= capacity; j++)
            {
                // Fill 0th row and 0th column as 0
                if (i == 0 or j == 0)
                {
                    knapSack[i][j] = 0;
                }
                // if ith element weight is less than j
                // we have two conditions
                // 1. Take it
                // 2. Ignore it
                else if (weight[i - 1] <= j)
                {
                    knapSack[i][j] = max(values[i - 1] + knapSack[i - 1][j - weight[i - 1]], knapSack[i - 1][j]);
                }
                // else
                // ignore it
                else
                {
                    knapSack[i][j] = knapSack[i - 1][j];
                }
            }
        }

        // get maximum cost
        // which is store at last position of knapsack table
        int maxCost = knapSack[items][capacity];
        // store capacity
        int cap = capacity;
        // to store indices
        vector<int> indices;

        // Iterate knapsack table
        for (int i = items; i > 0 and maxCost > 0; i--)
        {
            // if item is not included
            if (maxCost == knapSack[i - 1][cap])
            {
                continue;
            }
            // else item is included
            else
            {
                // put index of element
                indices.push_back(i - 1);
                // reduce cost
                maxCost = maxCost - values[i - 1];
                // reduce capacity
                cap = cap - weight[i - 1];
            }
        }

        // print size
        cout << indices.size() << endl;
        // print indices of items
        for (int i = indices.size() - 1; i >= 0; i--)
        {
            cout << indices[i] << " ";
        }
        cout << endl;
    }
    return 0;
}