/*
This problem was asked by Twitter.

Implement an autocomplete system. That is, given a query string s and a set of all possible 
query strings, return all strings in the set that have s as a prefix.

For example, given the query string de and the set of strings [dog, deer, deal], return [deer, deal].

Hint: Try preprocessing the dictionary into a more efficient data structure to speed up queries.

*/

// Basically this is the trie data structure problem

#include<bits/stdc++.h>
using namespace std;

struct Trie
{
    bool endOfWord;
    struct Trie *children[26];
};

// Get new node
struct Trie* getNode()
{
    struct Trie *newNode=new Trie;
    newNode->endOfWord=false;
    for(int i=0;i<26;i++)
    {
        newNode->children[i]=NULL;
    }
    return newNode;
}


// Insert into trie
void InsertNode(struct Trie *root,string s)
{
    struct Trie *pNode=root;
    int n=s.length();
    for(int i=0;i<n;i++)
    {
        int index=s[i]-'a';
        if(!pNode->children[index])
        {
            pNode->children[index]=getNode();
        }
        pNode=pNode->children[index];
    }
    pNode->endOfWord=true;
}



void prefixSuggestions(struct Trie *root,string s)
{
    if(root->endOfWord)
    {
        cout<<s<<endl;
    }
    int flag=0;
    for(int i=0;i<26;i++)
    {
        if(root->children[i])
        {
            flag=1;
            break;
        }
    }
    if(!flag)
    {
        return;
    }
    for(int i=0;i<26;i++)
    {
        if(root->children[i])
        {
            s.push_back(97+i);
            prefixSuggestions(root->children[i],s);
            s.pop_back();
        }
    }
}

void prefixSearch(Trie *root,string s)
{
    Trie *pNode=root;
    int n=s.length();
    for(int i=0;i<n;i++)
    {
        int index=s[i]-'a';
        if(!pNode->children[index])
        {
            cout<<"No such prefix exist...!!!";
            return ;
        }
        pNode=pNode->children[index];
    }
    int flag=0;
    for(int i=0;i<26;i++)
    {
        if(pNode->children[i])
        {
            flag=1;
            break;
        }
    }

    if(pNode==NULL)
    {
        return;
    }

    if(!flag && pNode->endOfWord)
    {
        cout<<s<<endl;
        return;
    }
    prefixSuggestions(pNode,s);
}


int main()
{
    string s="de";
    vector<string>list={"dpg","deer","deal"};
    struct Trie *root=getNode();
    for(auto it:list)
    {
        InsertNode(root,it);
    }
    prefixSearch(root,s);
}


/*
Insert and search costs O(key_length), however the memory requirements of 
Trie is O(ALPHABET_SIZE * key_length * N) where N is number of keys in Trie.
*/