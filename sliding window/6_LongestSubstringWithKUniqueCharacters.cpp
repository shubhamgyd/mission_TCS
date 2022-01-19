// In this problem we are going to , find the maximum length of substring of k unique characters

// This problem is similar to the maximum selection of 2 toys among the length of string 


#include<bits/stdc++.h>
using namespace std;


int main()
{
    string str="aaabb";
    //cin>>str;
    int n=str.length();
    int k=3;  // Condition of selection of largest substring of k unique characters 
     // Condition of selection of largest selection of toys among the given strings 
    int mx=INT_MIN;
    int i=0,j=0;
    unordered_map<char,int>mp;
    while(j<n)
    {
        mp[str[j]]++;
        if(mp.size()<k)
        {
            j++;
        }
        else if(mp.size()==k)
        {
            mx=max(mx,j-i+1);
            j++;
        }
        else if(mp.size()>k)
        {
            while(mp.size()>k)
            {
                mp[str[i]]--;
                if(mp[str[i]]==0)
                {
                    mp.erase(str[i]);
                }
                i++;
            }
            j++;
        }
    }
    if(mx!=INT_MIN)
    {
        cout<<"Maximum length of the longest substring with k unique characters : "<<mx<<endl;
        cout<<"Maximum Number of selected toys among the given condition : "<<mx<<endl;
    }
    else
    {
        cout<<"Not Valid"<<endl;
    }
    return 0;
}

// #include<bits/stdc++.h>
// using namespace std;

// int MaxLen(string str,int k)
// {
// 	int n=str.length();
//     if(k>n)
//     {
//         return -1;
//     }
// 	unordered_map<char,int>mp;
// 	int i=0;
// 	int j=0;
// 	int ans=INT_MIN;
// 	while(j<n)
// 	{
// 		mp[str[j]]++;
// 		if(mp.size()<k)
// 		{
// 			j++;
// 		}
// 		else if(mp.size()==k)
// 		{
// 			ans=max(ans,j-i+1);
// 			j++;
// 		}
// 		else if(mp.size()>k)
// 		{
// 			while(mp.size()>k)
// 			{
// 				mp[str[i]]--;
// 				if(mp[str[i]]==0)
// 				{
// 					mp.erase(str[i]);
// 				}
// 				i++;
// 			}
// 			j++;
// 		}

// 	}
// 	return ans;
// }

// int main()
// {	
// 	string str;
// 	cin>>str;
// 	int k=5;
// 	cout<<MaxLen(str,k)<<endl;
// 	return 0;
// }
