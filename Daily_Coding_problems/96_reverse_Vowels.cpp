#include<bits/stdc++.h>
using namespace std;



// utility function to check for vowel
bool isVowel(char c)
{
    return (c=='a' || c=='A' || c=='e' ||
            c=='E' || c=='i' || c=='I' ||
            c=='o' || c=='O' || c=='u' ||
            c=='U');
}
 
// Function to reverse order of vowels
string reverseVowel(string str)
{
    // Start two indexes from two corners
    // and move toward each other
    int i = 0;
    int j = str.length()-1;
    while (i < j)
    {
        if (!isVowel(str[i]))
        {
            i++;
            continue;
        }
        if (!isVowel(str[j]))
        {
            j--;
            continue;
        }
 
        // swapping
        swap(str[i], str[j]);
 
        i++;
        j--;
    }
 
    return str;
}
// Time Complexity:O(n)
// Space Complexity:O(1)



void ReverseVowels(string str)
{
    vector<char>res;
    stringstream ss(str);
    string word;
    while(ss>>word)
    {
        for(auto it:word)
        {
            if(it=='a' or it=='e' or it=='i' or it=='o' or it=='u')
            {
                res.push_back(it);
            }
        }
    }
    int ind=res.size()-1;
    stringstream ss1(str);
    string ans="";
    while(ss1>>word)
    {
        for(int i=0;i<word.length();i++)
        {
            if(word[i]=='a' or word[i]=='e' or word[i]=='i' or word[i]=='o' or word[i]=='u')
            {
                word[i]=res[ind];
                ind--;
            }
        }
        
        ans+=word+" ";
    }
    ans.pop_back();
    cout<<ans<<endl;
}
// Time Complexity:O(n)
// Space Complexity:O(n)



int main()
{
    string str;
    getline(cin,str);
    ReverseVowels(str);
    return 0;
}