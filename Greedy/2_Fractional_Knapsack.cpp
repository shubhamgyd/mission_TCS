#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        vector<pair<double,int>>res;
        for(int i=0;i<n;i++)
        {
            double x=(arr[i].value*1.0)/(arr[i].weight*1.0);
            res.push_back({x,i});
        }
        sort(res.begin(),res.end(),greater<pair<double,int>>());
        int sum=0;
        double ans=0;
        for(auto it:res)
        {
            if(sum+arr[it.second].weight<W)
            {
                ans+=arr[it.second].value;
                sum+=arr[it.second].weight;
            }
            else
            {
                double x=(W-sum)*1.0;
                ans+=(x*it.first);
                break;
            }
        }
        return ans;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  