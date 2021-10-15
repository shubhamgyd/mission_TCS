// If the array contains repeated element and we have to return the sequence wise kth smallest/largest
// element from the array

// Then map stl function is very useful

#include <bits/stdc++.h>
using namespace std;
int Kth_smallest(map<int, int> m, int k)
{
	int freq = 0;
	for (auto it = m.begin(); it != m.end(); it++) {
		freq += (it->second); // adding the frequencies of
							// each element
		if (freq >= k) // if at any point frequency becomes
					// greater than or equal to k then
					// return that element
		{
			return it->first;
		}
	}
	return -1; // returning -1 if k>size of the array which
			// is an impossible scenario
}
int main()
{
	//int n = 5;
	int k = 2;
	vector<int> arr = { 12, 3,3,3,3,3, 5,5,5,5, 7, 19 ,19 };
	int n=arr.size();
  map<int, int> m;
	for (int i = 0; i < n; i++) {
		m[arr[i]] += 1; // mapping every element with it's
						// frequency
	}
	int ans = Kth_smallest(m, k);
	cout << "The " << k << "rd smallest element is " << ans
		<< endl;
	return 0;
}




//If array contains repeated element and we  have to return the kth smallest/largest element from the
// unique of this elements then set stl function is very useful

/* the following code demonstrates how to find kth smallest
element using set from C++ STL */

#include <bits/stdc++.h>
using namespace std;

int main()
{

	int arr[] = { 12, 3,3,3,3,3, 5,5,5,5,5, 7, 19 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 4;

	set<int> s(arr, arr + n);
	set<int>::iterator itr
		= s.begin(); // s.begin() returns a pointer to first
					// element in the set
	advance(itr, k - 1); // itr points to kth element in set

	cout << *itr << "\n";

	return 0;
}




// Basic Soluton 
// Quick Sort

#include <climits>
#include <iostream>
using namespace std;

int partition(int arr[], int l, int r);

// This function returns k'th smallest element in arr[l..r] using
// QuickSort based method. ASSUMPTION: ALL ELEMENTS IN ARR[] ARE DISTINCT
int kthSmallest(int arr[], int l, int r, int k)
{
	// If k is smaller than number of elements in array
	if (k > 0 && k <= r - l + 1) {
		// Partition the array around last element and get
		// position of pivot element in sorted array
		int pos = partition(arr, l, r);

		// If position is same as k
		if (pos - l == k - 1)
			return arr[pos];
		if (pos - l > k - 1) // If position is more, recur for left subarray
			return kthSmallest(arr, l, pos - 1, k);

		// Else recur for right subarray
		return kthSmallest(arr, pos + 1, r, k - pos + l - 1);
	}

	// If k is more than number of elements in array
	return INT_MAX;
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// Standard partition process of QuickSort(). It considers the last
// element as pivot and moves all smaller element to left of it
// and greater elements to right
int partition(int arr[], int l, int r)
{
	int x = arr[r], i = l;
	for (int j = l; j <= r - 1; j++) {
		if (arr[j] <= x) {
			swap(&arr[i], &arr[j]);
			i++;
		}
	}
	swap(&arr[i], &arr[r]);
	return i;
}

// Driver program to test above methods
int main()
{
	int arr[] = { 12, 3, 5, 7, 4, 19, 26 };
	int n = sizeof(arr) / sizeof(arr[0]), k = 3;
	cout << "K'th smallest element is " << kthSmallest(arr, 0, n - 1, k);
	return 0;
}
