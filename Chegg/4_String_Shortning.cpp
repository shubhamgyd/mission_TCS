#include<bits/stdc++.h>
using namespace std;


int main()
{
    cout<<"Type the message to be shortened"<<endl;

    // we need to take the input as a sentence so 
    // for that simple string can't do that,
    // we need to use getline ( getline() is an in-built function defined in the <string. h> 
    // header file that allows accepting and reading single and multiple line strings from the 
    // input stream.)
    string message;
    getline(cin,message);
    // converting  string to lowercase
    transform(message.begin(),message.end(),message.begin(),::tolower);

    // initial length of the input string
    int initialLength=message.length();
    // working on Algorithm: 1 
    stringstream ss(message);
    string word;

    int vowelsRemoved=0;
    int repetRemoved=0;
    string algo1Ans="";

    // it will traverse the string(message string) without considering the space
    while(ss>>word)
    {
        // travese the particular word in message to count the vowels and repeated characters
       int i=0;
       int len=word.length();
       string temp="";
       while(i<len)
       {
           // if current index is 0
           // then we have two conditions
           // 1. Either vowel is present at 0th index
           // 2. or non-vowel is present at 0th index
           if(i==0)
           {
               
               int j=i;
               while(j<len && word[i]==word[j])
               {
                   j++;
               }

               // if it is vowel , then increment the vowels count
               if(word[i]=='a' || word[i]=='e' || word[i]=='i' || word[i]=='o' || word[i]=='u')
               {
                   temp.push_back(word[i]);
                   vowelsRemoved+=j-i-1;
               }

               // else if repeated, then increment the repeated count
               else
               {
                   temp.push_back(word[i]);
                   if(i+1<j)
                   {
                       repetRemoved++;
                   }
               }
            

                // set the i to the jth position 
                // so that we will traverse from on wards, instead of i+1
               if(i+1==j)
               {
                   i=j;
               }
               else
               {
                   i=j;
               }
           }
           else
           { 
               // similarly if it is vowel, and this is present between the word mean it is not 
               // not found the starting of word, so increment the vowels count
               if(word[i]=='a' || word[i]=='e' || word[i]=='i' || word[i]=='o' || word[i]=='u')
               {
                   vowelsRemoved++;
                   i++;
               }
               // else if it is repeated character, then increment the repeated count
               else
               {
                   temp.push_back(word[i]);
                   int j=i;
                   while(j<len && word[j]==word[i])
                   {
                       j++;
                   }
                   if(i+1<j)
                   {
                       repetRemoved++;
                   }
                   if(i+1==j)
                   {
                       i=j;
                   }
                   else{
                       i=j;
                   }
               }
           }
       }
       // add the space between two words
       algo1Ans+=temp+" ";
    }
    // we have added one more extra space at the end, remove it
    algo1Ans.pop_back();



    //  Working on algorithm: 2

    // remove the space between two words in message
    message.erase(remove(message.begin(), message.end(), ' '),message.end());

    // it will keep track on visited characters in message
    map<char,int>visited;
    int uniqueCharacters=0;
    string algo2Ans="";
    for(int i=0;i<message.length();i++)
    {
        // if we have not visited this character earlier
       if(visited.find(message[i])==visited.end())
       {
           int freq=1;     // because of current character

           // inner for loop will count the frequency of current character
           for(int j=i+1;j<message.length();j++)
           {
               if(message[i]==message[j])
               {
                   freq++;
               }
           }
           // mark the current character as visited
           visited[message[i]]++;

           // increment the count of uniqueCharacters
           uniqueCharacters++;


           // append in new string 
           // convert the integer to string
           string strNum=to_string(freq);
          algo2Ans+=strNum;
          algo2Ans.push_back(message[i]);
       }
    }
    // length of message after passing the given condision

    // final outout
    int finalLength=algo2Ans.length();

    cout<<"Algorithm 1"<<endl;
    cout<<"Vowels removed: "<<vowelsRemoved<<endl;
    cout<<"Repeats removed: "<<repetRemoved<<endl;
    cout<<"Algorithm 1 message: "<<algo1Ans<<endl;
    cout<<"Algorithm 1 characters saved: "<<vowelsRemoved+repetRemoved<<endl;



    cout<<endl;
    cout<<"Algorithm 2"<<endl;
    cout<<"Unique characters found: "<<uniqueCharacters<<endl;
    cout<<"Algorithm 2 message: "<<algo2Ans<<endl;
    cout<<"Algorithm 2 characters saved: "<<initialLength-finalLength<<endl;
    return 0;
}