/*
The parcel section of the Head Post Office is in a mess. The parcels that need to be loaded to the vans have been lined up in a row in an arbitrary order of weights. The Head Post Master wants them to be sorted in the increasing order of the weights of the parcels, with one exception. He wants the heaviest (and presumably the most valuable) parcel kept nearest his office.

You and your friend try to sort these boxes and you decide to sort them by 
interchanging two boxes at a time. Such an interchange needs effort equal 
to the product of the weights of the two boxes.

The objective is to reposition the boxes as required with minimum effort.

Input Format:

The first line consists of two space-separated positive integers giving the 
number of boxes (N) and the position of the Head Post Masters office (k) 
where the heaviest box must be.
The second line consists of N space-separated positive integers giving the 
weights of the boxes. You may assume that no two weights are equal
Output Format:

The output is one line giving the total effort taken to get the boxes in 
sorted order, and the heaviest in position k.
Constraints:

 N<=50 and Weights <= 1000

Sample Input 1:
5 2
20 50 30 80 70
Sample Output 1:
3600
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int mn=INT_MAX;
    int mx=0;
    vector<int>res(n);
    for(int i=0;i<n;i++)
    {
        cin>>res[i];
        mn=min(mn,res[i]);
        mx=max(mx,res[i]);
    }
    int sum=0;
    for(int i=0;i<n-1;i++)
    {
        int mni=min(res[i],res[i+1]);
        int mxi=max(res[i],res[i+1]);
        if(res[i+1]<res[i])
        {
            int l=mxi*mni;
            int r=2*mn*mni+mxi*mn;
            if(l>r)
            {
                sum+=r;
            }
            else
            {
                sum+=l;
            }
            i++;
        }
        else
        {
            i++;
        }
    }

    int d=res[k-1]*mx;
    int di=2*res[k-1]*mn+mn*mx;
    if(d+sum>di+sum)
    {
        cout<<di+sum<<endl;
    }
    else
    {
        cout<<d+sum<<endl;
    }
    return 0;
}
// Time Complexity:O(n)
// Space Complexity:O(1)