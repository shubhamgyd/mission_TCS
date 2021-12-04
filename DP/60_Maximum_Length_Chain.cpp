/*
You are given N pairs of numbers. In every pair, the first number is always smaller 
than the second number. A pair (c, d) can follow another pair (a, b) if b < c. 
Chain of pairs can be formed in this fashion. You have to find the longest chain 
which can be formed from the given set of pairs.  
*/

#include<bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};



int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

/*You are required to complete this method*/

static bool cmp(const val&a,const val&b){
return(b.second>a.second);
}
int maxChainLen(struct val p[],int n)
{
//Your code here
    int res=0;
    int *dp=new int[sizeof(int )*n];
    //int dp[n];
    //int value=0;
    //int count=0;
    sort(p,p+n,cmp);
    // for(int i=0;i<n;i++)
    // {
    //     cout<<p[i].first<<" "<<p[i].second<<endl;
    // }
    // cout<<endl;
    for(int i=0;i<n;i++)
    {
        dp[i]=1;
    }
    for(int i=1;i<n;i++)
    {
        //dp[i]=1;
        //value=p[i].second;
        for(int j=0;j<i;j++)
        {
            if(p[i].first>p[j].second && dp[i]<dp[j]+1)
            {
                //dp[i]=max(dp[i],dp[j]+1);
                // count++;
                // dp[i]=max(dp[i],count);
                // value=p[j].second;
                dp[i]=dp[j]+1;
            }
        }
        //res=max(res,dp[i]);
    }
    for(int i=0;i<n;i++)
    {
        if(res<dp[i])
        {
            res=dp[i];
        }
    }
    return res;
}



//Another one shortest O(n)
// Space O(1)
/*

class Solution {
public:
int findLongestChain(vector<vector>& pairs) {

    sort(pairs.begin(),pairs.end());
    
    int curr=INT_MAX,res=0;
    
    for(int i=pairs.size()-1;i>=0;i--)
    {
        if(pairs[i][1]<curr)
        {
            res++;
            curr=pairs[i][0];
        }
    }
    return res;
}
};
*/