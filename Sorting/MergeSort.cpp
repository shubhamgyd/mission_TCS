#include<bits/stdc++.h>
using namespace std;

void Merge(int *v,int *L,int leftCount,int *R,int rightCount) {
	int i,j,k;
	// i - to mark the index of left aubarray (L)
	// j - to mark the index of right sub-raay (R)
	// k - to mark the index of merged subarray (A)
	i = 0; j = 0; k =0;

	while(i<leftCount && j< rightCount) {
		if(L[i]  < R[j]) v[k++] = L[i++];
		else v[k++] = R[j++];
	}
	while(i < leftCount) v[k++] = L[i++];
	while(j < rightCount) v[k++] = R[j++];
}

void MergeSort(int *v,int n)
{
    int mid,i,*L,*R;
    if(n<2) return; // Base condition
    mid=n/2;               //Divide array in two part          
    // create left and right subarrays
	// mid elements (from index 0 till mid-1) should be part of left sub-array 
	// and (n-mid) elements (from mid to n-1) will be part of right sub-array
	L = (int*)malloc(mid*sizeof(int)); 
	R = (int*)malloc((n- mid)*sizeof(int)); 
	
	for(i = 0;i<mid;i++) L[i] = v[i]; // creating left subarray
	for(i = mid;i<n;i++) R[i-mid] = v[i]; // creating right subarray

	MergeSort(L,mid);  // sorting the left subarray
	MergeSort(R,n-mid);  // sorting the right subarray
	Merge(v,L,mid,R,n-mid);  // Merging L and R into A as sorted list.
    free(L);
    free(R);
}

int main()
{
    int n;
    cout<<" Enter a number: ";
    cin>>n;;
    int v[n];
    for(int i=0;i<n;i++)
    {
        int a;cin>>a;
        v[i]=a;
    }
    int x=sizeof(v)/sizeof(v[0]);
    MergeSort(v,x);
    cout<<"Sorted array by Merge sort:";
    for(auto ele:v)
    {
        cout<<ele<<" ";
    }
    return 0;
}