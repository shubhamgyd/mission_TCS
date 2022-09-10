#include<bits/stdc++.h>
using namespace std;


int main()
{
    // no of packages
    int n;
    cin>>n;
    // declare the packageWeights array
    vector<int>packageWeights(n);
    // input of n packages
    for(int i=0;i<n;i++)
    {
        cin>>packageWeights[i];
    }
    // keep track on maximum possible weights
    int maximumWeight=0;
    // declare another copy array for simplicity
    vector<int>copyWeights(n);
    // assign the last weight at the last index of copy array to 
    // calculate the maximum weight
    copyWeights[n-1]=packageWeights[n-1];
    // Iterate from the 2nd last position to the first position
    for(int i=n-2;i>=0;i--)
    {
        // if packageweight at ith position is less than the 
        // sum of copyweight at (i+1)th position
        // then add the totalWeight at (i+1)th positon of copyweight and 
        // the packageweight at ith positon
        if(packageWeights[i]<copyWeights[i+1])
        {
            copyWeights[i]=copyWeights[i+1]+packageWeights[i];
        }
        // else just put the packageweight at (i)th positon to the ith positon
        // of copyweight
        else
        {
            copyWeights[i]=packageWeights[i];
        }
    }
    // Iterate from the start to end and
    // find the maximum possible weight 
    for(int i=0;i<n;i++)
    {
        maximumWeight=max(maximumWeight,copyWeights[i]);
    }
    // print maximum weight
    cout<<maximumWeight<<endl;
    return 0;
}