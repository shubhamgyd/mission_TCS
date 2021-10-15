// Palinfrome partition Recursive method

// Basiclly in this program we haev to find out ..minimum number of partition so that string become 
//palindrome in each parition 
// Basically idea behind the que is same as MCM matrix mulitplication

#include<bits/stdc++.h>
using namespace std;


// Primilinary function to check gievn string is palindrome or not to itself
bool isPalindrome(string str,int i,int j)
{
    while(i < j)
    {
      if(str[i] != str[j])
        return false; 
      i++;
      j--;
    }
    return true;
}

int MCM(string str,int i,int j)
{
    // Base condition ...where we can check that length of string it means if length is 1 then we can 
    // retrn 0 or we can check also if given string is already palindrome or not ..that case also we can
    // return 0 ...means no need to more patition
    if(i>=j || isPalindrome(str,i,j)) 
    {
        return 0;
    }
    int mn=INT_MAX;
    
    //Now in the loop we check at every cut means at every incremented position , wheather given partition
    // is palindrome itself or not.
    for(int k=i;k<j;k++)
    {
        // Basically here k makes partition at each step and checking palindromic 
        int temp=MCM(str,i,k)+MCM(str,k+1,j)+1;
        mn=min(mn,temp);
    }
    return mn;
}

int main()
{
    string str="ababbbabbababa";
    int n=str.length();
    int i=0;
    int j=n-1;
    cout<<"Minimum number of cuts required to make palindromic is: "<<MCM(str,i,j)<<'\n';
    return 0;
}