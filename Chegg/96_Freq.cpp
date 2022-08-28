#include <iostream>
#include <fstream>
#include <cstdlib>
#include <filesystem>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    // to get the fileName input
    string fileName="";
    cout<<"Please enter a filename: ";
    cin>>fileName;
    // to read file 
    ifstream filePtr;
    // open file
    filePtr.open(fileName);
    // if file is not present then show error
    if(!filePtr)
    {
        cerr<<"Error: File could not be opened!";
        exit(1);
    }
    // read file character by character
    char ch;
    // to store the frequency of each character
    map<char,int>freq;
    // read file at the end of file pointer
    while(filePtr.good())
    {
        // get the current index character
        filePtr.get(ch);
        // if current char is alphabetic character
        if(isalpha(ch))
        {
            // then convert it to upper case so that we can treat lower case and upper case
            // char same
            char newChar=toupper(ch);
            // increment the frequency of char
            freq[newChar]++;
        }
    }
    // print the freq of each char if present 
    for(auto it:freq)
    {
        cout<<it.first<<"'s"<<": "<<it.second<<endl;
    }
    return 0;
}