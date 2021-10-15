#include<bits/stdc++.h>
using namespace std;


class Solution{
  public:
    int minJumps(int arr[], int n){
        if(arr[0]<=0)
        {
            return -1;
        }
        if(n<=1)
        {
            return 0; // jump 0
        }
        pair<int,int>interval{0,0}; //  Initial interval to jump .......for checking the interval max value
        int jump=0; // Initial jump i.e. we are at -1 th position ( not in array )
        
        // Loop run infinite , until any brek/return come
        while(true)
        {
            jump++; // Whenever we proceed forward , jump increases
            int can_reach=-1;  // 
            // For finding the maximum reached_position , by using this loop and interval of previously declares 
            for(int i=interval.first;i<=interval.second;++i)
            {
                can_reach=max(can_reach,i+arr[i]); // Here i+arr[i] means i is the number of steps we have
                                                   // already jump and arr[i] means we can jump more this num
            }
            
            // If maximum can_reached position greater than equal to number of elements
            // then return the jumps
            // It means if we are at the last position or beyond the stairs
            if(can_reach>=n-1)
            {
                return jump;
            }
            
            // Next interval is  previous internal.second + 1 to can_reached position,
            // and we have to again check the maximum can reached position in 
            // newly created intevrval
            // i.e 2,4 we have to check the check the maxumum int between index 2 to 4
            interval={interval.second+1,can_reach};
            
            // condition like 1,0 so in this case we can return -1
            // Means no further move is possible
            if(interval.first>interval.second)
            {
                return -1;
            }
        }
        return -1;
    }
};


/*
Alternative Soln : O(n)
Space :O(1)

Class Solution
{
public:
    canReach(int arr[],int n)
    {
        int i,count=arr[0];
        for(int i=1;i<n;i++)
        {
            if(count<1)
            {
                return 0;
            }
            if(count=<arr[i])
            {
                count=arr[i];
            }
            else
            {
                count--;
            }
        }
        if(i==n)
        {
            return 1;
        }
        return 0;
    }
};

Where count keep track off the number of jumps
*/


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        //cout<<obj.minJumps(arr, n)<<endl;
        int ju=obj.minJumps(arr,n);
        if(ju>0)
        {
            cout<<"Minimum Number of jumps required : "<<ju<<endl;
        }
        else
        {
            cout<<"Jumps are not possible...!!!"<<endl;
        }
    }
    return 0;
}