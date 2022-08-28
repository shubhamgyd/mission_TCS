#include <iostream>
#include <fstream>
#include <map>
#include <cstring>
#include <sstream>
#include<vector>
#include<algorithm>
#include <iomanip>
#include <ios>

using namespace std;


// Helper function which sort the string according to their counts
bool compare(pair<string,int>s1,pair<string,int>s2)
{ 
    // If two string count is same then it sort them according to alphabetically
    if(s1.second==s2.second)
    {
        return s1.first<s2.first;
    }
    // or else sort according to the count
    return s1.second>s2.second;
}

int main()
{
    const int maxsize = 50000;
    char c;
    char arr[maxsize];
    char *words;
    int *wordCounts;
    int count = 0;
    // Hashmap to store the stirng and count
    map<string,int>wordStore;

    // open file using fstream
    ifstream in;

    // Open the text file in read mode.
    in.open("sample-long.txt");

    // If file doen't exist
    if (!in)
    {
        cout << "Error File Doesn't Exist" << endl;
        exit(-1);
    }
    cin.ignore(c);
    // To store the words
    string word;
    // Read file character by character
    while(in.get(c))
    {
        // if space
        if(isspace(c))
        {
            // add word into hashmap and increase its count
            wordStore[word]++;

            // make word empty
            word="";
        }
        // if any marks, ignore it
        else if(ispunct(c))
        {
            continue;
        }
        //if alphabetic character
        else if(isalpha(c))
        {
            // convert it into lower case
            c=tolower(c);
            // append to word
            word.push_back(c);
        }
    }

    // if there is no space after last char
    if(word.size()>0)
    {
        wordStore[word]++;
    }

    // vector to store the strings along with their counts
    vector<pair<string,int>>wordCount;

    // Push all string and theirs count into vector
    for(auto it:wordStore)
    {
        wordCount.push_back({it.first,it.second});
    }

    // Sort vector by decreasing order of string counts
    sort(wordCount.begin(),wordCount.end(),compare);
    // get size
    int size=wordCount.size();

    // Print first 10 words along with their counts
    cout<<"First 10 words along with their counts: "<<endl;
    cout<<"string   count"<<endl;
    for(int i=0;i<10;i++)
    {
        cout<<wordCount[i].first<<"  = "<<wordCount[i].second<<endl;
    }

    // Print last 10 words along with their counts
    cout<<"\nLast 10 words along with their counts: "<<endl;
    int last=size-10;
    for(int i=last;i<size;i++)
    {
        cout<<wordCount[i].first<<"  = "<<wordCount[i].second<<endl;
    }
    cout<<endl;

    // Print all unique words
    cout<<"All unique words: "<<endl;
    for(auto it:wordStore)
    {
        // if word count is 1 then print it
        if(it.second==1)
        {
            cout<<it.first<<endl;
        }
    }
    return 0;
}