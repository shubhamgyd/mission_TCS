#include <iostream>
#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;
 
// Data structure to store a Trie node
struct Trie
{
    // true when the node is a leaf node
    bool isLeaf;
    //int wc=0;
    // each node stores a map to its child nodes
    unordered_map<char, Trie*> map1;
    map<char,int>mp;
};
 
// Function that returns a new Trie node
Trie* getNewTrieNode()
{
    Trie* node = new Trie;
    node->isLeaf = false;
    //node->wc=0;
    return node;
}
 
// Iterative function to insert a string into a Trie
void insert(Trie*& head, char* str)
{
    if (head == nullptr) {
        head = getNewTrieNode();
    }
 
    // start from the root node
    Trie* curr = head;
    while (*str)
    {
        // create a new node if the path doesn't exist
        if (curr->map1.find(*str) == curr->map1.end()) {
            curr->map1[*str] = getNewTrieNode();
            (curr->mp)[*str]=1;
        }
 
        // go to the next node
        else
        {
            curr = curr->map1[*str];
            (curr->mp)[*str]+=1;
        }
 
        // move to the next character
        str++;
    }
 
    // mark the current node as a leaf
    curr->isLeaf = true;
}
 
// Returns true if the given node has any children
bool haveChildren(Trie const* curr)
{
    // don't use `(curr->map).size()` to check for children
 
    for (auto it: curr->map1)
    {
        if (it.second != nullptr) {
            return true;
        }
    }
 
    return false;
}
 
// Recursive function to delete a string from a Trie
bool deletion(Trie*& curr, char* str)
{
    // return if Trie is empty
    if (curr == nullptr) {
        return false;
    }
 
    // if the end of the string is not reached
    if (*str)
    {
        // recur for the node corresponding to the next character in
        // the string and if it returns true, delete the current node
        // (if it is non-leaf)
        if (curr != nullptr && curr->map1.find(*str) != curr->map1.end() &&
            deletion(curr->map1[*str], str + 1) && curr->isLeaf == false)
        {
            if (!haveChildren(curr))
            {
                delete curr;
                curr = nullptr;
                return true;
            }
            else {
                return false;
            }
        }
    }
 
    // if the end of the string is reached
    if (*str == '\0' && curr->isLeaf)
    {
        // if the current node is a leaf node and doesn't have any children
        if (!haveChildren(curr))
        {
            delete curr;    // delete the current node
            curr = nullptr;
            return true;    // delete the non-leaf parent nodes
        }
 
        // if the current node is a leaf node and has children
        else {
            // mark the current node as a non-leaf node (DON'T DELETE IT)
            curr->isLeaf = false;
            return false;   // don't delete its parent nodes
        }
    }
 
    return false;
}
 
// Iterative function to search a string in a Trie. It returns true
// if the string is found in the Trie; otherwise, it returns false.
bool search(Trie* head, char* str)
{
    // return false if Trie is empty
    if (head == nullptr) {
        return false;
    }
 
    Trie* curr = head;
    while (*str)
    {
        // go to the next node
        curr = curr->map1[*str];
 
        // if the string is invalid (reached end of a path in the Trie)
        if (curr == nullptr) {
            return false;
        }
 
        // move to the next character
        str++;
    }
 
    // return true if the current node is a leaf and the
    // end of the string is reached
    return curr->isLeaf;
}
 

// int countPrefix(Trie* head,char* str)
// {
//     // Return false if Trie is empty
//     if(head==NULL)
//     {
//         return 0;
//     }

// }



// Memory efficient Trie implementation in C++ using Map
int main()
{
    Trie* head = nullptr;
 
    int n;
    cout<<"Enter Test Case: ";
    cin>>n;
    while(n--)
    {
        char c[80];
        cout<<"Enter String : ";
        cin>>c;
        insert(head,c);
    }

    cout<<"Enter Query: ";
    int q;
    cin>>q;
    while(q--)
    {
        cout<<"Enter query (search/delete/prefix): ";
        string str;
        cin>>str;
        if(str=="search")
        {
            char s[80];
            cin>>s;
            if(search(head,s))
            {
                cout<<"Enteres String is present in Trie..!!"<<endl;
            }
        }
        if(str=="delete")
        {
            char s[80];
            cin>>s;
            if(deletion(head,s))
            {
                cout<<"Enter word deleted successfully...!!"<<endl;
            }
        }
    }
 
    return 0;
}