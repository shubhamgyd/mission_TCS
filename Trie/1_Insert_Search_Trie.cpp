// // // In this problem we are going to insert the new keys in the trie daya structure and also searching them
// // #include<bits/stdc++.h>
// // using namespace std;

// // const int ALPHA_SIZE=26; // Maximum number of charaters 

// // struct TrieNode
// // {
// //     struct TrieNode *children[ALPHA_SIZE]; //Array of 26 characters for each of letter
// //     bool isEndOfWord;    // Checking if last letter is leaf nod or not.
// //     int nodecount; //to count the nodes in the Trie
// // };


// // struct TrieNode *getNode() // Getting the array of 26 nodes
// // {
// //     struct TrieNode *curr= new TrieNode;
// //     curr->isEndOfWord=false;
    
// //     for(int i=0;i<ALPHA_SIZE;i++)
// //     {
// //         curr->children[i]=NULL; // Initialises all the values as a NULL
// //     }
// //     return curr;
// // }


// // // Fucntion to insert words in the Trie
// // void Insert(struct TrieNode *root,string key)
// // {
// //     struct TrieNode *pointer=root;
// //     for(int i=0;i<key.length();i++)
// //     {
// //         int index=key[i]-'a';        // getting the index of the current letter
// //         if(pointer->children[index]==NULL)   // If the current letter is not present in the given array if dictionary , then at that node
// //                                              // create a new node 
// //         {
// //             pointer->children[index]=getNode();
// //         }
// //         pointer=pointer->children[index];     // If the given letter is alreay present then pointer moves towords its children 
// //     }
// //     pointer->isEndOfWord=true;         // After Inserting the last word mark it as the endofword 
// // }



// // // Function to search the words from the key
// // bool Search(struct TrieNode *root, string key)
// // {
// //     struct TrieNode *pointer=root;   // initially Pointer to the root 
// //     for(int i=0;i<key.length();i++)
// //     {
// //         int index=key[i]-'a';   // Checking the given letter is present in the array of string or not
// //         if(pointer->children[index]==NULL)  // If the given letter is not present in the root array , return false
// //         {
// //             return false;
// //         }
// //         pointer=pointer->children[index];  // If the current letter is present then , move pointer to the next node 
// //     }
// //     if(pointer->isEndOfWord==true) // Check the last node is marked with endofword or not , if marked then return true
// //     {
// //         return true;
// //     }
// //     return false;  // Otherwise return false;
// // }


// // // Returns true if root has no children, else false
// // bool isEmpty(TrieNode* root)
// // {
// //     for (int i = 0; i < ALPHA_SIZE; i++)
// //         if (root->children[i])
// //             return false;
// //     return true;
// // }


// // TrieNode* Delete(struct TrieNode *root,string key,int depth=0)
// // {
// //     if(!root)
// //     {
// //         return NULL;
// //     }
// //     if(depth==key.size())
// //     {
// //         if(root->isEndOfWord)
// //         {
// //             root->isEndOfWord=false;
// //         }
// //         if(isEmpty(root))
// //         {
// //             delete(root);
// //             root=NULL;
// //         }
// //         return root;
// //     }

// //     int index=key[depth]-'a';
// //     root->children[index]=Delete(root->children[index],key,depth+1);
// //     if(isEmpty(root) && root->isEndOfWord==false)
// //     {
// //         delete(root);
// //         root=NULL;
// //     }
// //     return root;
// // }


// // int main()
// // {
// //     struct TrieNode *root=getNode();
// //     cout<<"Enter number of  words , you want to insert in Trie: ";
// //     int number;cin>>number;
// //     for(int i=0;i<number;i++)
// //     {
// //         string str;
// //         cin>>str;
// //         Insert(root,str);
// //     }

// //     cout<<"Enter word to search: ";
// //     string ss;cin>>ss;
// //     bool res=Search(root,ss);
// //     if(res)
// //     {
// //         cout<<"Given string is present "<<endl;
// //     }
// //     else
// //     {
// //         cout<<"given string is not present"<<endl;
// //     }


// //     cout<<"Enter string to delete: ";
// //     string st;
// //     cin>>st;
// //     Delete(root,st);

// //     cout<<"Enter word to search: ";
// //     string st1;cin>>st1;
// //     bool rest=Search(root,st1);
// //     if(rest)
// //     {
// //         cout<<"Given string is present "<<endl;
// //     }
// //     else
// //     {
// //         cout<<"given string is not present"<<endl;
// //     }
// //     return 0;
// // }





















// // Anothe approach 

// #include<bits/stdc++.h>
// using namespace std;

// struct Trienode
// {
//     char data;
//     int wc;  //wc:word_count
//     Trienode *child[26];
// };
// Trienode nodepool[100000];  //Pool of 100K Trienodes
// Trienode *root;    //Root of Trie
// int poolcount;  //Always points to next free Trienode

// void init() //Initializer function
// {
//     poolcount = 0;
//     root = &nodepool[poolcount++];
//     root->data = '/';
//     for(register int i=0;i<26;++i)
//         root->child[i] = NULL;
// }

// Trienode *getNode(char c)
// {
//     Trienode *newnode = &nodepool[poolcount++];
//     newnode->data = c;
//     for(register int i=0;i<26;++i)
//         newnode->child[i] = NULL;
//     newnode->wc=0;
//     return newnode;
// }

// void insert(char *s)
// {
//     Trienode *curr = root;
//     int index;
//     for(int i=0; s[i]!='\0'; ++i)
//     {
//         index = s[i]-'a';
//         if(curr->child[index]==NULL)
//             curr->child[index] = getNode(s[i]);
//         curr->child[index]->wc += 1;
//         curr = curr->child[index];
//     }
// }

// bool search(char *s)
// {
//     Trienode *curr = root;
//     int index;
//     for(int i=0; s[i]!='\0'; ++i)
//     {
//         index = s[i]-'a';
//         if(curr->child[index]==NULL || curr->child[index]->wc == 0)
//             return false;
//         curr = curr->child[index];
//     }
//     return true;
// }

// bool Triedelete(char *s)
// {
//     if(search(s))
//     {
//         Trienode *curr = root;
//         int index;
//         for(int i=0; s[i]!='\0'; ++i)
//         {
//             index = s[i]-'a';
//             curr->child[index]->wc -=1;
//             curr = curr->child[index];
//         }
//     }
// }
// int countPrefix(string s)
// {
//     Trienode *curr = root;
//     int index;
//     for(int i=0; s[i]!='\0'; ++i)
//     {
//         index = s[i]-'a';
//         if(curr->child[index]==NULL || curr->child[index]->wc == 0)
//             return 0;   //No string with given prefix is present
//         curr = curr->child[index];
//     }
//     return curr->wc;
// }

// string countPrefix1(string s)
// {
//     string res="";
//     Trienode *curr = root;
//     int index;
//     for(int i=0; s[i]!='\0'; ++i)
//     {
//         index = s[i]-'a';
//         if(curr->child[index]==NULL || curr->child[index]->wc == 0)
//             //res.push_back(s[i]);
//             return res+=s[i];   //No string with given prefix is present
//         //res.push_back(curr->child[index]);
//         else if(curr->child[index]->wc==1)
//         {
//             res.push_back(s[i]);
//             break;
//         }
//         res.push_back(s[i]);
//         curr = curr->child[index];
//     }

//     return res;
// }


// bool wordBreak(string s)
// {
//     int size=sizeof(s);
//     if(size==0) return true;

//     for(int i=1;i<=size;i++)
//     {
//         //char arr;
//         //arr=s.substr(0,i);
//         if(search(&s.substr(0,i)[0])&&wordBreak(s.substr(i,size-i)))
//         {
//             return true;
//         }
//     }
//     return false;
// }

// int main()
// {
//     init();
//     char a1[20] ={"dog"};insert(a1);
//     char a[20] = {"monkey"};insert(a);
//     char b[20] = {"bucket"};insert(b);
//     char c[20] = {"bulk"};insert(c);
//     char d[20] = {"bully"};insert(d);
//     char e[20] = {"bullyw"};insert(e);
//     char f[20] = {"bullyww"};insert(f);
//     char g[20]={"bullywwzaq"}; insert(g);
//     char h[20]={"nilesh"}; insert(h);
    

//     char ser[20];
//     cout<<"Enter string to search: ";
//     cin>>ser;
//     if(search(ser))
//     {
//         cout<<"Given string is present"<<endl;
//     }
//     else
//     {
//         cout<<"Given string is not present"<<endl;
//     }

//     printf("No of strings with given prefix = %d\n",countPrefix("monk"));
//     printf("No of strings with given prefix = %d\n",countPrefix("ar"));
//     printf("No of strings with given prefix = %d\n",countPrefix("arm"));
//     printf("No of strings with given prefix = %d\n",countPrefix("army"));
//     printf("No of strings with given prefix = %d\n",countPrefix("armi"));
//     printf("No of strings with given prefix = %d\n",countPrefix("ary"));

//     char del[20];
//     cout<<"Enter string to delete:";
//     cin>>del;
//     Triedelete(del);
//     Triedelete(d);
//     cout<<"Enteres strings deleted"<<endl;
//     printf("No of strings with given prefix = %d\n",countPrefix("a"));
//     printf("No of strings with given prefix = %d\n",countPrefix("ar"));
//     printf("No of strings with given prefix = %d\n",countPrefix("arm"));
//     printf("No of strings with given prefix = %d\n",countPrefix("army"));
//     printf("No of strings with given prefix = %d\n",countPrefix("armi"));
//     printf("No of strings with given prefix = %d\n",countPrefix("ary"));


//     string s0=countPrefix1(a1);
//     cout<<"Prefix of the given word is: "<<s0<<endl;

//     string ss=countPrefix1(a);
//     cout<<"Prefix of the given word is: "<<ss<<endl;

//     string ss1=countPrefix1(b);
//     cout<<"Prefix of the given word is: "<<ss1<<endl;

//     string ss2=countPrefix1(c);
//     cout<<"Prefix of the given word is: "<<ss2<<endl;

//     string ss3=countPrefix1(d);
//     cout<<"Prefix of the given word is: "<<ss3<<endl;

//     string ss4=countPrefix1(e);
//     cout<<"Prefix of the given word is: "<<ss4<<endl;

//     string ss5=countPrefix1(f);
//     cout<<"Prefix of the given word is: "<<ss5<<endl;

//     string ss6=countPrefix1(g);
//     cout<<"Prefix of the given word is: "<<ss6<<endl;



//     string word="dogmonkey";
//     wordBreak(word)?cout<<"YES\n":cout<<"NO\n";
//     // if(wordBreak(word))
//     // {
//     //     cout<<"We can make this words form the given dictionary"<<endl;
//     // }
//     // else
//     // {
//     //     cout<<"We can't make this word from the given words of dictionary"<<endl;
//     // }

//     return 0;
// }





#include <bits/stdc++.h>
using namespace std;

struct Trie
{
    char data;
    int wc;
    Trie* child[26];   // to store the childs
};

Trie *root;
Trie nodepool[1000000];
int poolcount;        //always point ot next free trie node

void init()
{
    poolcount=0;
    root=&nodepool[poolcount++];
    root->data='/';
    for(register int i=0;i<26;i++)
    {
        root->child[i]=NULL;
    }

}


Trie *getNode(char c)
{
    Trie *curr=&nodepool[poolcount++];
    curr->data=c;
    for(register int i=0;i<26;i++)
    {
        curr->child[i]=NULL;
    }
    curr->wc=0;
    return curr;
}

// void insert(char *s)
// {
//     Trie *curr=root;
//     for(int i=0;s[i]!='\0';i++)
//     {
//         int index=s[i]-'a';
//         if(curr->child[index]==NULL)
//         {
//             curr->child[index]=getNode(s[i]);
//         }
//         curr->child[index]->wc+=1;
//         curr=curr->child[index];
//     }
// }

void insert(char s[])
{
    //cout<<"Hello"<<endl;
    Trie *curr = root;
    int index;
    for(int i=0; s[i]!='\0'; ++i)
    {
        index = s[i]-'a';
        if(curr->child[index]==NULL)
            curr->child[index] = getNode(s[i]);
        curr->child[index]->wc += 1;
        curr = curr->child[index];
    }
    //cout<<"Hello"<<endl;
}

bool search(char s[])
{
    Trie *curr=root;
    for(int i=0;s[i]!='\0';i++)
    {
        int index=s[i]-'a';
        if(curr->child[index]==NULL || curr->child[index]->wc==0)
        {
            return false;
        }
        curr=curr->child[index];
    }
    return true;
}


void Delete(char s[])
{
    if(search(s))
    {
        Trie *curr=root;
        for(int i=0;s[i]!='\0';i++)
        {
            int index=s[i]-'a';
            curr->child[index]->wc-=1;
            curr=curr->child[index];
        }
    }
}


int countPrefix(char *s)
{
    Trie *curr=root;
    for(int i=0;s[i]!='\0' ;i++)
    {
        int index=s[i]-'a';
        if(curr->child[index]==NULL || curr->child[index]->wc==0)
        {
            return 0;
        }
        curr=curr->child[index];
    }
    return curr->wc;
}

int main()
{
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    init();
    int n;
    cin>>n;
    while(n--)
    {
        char s[20];
        cout<<"Enter string to add: ";
        cin>>s;  
        insert(s);
    }
    // char a1[20]="Nilesh";insert(a1);
    // char a2[20]="Nil";insert(a2);
    int q;
    cin>>q;
    while(q--)
    {
        char c[20];
        cout<<"Enter string to search: ";
        cin>>c;
        if(search(c))
        {
            cout<<"Given string is present..!!"<<endl;
        }
        else
        {
            cout<<"Given string is not present .."<<endl;
        }
    }
    // char c1[20]="Nilesh";
    // if(search(c1))
    // {
    //     cout<<"Given string is present in the trie..!!!"<<endl;
    // }
    // else{
    //     cout<<"Gicen string is not present in the trie..!!!"<<endl;
    // }

}


