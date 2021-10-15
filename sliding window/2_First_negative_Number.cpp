// // // In this problem we are going to find the first negative number of k size window

// // #include<bits/stdc++.h>
// // using namespace std;


// // void firstNegative(int arr[],int n,int k)
// // {
// //     // For storing the useful elements from the array
// //     deque<int>dq; // That is we are storing the index of  negative elements in this deque

// //     // first slide the k elements to store the -ve elements
// //     int i;
// //     for(i=0;i<k;i++)
// //     {
// //         if(arr[i]<0)
// //         {
// //             dq.push_back(i);
// //         }
// //     }
// //     //cout<<" i : "<<i<<endl;

// //     // Now we are processing the rest of element from the arr[k] to arr[n-1]

// //     for(;i<n;i++)
// //     {
// //         // if the dq is not empty , then the front element from the dq is the negative element from the 
// //         // previous window
// //         if(!dq.empty())
// //         {
// //             cout<<arr[dq.front()]<<" ";
// //         }

// //         // else the previous window does not gave any kind of negative integer
// //         else
// //         {
// //             cout<<0<<" ";
// //         }

// //         // Now if dq is not empty and the current window is less than i-k+1 then we are going to pop out it
// //         while(!dq.empty()&&dq.front()<(i-k+1))
// //         {
// //             dq.pop_front(); // Removing the front elements from the deque
// //         }

// //         // Addinng the current element at the rear the dq , if it is negative
// //         if(arr[i]<0)
// //         {
// //             dq.push_back(i);
// //         }
// //     }

// //     // After traversing all the window , last window element is remaining , so for printing the last
// //     // window  element 
// //     if(!dq.empty())
// //     {
// //         cout<<arr[dq.front()]<<" ";
// //     }
// //     else
// //     {
// //         cout<<0<<" ";
// //     }

// // }

// // /*
// // Time Complexity: O(n) 
// // Auxiliary Space: O(k)
// // */
// // int main()
// // {
// //     int arr[]={12, -1, -7, 8, -15, 30, 16, 28};
// //     int n=sizeof(arr)/sizeof(arr[0]);
// //     int k=3;
// //     firstNegative(arr,n,k);
// //     return 0;
// // }





// /* Optimise Approach */


// #include<bits/stdc++.h>
// using namespace std;

// void printFirstNegativeInteger(int arr[], int k, int n)
// {
// 	int firstNegativeIndex = 0;
// 	int firstNegativeElement;
	
	
// 	for(int i = k - 1; i < n; i++)
// 	{
	
// 		// skip out of window and positive elements
// 		while((firstNegativeIndex < i ) &&
// 			(firstNegativeIndex <= i - k ||
// 			arr[firstNegativeIndex] > 0))
// 		{
// 			firstNegativeIndex ++;
// 		}
		
// 		// check if a negative element is found, otherwise use 0
// 		if(arr[firstNegativeIndex] < 0)
// 		{
// 			firstNegativeElement = arr[firstNegativeIndex];
// 		}
// 		else
// 		{
// 			firstNegativeElement = 0;
// 		}
// 		cout<<firstNegativeElement << " ";
// 	}
	
// }

// /*
// Time Complexity: O(n) 
// Auxiliary Space: O(1)
// */

// int main()
// {
// 	int arr[] = { 12, -1, -7, 8, -15, 30, 16, 28};
// 	int n = sizeof(arr)/sizeof(arr[0]);
// 	int k = 3;
// 	printFirstNegativeInteger(arr, k, n);
// }


#include<bits/stdc++.h>
using namespace std;

void FirstNegative(int arr[],int n,int k)
{
	int index=0;
	int element=0;
	for(int i=k-1;i<n;i++)
	{
	while(index<i && (index<=i-k || arr[index]>0))
	{	
		index++;
	}
	if(arr[index]<0)
	{
		element=arr[index];
	}
	else
	{
		element=0;
	}
	cout<<element<<" ";
	}
}


int main()
{	
	int arr[]={1,-2,3,-4,5,1};
	int n=sizeof(arr)/sizeof(arr[0]);
	int k=2;
	FirstNegative(arr,n,k);
	return 0;
}
