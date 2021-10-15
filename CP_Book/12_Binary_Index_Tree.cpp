// In this problem we are going to find the range sum between two ranges , also in between we
// can update the value


#include<bits/stdc++.h>
using namespace std;


// Returns sum of arr[0..index]. This function assumes
// that the array is preprocessed and partial sums of
// array elements are stored in BITree[].
int getSum(int BITree[], int index)
{
    int sum = 0; // Iniialize result
  
    // index in BITree[] is 1 more than the index in arr[]
    index = index + 1;
  
    // Traverse ancestors of BITree[index]
    while (index>0)
    {
        // Add current element of BITree to sum
        sum += BITree[index];
  
        // Move index to parent node in getSum View
        index -= index & (-index);
    }
    return sum;
}


// Updates a node in Binary Index Tree (BITree) at given index
// in BITree. The given value 'val' is added to BITree[i] and 
// all of its ancestors in tree.
void Update(int BITree[],int n,int index,int val)
{
    // index in BITree[] is 1 more than the index in arr[]
    index=index+1;
    // Traverse all ancestors and add 'val'
    while(index<=n)
    {
        BITree[index]+=val;

        // Update index to that of parent in update View
        index+=index&(-index);
    }

}

int *ConstructBITree(int arr[],int n)
{
    int *BITree = new int[n+1];
    for(int i=1;i<=n;i++)
    {
        BITree[i]=0;
    }

    for(int i=0;i<n;i++)
    {
        Update(BITree,n,i,arr[i]);
    }
    for (int i=1; i<=n; i++)
        cout << BITree[i] << " ";
    cout<<endl;
    return BITree;

}

int main()
{
    int arr[]={1,3,4,8,6,1,4,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    int *BITree=ConstructBITree(arr,n);
    cout<<"Sum of elements range from 0 to 5: "<<getSum(BITree,5)<<endl;
    Update(BITree,n,3,6);
    cout<<"Sum of elements range from 0 to 5: "<<getSum(BITree,5)<<endl;

}