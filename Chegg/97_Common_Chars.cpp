#include <iostream>
#include <map>
using namespace std;

int main()
{
    // Declaration of String1 and String2
    string str1,str2;
    // User Input of String1 and String2
    cin>>str1;
    cin>>str2;
    // HashMap to store the characters present in string2
    map<char,int>charsOfStr2;
    // Iterate string2 and push each character into hashmap
    for(int i=0;i<str2.length();i++)
    {
        // we are ignoring chars sensitive case
        // converting char to lowercase
        char ch=tolower(str2[i]);
        // pushing into hash map alog with the index 
        charsOfStr2[ch]=i;
    }
    // Iterate the first string
    for(int i=0;i<str1.length();i++)
    {
        // convert current char into the lower case
        char ch=tolower(str1[i]);
        // check it is present in the hashmap or not
        // if it is not present then print it
        // otherwise ignore it
        if(charsOfStr2.find(ch)==charsOfStr2.end())
        {
            cout<<ch<<" ";
        }
    }
    cout<<endl;
    // now again iterate string1
    for(int i=0;i<str1.length();i++)
    {
        // convert current char into the lower case
        char ch=tolower(str1[i]);
        // check it is present in the hashmap or not
        // if it is not present then print it along with 
        // the index of current char in string1 and in string2
        if(charsOfStr2.find(ch)!=charsOfStr2.end())
        {
            // char       ind1        ind2
            cout<<ch<<": "<<i<<" "<<charsOfStr2[ch]<<endl;
        }
    }
    return 0;
}