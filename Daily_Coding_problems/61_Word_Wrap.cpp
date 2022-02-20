/*
Good morning! Here's your coding interview problem for today.

This problem was asked by Amazon.

Given a string s and an integer k, break up the string into multiple lines such 
that each line has a length of k or less. You must break it up so that words don't 
break across lines. Each line has to have the maximum possible amount of words. If 
there's no way to break the text up, then return null.

You can assume that there are no spaces at the ends of the string and that there is 
exactly one space between each word.

For example, given the string "the quick brown fox jumps over the lazy dog" and k = 10, 
you should return: ["the quick", "brown fox", "jumps over", "the lazy", "dog"]. 
No string in the list has a length of more than 10.
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str="THESE TERMS AND CONDITIONS OF SERVICE (the Terms) ARE A LEGAL AND BINDING AGREEMENT BETWEEN YOU AND NATIONAL GEOGRAPHIC governing your use of this site, www.nationalgeographic.com, which includes but is not limited to products, software and services offered by way of the website such as the Video Player, Uploader, and other applications that link to these Terms (the Site). Please review the Terms fully before you continue to use the Site. By using the Site, you agree to be bound by the Terms. You shall also be subject to any additional terms posted with respect to individual sections of the Site. Please review our Privacy Policy, which also governs your use of the Site, to understand our practices. If you do not agree, please discontinue using the Site. National Geographic reserves the right to change the Terms at any time without prior notice. Your continued access or use of the Site after such changes indicates your acceptance of the Terms as modified. It is your responsibility to review the Terms regularly. The Terms were last updated on 18 July 2011.";
    // getline(cin,str);
    int k=80;
    // cin>>k;
    vector<string>ans;
    stringstream ss(str);
    string word;
    string res="";
    while(ss>>word)
    {
        // cout<<"words: "<<word<<endl;
        if(word.length()>k)
        {
            cout<<"Cannot complete becuse of the word "<<word<<endl;
            return 0;
        }
        if(res.length()+word.length()<=k)
        {
            if(res.empty())
            {
                res+=word;
            }
            else if(res.length()+1+word.length()<=k)
            {
                res+=" "+word;
            }
            // cout<<"new String1: "<<res<<endl;
            if(res.length()==k)
            {
                ans.push_back(res);
                res="";
            }

        }
        else
        {
            // cout<<"new String2: "<<res<<endl;
            ans.push_back(res);
            res=word;
        }
    }
    if(res.size())
    {
        ans.push_back(res);
    }
    for(auto it:ans)
    {
        cout<<it<<endl;
    }
    return 0;
}
// Time Complexity:O(n)
// Space Complexity:O(n)