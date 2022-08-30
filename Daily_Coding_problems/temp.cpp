// #include<bits/stdc++.h>
// using namespace std;


// void rotate_right(char* input1,int input2)
// {
// 	int len=strlen(input1);
// 	char *arr;
// 	arr=(char*)malloc(len*1);
// 	if(input2>=len) printf("%s",input1);
// 	int ind=0;
// 	for(int i=len-input2;i<len;i++)
// 	{
// 		arr[ind]=input1[i];
// 		ind++;
// 	}
// 	for(int i=0;i<len-input2;i++)
// 	{
// 		arr[ind]=input1[i];
// 		ind++;
// 	}
// 	printf("%s",arr);
// 	// return (char *)arr;
// }

// char* left_rotate(char* input1,int input2)
// {
// 	int len=strlen(input1);
// 	if(len>=input2) return input1;
// 	char *arr;
// 	arr=(char*)malloc(len*1);
// 	int ind=0;
// 	for(int i=input2;i<len;i++)
// 	{
// 		arr[ind]=input1[i];
// 		ind++;
// 	}
// 	for(int i=0;i<input2;i++)
// 	{
// 		arr[ind]=input1[i];
// 		ind++;
// 	}
// 	return (char *)arr;
// }

// int main()
// {
// 	// char arr[7]
// 	// char *arr;
// 	// arr=(char*)malloc(7*1);
// 	char arr[8]="abcdxyz";
// 	rotate_right(arr,2);
// 	// printf("%s",ans);
	
// 	// ios_base::sync_with_stdio(0);
// 	// cout.tie(0);
// 	// cout.tie(0);
// 	// int n;
// 	// cin>>n;
// 	// string str;
// 	// cin>>str;
// 	// str.resize(n);
// 	// int mx=0;
// 	// for(int i=0;i<n;i++)
// 	// {
// 	// 	int num=str[i]-'0';
// 	// 	mx=max(mx,num);
// 	// }
// 	// cout<<mx<<"\n";
// 	return 0;
// }

#include<bits/stdc++.h>
using namespace std;

vector<int> findDataLocations(vector<int>&locations,vector<int>&movedFrom,vector<int>&movedTo)
{
	int n=movedFrom.size();
	map<int,bool>mp;
	for(auto it:locations)
	{
		mp[it]=true;
	}
	for(int i=0;i<n;i++)
	{
		mp[movedFrom[i]]=false;
		mp[movedTo[i]]=true;
	}
	vector<int>ans;
	for(auto it:mp)
	{
		if(it.second==true)
		{
			ans.push_back(it.first);
		}
	}
	return ans;
}

// int main()
// {
// 	int n;
// 	cin>>n;
// 	vector<int>nums(n);
// 	for(int i=0;i<n;i++)
// 	{
// 		cin>>nums[i];
// 	}
// 	int m;
// 	cin>>m;
// 	vector<int>moveFrom(m),moveTo(m);
// 	for(int i=0;i<m;i++)
// 	{
// 		cin>>moveFrom[i];
// 	}
// 	for(int i=0;i<m;i++)
// 	{
// 		cin>>moveTo[i];
// 	}
// 	vector<int>ans=findDataLocations(nums,moveFrom,moveTo);
// 	for(auto it:ans)
// 	{
// 		cout<<it<<" ";
// 	}
// 	return 0;
// }

long findMaximumSum(vector<int>&stockPrice,int k)
{
	int n=stockPrice.size();
	long pref[n];
	pref[0]=stockPrice[0];
	for(int i=1;i<n;i++)
	{
		pref[i]=pref[i-1]+stockPrice[i];
	}
	long max_sum=0;
	map<int,int>mp;
    for(int i=0;i<k;i++)
    {
		if(mp.find(stockPrice[i])==mp.end())
		{
			max_sum+=stockPrice[i];
		}
		else
		{
			max_sum=0;
			break;
		}
		mp[stockPrice[i]]++;
    }

	int j=0;
    for(int i=k;i<n;i++)
    {
		mp[stockPrice[j]]--;
		if(mp[stockPrice[j]]==0)
		{
			mp.erase(stockPrice[j]);
		}
		j++;
		if(mp.find(stockPrice[i])==mp.end() and mp.size()==k-1)
		{
			max_sum=max(max_sum,pref[i]-pref[j-1]);
		}
		mp[stockPrice[i]]++;
    }
    return max_sum;
}

int main()
{
	int n;
	cin>>n;
	vector<int>nums(n);
	for(int i=0;i<n;i++)
	{
		cin>>nums[i];
	}
	int k;
	cin>>k;
	int ans=findMaximumSum(nums,k);
	cout<<ans<<endl;
}