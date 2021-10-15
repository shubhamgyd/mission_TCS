#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fast() ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define lli long long int
#define str string
#define MOD 1000000007
#define num1 1000000

using namespace std;

void swapping(int arr[],int n,int outofplace,int i)
{
    char curr=arr[i];
    for(int j=i;j>outofplace;j--)
    {
        arr[j]=arr[j-1];
    }
    arr[outofplace]=curr;
}

void rearrange(int arr[],int n)
{
    int outofplace=-1;
    for(int i=0;i<n;i++)
    {
        if(outofplace>=0)
        {
            // find the item which must be moved into the
            // out-of-place entry if out-of-place entry is
            // positive and current entry is negative OR if
            // out-of-place entry is negative and current
            // entry is negative then right rotate
            //
            // [...-3, -4, -5, 6...] -->   [...6, -3, -4,
            // -5...]
            //      ^                          ^
            //      |                          |
            //     outofplace      -->      outofplace
            //
            if(((arr[i]>=0) && (arr[outofplace]<0)) ||  ((arr[i]<0) && (arr[outofplace]>=0)))
            {
                swapping(arr,n,outofplace,i);  // If the element is either -ve & +ve at the current indes and the outofindex that respectively
                                               // and the vice-versa that time we , swap the position of thode elements


                // the new out-of-place entry is now 2 steps
                // ahead
                if(i-outofplace>=2)
                {
                    outofplace+=2;
                }
                else
                {
                    outofplace=-1;
                }
            }

        
        }
        if(outofplace==-1)
        {
            if((arr[i]>=0 && (!(i&0x01))) || (arr[i]<0) &&((i&0x01))) // this will help us to make the position of elements order wise
            {
                outofplace=i;
            }
        }
    }

}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}



// Time Complexity : O(N^2)

// Space Complexity : O(1)
int main()
{
    fast();
    int arr[]={-5,-2,5,2,4,7,1,8,0,-8};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Array before arranging: ";
    printArray(arr,n);
    rearrange(arr,n);
    cout<<"Array after rearranging: ";
    printArray(arr,n);
    // for(int i=0;i<n;i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    return 0;
}
