// //In this program we are going to find the sum of min and max elements of size k

// // In this problem we are going to find the maximum element of every window of size k

// #include<bits/stdc++.h>
// using namespace std;

// vector<int> findMax(vector<int>&v , int k)
// {
//     int n=v.size();
//     int i=0;
//     int l=0;
//     vector<int>ans;
//     map<int,int>mp;
//     while(i<n)
//     {
//         l++;                           // incrementing the window size
//         mp[v[i]]++;                   // Adding current element to the map
//         if(l==k)                     // if the window size is equal to k
//         {
//             auto itmin=mp.begin();            // points to the first position of the map i.e. minimum position
//             auto itmax=mp.end();              // Points to the last position of the map i.e. maximum position
//             itmax--;          // mp.end point to the out of map , so we decrement one step back so that we can fetch the last max element 
//             // from the map
//             ans.push_back(itmin->first);     // pushing them to the vectore to further result
//             ans.push_back(itmax->first);
//             mp[v[i-k+1]]--;                   // Remove the starting position element i.e. very first element from the map
//             if(mp[v[i-k+1]]==0)               // check if it is zero or not , it yes then remove
//             {
//                 mp.erase(v[i-k+1]);
//             }
//             l--;          // Decrese the window size
//         }
//         i++;              // increment the array position
//     }
//     return ans;
// }

// int main()
// {
//     vector<int>v{5, 4, 3, 2, 1, 6,3, 5, 4, 2, 1};
//     int k=3;
//     vector<int>vs{findMax(v,k)};
//     for(auto ele:vs)
//     {
//         cout<<ele<<" ";
//     }
//     return 0;
// }



#include<bits/stdc++.h>
using namespace std;

void MaxEle(int arr[],int n,int k)
{
	map<int,int>mp;
	int l=0;
	int i=0;
	while(i<n)
	{
		l++;
		mp[arr[i]]++;
		if(l==k)
		{
			auto it=mp.end();
			it--;
            //auto it=mp.begin();
			//cout<<(*it)<<" ";
            cout<<it->first<<" ";
			mp[arr[i-k+1]]--;
			if(mp[arr[i-k+1]]==0)
			{
				mp.erase(arr[i-k+1]);
			}
			l--;
		}
		i++;
		
	}
}

int main()
{	
	int arr[]={1,2,4,2,5,7,6,9,1,2};
	int n=sizeof(arr)/sizeof(arr[0]);
	int k=3;
	MaxEle(arr,n,k);
	return 0;
}
