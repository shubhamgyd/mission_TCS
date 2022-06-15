// In this problem we are going to see , the maximum size of window , with unique characters

#include<bits/stdc++.h>
using namespace std;

int MaxLength(string str)
{
        unordered_map<char,int>mp;
        int mx=0;
        int i=0,j=0;
        int n=str.length();
        while(j<n)
        {
            mp[str[j]]++;  // Updating character in map
            int k=j-i+1;
            if(mp.size()==k)
            {
                mx=max(mx,k);
            }
            else       //we will also have to check for the window right after updating the map in the else case.
            {
                while(mp.size()<k)
                {
                    mp[str[i]]--;
                    if(mp[str[i]]==0)
                    {
                        mp.erase(str[i]);
                    }
                    i++; // Increasing the left side
                    k--; // Shrinking window size
                    if(mp.size()==k)
                    {
                        mx=max(mx,k);  // Updating the window size
                    }
                }
            
            }
            j++;
        }
        return mx;
}

int main()
{
    string str="abdefgabef";
    cout<<"Maximum length of window size ,with unique characters: "<<MaxLength(str)<<endl;
    return 0;
}






/*
Alternative Solution:

int N = str.size();
        vector<int> lastOccur(256, -1);
        
        int res = 0;
        
        int i = 0;
        for(int j = 0; j < N; j++)
        {
            i = max(i, lastOccur[str[j]] + 1);
            
            res = max(res, j - i + 1);
            
            lastOccur[str[j]] = j;
        }
        
        return res;

*/
















// #include<bits/stdc++.h>
// using namespace std;
// int MaxLen(string str)
// {
// 	int n=str.length();
// 	int i=0;
// 	int j=0;
// 	int ans=0;
// 	map<char,int>mp;
// 	while(j<n)
// 	{
// 		mp[str[j]]++;
// 		if(mp.size()==j-i+1)
// 		{
// 			ans=max(ans,j-i+1);
// 		}
// 		else
// 		{
// 			while(mp.size()<j-i+1)
// 			{
// 				mp[str[i]]--;
// 				if(mp[str[i]]==0)
// 				{
// 					mp.erase(str[i]);
// 				}
// 				i++;
// 				j-i+1-1;
// 				if(mp.size()==j-i+1)
// 				{
// 					ans=max(ans,j-i+1);
// 				}
// 			}
// 		}
//         j++;
// 	}
// 	return ans;
// }

// int main()
// {	
// 	string str;
// 	cin>>str;
// 	cout<<MaxLen(str)<<endl;
// 	return 0;
// }
