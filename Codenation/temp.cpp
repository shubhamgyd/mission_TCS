#include <bits/stdc++.h>
using namespace std;
const int mod=1000000007;


int countUnique(int arr[], int n)
{

	unordered_set<int> mp;
	for (int i = 0; i < n; i++)
		mp.insert(arr[i]);

	int c = pow(mp.size()%mod, 2);

	return c%mod;
}

int main()
{
    int n;
    cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
	cout << countUnique(arr, n);
	return 0;
}