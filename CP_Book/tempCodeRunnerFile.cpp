// C++ program to find largest Fibonacci subset
#include<bits/stdc++.h>
using namespace std;

// Prints largest subset of an array whose
// all elements are fibonacci numbers
vector<int> findFibSubset(vector<int>arr)
{
    vector<int>ans;
    int n=arr.size();
	int mx =*max_element(arr.begin(),arr.end());

	int a = 0, b = 1;
	unordered_set<int> hash;
	hash.insert(a);
	hash.insert(b);
	while (b < mx)
	{
		int c = a + b;
		a = b;
		b = c;
		hash.insert(b);
	}
	for (int i=0; i<n; i++)
	{
        if (hash.find(arr[i]) != hash.end())
		{
            ans.push_back(arr[i]);
        }
    }
    
    vector<int>temp;
    if(ans.size()==0)
    {
        temp.push_back(-1);
        return temp;
    }
    return ans;
}

// Driver code
int main()
{
    int n;
    cin>>n;

    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
	
	vector<int>res=findFibSubset(arr);
    for(auto it:res)
    {
        cout<<it<<" ";
    }
	return 0;
}
