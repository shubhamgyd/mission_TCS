// Basically in this program we are going to find the total anagrams of the given word. 
//by using the sliding window

#include<bits/stdc++.h>
using namespace std;

int  findAnagrams(string txt, string pat)
    {
        unordered_map<char,int> mp;
        int n = pat.length();
        int m = txt.length();
        for(int i = 0; i < n; i++)
        {
            mp[pat[i]]++;
        }
        int count = mp.size();
        int ans = 0, i = 0, j = 0;
        while(j < m)
        {
            if(mp[txt[j++]]-- == 1)
            { 
                count--;
            }
            if(count == 0) 
            {
                ans++;
            }
            if(j >= n)
            {
                if(mp[txt[i++]]++ == 0) count++;
            }
        }
        return ans;
    }

int main()
{
    string str,str1;
    cin>>str>>str1;
    cout<<findAnagrams(str,str1)<<endl;
    return 0;
}

// #include<bits/stdc++.h>
// using namespace std;

// int FindAnagrams(string str,string str1)
// {
// 	unordered_map<char,int>mp;
// 	int n=str.length();
// 	int m=str1.length();
// 	for(int i=0;i<m;i++)
// 	{	
// 		mp[str1[i]]++;
// 	}
// 	int count=mp.size();
// 	int ans=0;
// 	int i=0,j=0;
// 	while(j<n)
// 	{
// 		if(mp[str[j++]]--==1)
// 		{
// 			count--;
// 		}
// 		if(count==0)
// 		{
// 			ans++;
// 		}
// 		if(j>=m)
// 		{
// 			if(mp[str[i++]]++==0)
// 			{
// 				count++;
// 			}
// 		}
// 	}
// 	return ans;
// }

// int main()
// {	
// 	string str,str1;
// 	cin>>str>>str1;
// 	cout<<FindAnagrams(str,str1);
// 	return 0;
// }
