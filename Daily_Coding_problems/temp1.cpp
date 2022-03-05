#include<bits/stdc++.h>
using namespace std;

// Utility function to take the array input until zero is encountered
// and  reutrn it

vector<int> Input()
{
	// vector is dynamic list to store the elements
	vector<int>arr;
	// we will take inout from user until 0 in encountered
	while(true)
	{
		cout<<"Enter element: ";
		int number;
		cin>>number;

		// if input number is 0 then stop to take inout
		if(number==0)
		{
			break;
		}
		else{
			arr.push_back(number);
		}
	}
	//  return the list
	return arr;
}


// Utility function, which find the min and max element from the list and print them
void findMinMax(vector<int>&arr)
{
	// mn will keep track on the minimum element
	int mn=INT_MAX;
	int n=arr.size();
	for(int i=0;i<n;i++)
	{
		// here we are comparing each element to find the minimum element
		mn=min(mn,arr[i]);
	}

	// mx will keep track on the maximum element
	int mx=INT_MIN;
	for(int i=0;i<n;i++)
	{
		// here we are comparing each element to find the maximum element;
		mx=max(mx,arr[i]);
	}

	cout<<"List: ";
	// printing the list as we taken from the user
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<"\nMinimum Element: "<<mn<<endl;
	cout<<"Maximum Element: "<<mx<<endl;
}

int main()
{
	// here we are taking the input list and storing it
	vector<int>arr=Input();
	

	//function to find the min and max
	findMinMax(arr);
	return 0;
}