#define ll long long
#include <bits/stdc++.h>
#include<stdio.h>
using namespace std;




struct Trie
{
    struct Trie *children[26];
    bool endOfWord;
};

struct Trie *getNode(void)
{
    struct Trie *pnode=new Trie;
    pnode->endOfWord=false;
    for(int i=0;i<26;i++)
    {
        pnode->children[i]=NULL;
    }
    return pnode;
}

void insert(struct Trie *root,string s)
{
    struct Trie *p=root;
    int n=s.length();
    for(int i=0;i<n;i++)
    {
        int k=s[i]-'a';
        if(!p->children[k])
        {
            p->children[k]=getNode();
        }
        p=p->children[k];
    }
    p->endOfWord=true;

}


bool search(struct Trie *root,string s)
{
    struct Trie *p=root;


    int n=s.length();
    for(int i=0;i<n;i++)
    {
        int k=s[i]-'a';
        if(p->children[k]==NULL)
        {
            return false;
        }

        p=p->children[k];

    }
    return ( p->endOfWord && p!=NULL);

}


// Returns true if root has no children, else false
bool isEmpty(struct Trie* root)
{
    for (int i = 0; i <26; i++)
        if (root->children[i])
            return false;
    return true;
}
 
// Recursive function to delete a key from given Trie
Trie* Delete(Trie* root, string key, int depth = 0)
{
    // If tree is empty
    if (!root)
        return NULL;
 
    // If last character of key is being processed
    if (depth == key.size()) {
 
        // This node is no more end of word after
        // removal of given key
        if (root->endOfWord)
            root->endOfWord = false;
 
        // If given is not prefix of any other word
        if (isEmpty(root)) {
            delete (root);
            root = NULL;
        }
 
        return root;
    }
 
    // If not last character, recur for the child
    // obtained using ASCII value
    int index = key[depth] - 'a';
    root->children[index]=Delete(root->children[index], key, depth + 1);
 
    // If root does not have any child (its only child got
    // deleted), and it is not end of another word.
    if (isEmpty(root) && root->endOfWord == false) {
        delete (root);
        root = NULL;
    }
 
    return root;
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
        return;
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

void prefixSearch(struct Trie *root,string s)
{
    struct Trie *p=root;

    for(int i=0;i<s.length();i++)
    {
        int k=s[i]-'a';
        if(!p->children[k])
        {
            cout<<"No such prefix exist..!!"<<endl;
            return;
        }
        p=p->children[k];

    }
    int flag=0;
    for(int i=0;i<26;i++)
    {
        if(p->children[i])
        {
            flag=1;
            break;
        }
    }
    if(p==NULL)
        return;
    if(!flag&&p->endOfWord)
    {
        cout<<s<<endl;
        return;
    }

    prefixSuggestions(p,s);
}


int main ()
{
    struct Trie *root= getNode();
//  string keys[] = {"the", "a", "there","answer", "any", "Gopale","by","bye", "their","yo","yoyo","ni","nigga","Niggardly","Never"};
//     int n = sizeof(keys)/sizeof(keys[0]);

   // struct Trie *root = getNode();

    // Construct trie
    int n;
    cout<<"Enter number to add Strings in Trie: ";
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter string: ";
        string str;
        cin>>str;
        insert(root,str);
    }

    while(true)
    {
        cout<<"Enter query(search/prefix/delete): ";
        string s;
        cin>>s;
        if(s=="search")
        {
            cout<<"Enter string to search in Trie : ";
            string str;
            cin>>str;
            if(search(root,str))
            {
                cout<<str<<" is present in the Trie..!!"<<endl;
            }
            else
            {
                cout<<str<<" is not present in the Trie..!!"<<endl;
            }
        }
        else if(s=="prefix")
        {
            cout<<"Enter string to get suggestion :";
            string str;
            cin>>str;
            prefixSearch(root,str);
        }
        else if(s=="delete")
        {
            cout<<"Enter string to delete: ";
            string str;
            cin>>str;
            Delete(root,str);
        }
        else
        {
            cout<<"Please enter valid query....!!"<<endl;
        }
    }



}