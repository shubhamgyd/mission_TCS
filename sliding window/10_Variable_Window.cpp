#include<bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {
        int i=0,j=0,MinL=INT_MAX,start=0;
        unordered_map<char,int> mp;

        // Map of the pattern
        for(auto it:t)
            mp[it]++;


        // Size of map
        int count=mp.size();
        

        // If first char is found at zero index
        // Then decrease the value of that key
        // And keep eye on the size of map
        // if value of this char becomes 0 then we no need to find anymore char of same , so we can
        // decrease the size of map by 1
        if(mp.find(s[j])!=mp.end()){
            mp[s[j]]--;
            if(mp[s[j]]==0)
                count--;
        }
        

        // Iterate to the first string
        while(j<s.length()){

            // If size of map is greater zero means we need to find chars of the pattern string
            if(count>0){
                j++;
                // Check wheather jth index char is present in map  or not , is yes then reduce its
                // value by 1 also keep eye on map size
                if(mp.find(s[j])!=mp.end()){
                    mp[s[j]]--;
                    if(mp[s[j]]==0)
                    count--;
                }
            }

            // IF we found all chars present in pattern string, then we no need to find anymore chars
            // now we are finding min length, of substring
            else if(count==0){
                // MinL=min(MinL,j-i+1);
                if(MinL>j-i+1){
                    MinL=j-i+1;
                    start=i;
                }

                // Appending chars in map again, till size of map is zero
                // so that we will get desired substring
                while(count==0){
                    if(mp.find(s[i])!=mp.end()){
                        mp[s[i]]++;
                        if(mp[s[i]]==1){
                            count++;
                            // MinL=min(MinL,j-i+1);
                             if(MinL>j-i+1){
                                MinL=j-i+1;
                                start=i;
                            } 
                        }
                        i++;
                    }
                    else
                        i++;
                }
            }
        }
        string str="";
        if(MinL!=INT_MAX)
            return str.append(s.substr(start,MinL));
        else
            return str;
    }

int main()
{
    string str="abcdefg";
    string s="cdex";
    cout<<minWindow(str,s)<<endl;
    return 0;
}