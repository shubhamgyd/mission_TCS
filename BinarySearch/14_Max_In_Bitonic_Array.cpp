// This problem is similar to previous que peak element in the array.
// Bitonic: 
//       First Mocotically increasing and then monotically decreasing

#include<bits/stdc++.h>
using namespace std;


int findBitonicMax(vector<int>a,int low,int high)
{
    while(low<=high)
    {
        int mid=(low+high)/2;

		if(a[mid]>a[mid-1] && a[mid]>a[mid+1]) //the maximum
			//return a[mid];
            return mid;
		if(a[mid]>a[mid-1] && a[mid]<a[mid+1]) //in increasing zone
			low=mid+1;
		if(a[mid]<a[mid-1] && a[mid+1]<a[mid]) //in decreasing zone
			high=mid-1;
    }
    //return a[a.size()-1];
    return a.size()-1;
}

int main()
{
    int x;
    cin>>x;
    vector<int>v;
    for(int i=0;i<x;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    int n=v.size();
    cout<<" Peak element index  in given Bitonic array is: "<<findBitonicMax(v,0,n-1)<<endl;
}

