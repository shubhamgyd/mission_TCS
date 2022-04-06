#include<bits/stdc++.h>
using namespace std;

int RepeatedLetter(string str)
{
    // part a:  first repeated letters

    // array of 25 characters
    int arr[26];
    // initialize all count as 0
    for(int i=0;i<26;i++)
    {
        arr[i]=0;
    }

    // size of the string
    int size=str.length();

    // traverse the string
    for(int i=0;i<size;i++)
    {
        // index of character
        int indOfChar=str[i]-'a';

        // if we have already found character earlier
        if(arr[indOfChar]>=1)
        {
            // return the index of character inorder to the alphabetically
            return indOfChar;
        }

        // increment the char occurance
        arr[indOfChar]++;
    }

    // if there is no repeated character
    return 26;
}



void charactersCount(string str)
{
    // array of chracters will show us the occurance of characters
    // where arr[26] will indicates that the total number of characters which are not repeated
    int arr[27];

    // initially set all values 0
    for(int i=0;i<27;i++)
    {
        arr[i]=0;
    }

    // length of the string
    int size=str.length();

    // Traverse the string and count the occurance of characters
    for(int i=0;i<size;i++)
    {
        // finding the inde of character
        int indOfChar=str[i]-'a';

        // increment the count of character
        arr[indOfChar]++;
    }

    // now we have condition , if the charater is not repeated then we need to store its
    // count in arr[26], 
    // so now we will traverse the array and check which index have count=1 means this char is occurs
    // only one times in the string and parallely increment the count of arr[26]

    for(int i=0;i<27;i++)
    {
        // this char occur only one time in the string
        if(arr[i]==1)
        {
            // increment the arr[26] count
            arr[26]++;
        }
    }

    cout<<"Character and Occurance"<<endl;
    for(int i=0;i<26;i++)
    {
        char ch='a'+i;
        cout<<ch<<"->"<<arr[i]<<endl;
    }

    cout<<"Non Repeated characters in the string: ";
    cout<<arr[26]<<endl;



    // now we are going to find which character found most of the times in the string

    // initially char is a and it's occurance is 0
    char ch='a';
    int occurance=0;

    // traverse the array and find the occurance of characters
    for(int i=0;i<26;i++)
    {
        // if current char has occur more time than the previous char
        if(arr[i]>occurance)
        {
            occurance=arr[i];
            ch='a'+i;
        }
    }

    cout<<"\nMaximum occured character and occurance "<<endl;
    cout<<ch<<"->"<<occurance<<endl;
}


int main()
{
    cout<<"Enter string: ";
    string str;
    cin>>str;
    // part : a 
    int repeatedChar=RepeatedLetter(str);
    if(repeatedChar==26)
    {
        cout<<"No letter has repeated!!"<<endl;
    }
    else
    {
        cout<<"Position of letter in alphabet: "<<repeatedChar<<endl;
    }

    cout<<endl;
    // part : b and c
    charactersCount(str);

}