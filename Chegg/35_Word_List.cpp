#include <iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;



class WordPairList
{
private:
    // vector of pairs to stroe the word pairs
    vector<pair<string,string>> allPairs;
public :
    WordPairList(string words[],int n)
    {
        // Iterate to store all pairs of words into the allPairs vectors
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                // push the pair into result
                allPairs.push_back({words[i],words[j]});
            }
        }
        
    }
    int numMatches();                 // Funtion which return the number of matching pairs
    void display();                  // Function which displays the pais of words
}; 


// Utility function which displays the pair of words
void WordPairList::display()
{
    cout<<"WordPair List: "<<endl;

    // size of allPairs
    int n=allPairs.size();

    // Printing the pairs
    for(int i=0;i<n;i++)
    {
        //            first string                        second string
        cout<<"(\""<<allPairs[i].first<<"\""<<", "<<"\""<<allPairs[i].second<<"\")"<<", ";
    }
}



// Utility function which count the same pair of words and return the count
int WordPairList::numMatches()
{
    // counter of matchedPair
    int matchedPair=0;

    // size of allPairs
    int n=allPairs.size();
    for(int i=0;i<n;i++)
    { 
        string first=allPairs[i].first;            // first string in pair
        string second=allPairs[i].second;         // second string in pair

        // if both string are matched
        if(first==second)
        {
            matchedPair+=1;                     // increment the counter of matchedPair
        }
    }

    // return the count
    return matchedPair;
}

int main()
{
    // Example :1 
    string wordNums[3]={"one","two","three"};
    WordPairList exampleOne= WordPairList(wordNums,3);
    exampleOne.display();            // diaplay pairs
    cout<<endl;
    cout<<exampleOne.numMatches()<<endl;         // diaplay matched count


    cout<<"\n";
    // Example :2
    string phrase[4]={"the","more","the","merrier"};
    WordPairList exampleTwo=WordPairList(phrase,4);
    exampleTwo.display();           // diaplay pairs
    cout<<"\n";
    cout<<exampleTwo.numMatches()<<endl;           // diaplay matched count


    cout<<"\n";
    // Example :3
    string moreWords[5]={"the","red","fox","the","red"};
    WordPairList exampleThree=WordPairList(moreWords,5);
    exampleThree.display();       // display pairs
    cout<<"\n";
    cout<<exampleThree.numMatches()<<endl;         // diaplay matched count
    return 0;
}