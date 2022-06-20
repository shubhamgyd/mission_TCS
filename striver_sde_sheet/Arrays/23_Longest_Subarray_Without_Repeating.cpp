/*
Problem Statement: Given a String, find the length of longest substring without any
repeating character.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int n = str.length();

    // Brute Force
    // Approach: This approach consists of taking the two loops one for traversing the
    // string and another loop – nested loop for finding different substrings and after that,
    // we will check for all substrings one by one and check for each and every element
    // if the element is not found then we will store that element in HashSet otherwise
    // we will break from the loop and count it.

    int mxLen = 0;
    for (int i = 0; i < n; i++)
    {
        set<int> st;
        for (int j = i; j < n; j++)
        {
            st.insert(str[j]);
            int size = st.size();
            if (size == j - i + 1)
            {

                mxLen = max(mxLen, size);
            }
        }
    }
    cout << "MxLen: " << mxLen << endl;
    // T:O(n*n)
    // S:O(n)

    // Using Sliding Window
    // Approach: We will have two pointers left and right. Pointer ‘left’ is used for
    //  maintaining the starting point of substring while ‘right’ will maintain the 
    // endpoint of the substring.’ right’ pointer will move forward and check for the 
    // duplicate occurrence of the current element if found then ‘left’ pointer will be 
    // shifted ahead so as to delete the duplicate elements.

    unordered_map<char,int>mp;
    int i=0;
    int j=0;
    int len=0;
    while(j<n)
    {
        mp[str[j]]++;
        // if window size== number of characters
        if(mp.size()==j-i+1)
        {
            len=max(len,j-i+1);
        }
        else{
            while(mp.size()<(j-i+1))
            {
                mp[str[i]]--;
                if(mp[str[i]]==0)
                {
                    mp.erase(str[i]);
                }
                i++;
                if(mp.size()==(j-i+1))
                {
                    len=max(len,j-i+1);
                }
            }
        }
        j++;
    }
    cout<<"MxLen: "<<len<<endl;
    // T:O(n*n)
    // S:O(n)
    


    // Using Liner Time: 
    int arr[256];
    memset(arr,-1,sizeof(arr));
    int k=0;
    int ans=0;
    for(int j=0;j<len;j++)
    {
        // last index of current char
        k=max(k,arr[str[j]]+1);
        int range=j-k+1;
        ans=max(ans,range);
        arr[str[j]]=j;
    }
    cout<<"mxLen: "<<ans<<endl;
    // T:O(n)
    // S:O(256)
}