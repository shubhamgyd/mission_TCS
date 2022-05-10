#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

int main()
{
    // String input
    cout<<"\nEnter String: ";
    string str;
    cin>>str;


    // Lnegth of string
    int length=str.length();

    // suffix array of length of string, which counts the occurance of T in from back side
    int countT[length];

    // initialze the array as 0 
    memset(countT,0,sizeof(countT));

    // if the last char of string is T then set the last index value of suffix array 1
    if(str[length-1]=='T')
    {
        countT[length-1]=1;
    }

    // Iterate from second last index to 0th index
    for(int i=length-2;i>=0;i--)
    {
        // if T occurs, then increment the counter of T in suffix array by 1 + add the occurances of T after the current index
        if(str[i]=='T')
        {
            countT[i]=countT[i+1]+1;
        }
        // else count of T is same as (i+1)th index
        else
        {
            countT[i]=countT[i+1];
        }
    }

    // vector container which store the indeces,
    // in which count of A,G and T are same
    vector<pair<int,int>>ans;

    // initialize count of A=0
    int countA=0;
    for(int i=0;i<length;i++)
    {
        // if A occurs
        if(str[i]=='A')
        {
            // Increement the counter of A
            countA++;

            // Set the count of G as 0
            // we need to count G after ith position
            int countG=0;

            // Iterate from (i+1)th postion till end of string
            // and check the occurance of A,G and T are same or not
            for(int j=i+1;j<length;j++)
            {
                // if G occurs
                if(str[j]=='G')
                {
                    // Increment the counter of G by 1
                    countG++;

                    // Now check countA==countG and countG==countT or not
                    // as we have already pre computed count of T in suffix array
                    // so now just chek count of T at (j+1)th position is same with count of A and G or not
                    // if condistion satisfied then push the indices into the ans array
                    if(countA==countG and countG==countT[j+1])
                    {
                        // push the indices into the ans array
                        // as no of A's from 0 to i
                        // no of G's from i+1 to j
                        // and no of T's from j+1 to length-1
                        ans.push_back({i+1,j});
                    }
                }
            }
        }
    }

    // if there are pairs of indices
    if(!ans.empty())
    {
        cout<<"\nPairs of indeices where count of A's, G's and T's are equal: "<<endl;

        // printing the indices where condition satisfied
        for(auto it:ans)
        {
            cout<<it.first<<" "<<it.second<<endl;
        }
        cout<<endl;
    }
    else
    {
        cout<<"No valid pairs found!!!!"<<endl;
    }
    return 0;
}
// Time Complexity:O(|str|*|str|)
// where |str| is the length of string


// Space Complexity:O(|str|)
// where |str| is the length of string