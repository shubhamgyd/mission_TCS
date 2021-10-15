// In this program we are going to find the position of first and the last occurance of an element

// Also this problem is useful for count the number of element in a sorted arry 
// for that use formula : last-first+1
#include<bits/stdc++.h>
using namespace std;

int first_pos(vector<int>&v,int x)
{
        int n=v.size();
        int first_pos=n;
        int low=0,high=n-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(v[mid]>=x)
            {
                first_pos=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return first_pos;
}
int main()
{
    //int arr[]={1,2,3,4,5,5,5,6,7,8};
    vector<int>v= {1,2,3,4,5,5,5,6,7,8};
    //int n=sizeof(arr)/sizeof(arr[0]);
    int target=0;
    int pos1=first_pos(v,target);
    int pos2=first_pos(v,target+1)-1;
    if(pos1<=pos2)
    {
        cout<<"First Occurance: "<<pos1<<" Second occurance at: "<<pos2<<endl;
    }
    else
    {
        cout<<-1<<" "<<-1<<endl;
    }
    return 0;

}