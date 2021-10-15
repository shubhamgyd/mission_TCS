#include <bits/stdc++.h>
using namespace std;

int subArrayExists(int arr[], int n)
{
	unordered_set<int> sumSet;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
		if (sum == 0
			|| sumSet.find(sum)
			!= sumSet.end())
			return 1;

		sumSet.insert(sum);
	}
	return 0;
}

int main()
{
    int N;
    cin>>N;
    int arr[N];
    for(int i=0;i<N;i++)
    {
        cin>>arr[i];
    }
	int n = sizeof(arr) / sizeof(arr[0]);
	cout<<subArrayExists(arr, n)<<endl;
	return 0;
}
