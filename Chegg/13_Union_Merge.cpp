#include<bits/stdc++.h>
using namespace std;

void unionOfLists(vector<int>&A,vector<int>&B)
{
    int size1=A.size();                 // size of list1
    int size2=B.size();                 // size of list2

    // map data structure for stoing lists elements
    // it helps us to remove duplicates and also it stores the 
    // frequency of elements

    // Also map sort the elements inside it
    map<int,int>unionSet;

    //Inserting list1 elements into unionSet map
    for(int i=0;i<size1;i++)
    {
        unionSet[A[i]]++;
    }

    // Inserting list2 elements into unionSet map
    for(int i=0;i<size2;i++)
    {
        unionSet[B[i]]++;
    }

    cout<<"\nUnion set of both list1 and list2 is: "<<endl;


    cout<<"List1: ";
    for(auto it:A) cout<<it<<" ";
    cout<<endl;
    cout<<"List2: ";
    for(auto it:B) cout<<it<<" ";
    cout<<endl;


    // unionSet will contain only distinct elements from list1 and list2
    cout<<"\nUnion: ";
    for(auto itr=unionSet.begin();itr!=unionSet.end();itr++)
    {
        cout<<itr->first<<" ";
    }
    cout<<endl;
}
// Time complexity:O(n+m)
// n is lenth of list1
// m is length of list2




// Utility function which merge two sorted list together
void MergeUtil(int *arr,int *LeftList,int lCount,int *RightList,int rCount) {
	int i,j,k;
	// i - to mark the index of left aubarray (LeftList)
	// j - to mark the index of right sub-raay (RightList)
	// k - to mark the index of merged subarray (arr)
	i = 0; j = 0; k =0;

    // compare all elements of leftlist and rightlist
	while(i<lCount && j< rCount) {

        // if leftlist element is smaller than rightlist element 
        // then append it in sorted array list
		if(LeftList[i]  < RightList[j]) arr[k++] = LeftList[i++];

        
        // else append right list element to the sorted array
		else arr[k++] = RightList[j++];
	}

    // if any element is left behind , then append them into the last of sorted array
	while(i < lCount) {
        arr[k++] = LeftList[i++];
    }
	while(j < rCount) {
        arr[k++] = RightList[j++];
    }
}

// Utility function which divide list and sort them
void MergeSortUtil(int *arr,int n)
{
    int midPos,i,*LeftList,*RightList;

    if(n<2) return; // Base condition

    midPos=n/2;               //Divide array in two part    

    // create left and right subarrays
	// mid elements (from index 0 till mid-1) should be part of left sub-array 
	// and (n-mid) elements (from mid to n-1) will be part of right sub-array
	LeftList = (int*)malloc(midPos*sizeof(int)); 
	RightList = (int*)malloc((n- midPos)*sizeof(int)); 
	


    // creating left subarray
	for(i = 0;i<midPos;i++){
        LeftList[i] = arr[i]; 
    }

    // creating right subarray
	for(i = midPos;i<n;i++){
        RightList[i-midPos] = arr[i]; 
    }


	MergeSortUtil(LeftList,midPos);  // sorting the left subarray
	MergeSortUtil(RightList,n-midPos);  // sorting the right subarray


    // Merging L and R into A as sorted list.
	MergeUtil(arr,LeftList,midPos,RightList,n-midPos);


    // free the memory(deallocation) of left part and right part
    free(LeftList);                 
    free(RightList);                
}

void mergeSort(int list[],int size)
{
    cout<<"\nInitial List: ";
    for(int i=0;i<size;i++) cout<<list[i]<<" ";
    cout<<endl;

    // call function
    MergeSortUtil(list,size);
    cout<<"\nSorted list : ";
    for(int i=0;i<size;i++)
    {
        cout<<list[i]<<" ";
    }
    cout<<endl;
}


int main()
{
    // vector<int>A{3,4,7,9,8,5};
    // vector<int>B{5,7,6,2,1,8,9};
    // unionOfLists(A,B);

    int list[9]={3,4,7,9,8,5,6,2,1};
    mergeSort(list,9);
}