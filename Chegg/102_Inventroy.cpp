#include<bits/stdc++.h>
using namespace std;

// utility function which return the resulting array
vector<int> solve(string str,int startIndices[],int endIndices[],int n)
{
    // length of items
    int size=str.length();
    // precalculate the sum of stars from the items
    int preCalStars[size+1];
    memset(preCalStars,0,sizeof(preCalStars));
    // precalculate the indices of pipes from the items
    int leftPipe[size+1];
    memset(leftPipe,-1,sizeof(leftPipe));
    // Iterate the items
    for(int i=1;i<=size;i++)
    {
        // if closed 
        if(str[i-1]=='|')
        {
            // update the leftpipe index
            // and take the previous sum of stars
            preCalStars[i]=preCalStars[i-1];
            leftPipe[i]=i;
        }
        else
        {
            // else increment the sum of stars
            // and take the previous index of pipe
            preCalStars[i]=preCalStars[i-1]+1;
            leftPipe[i]=leftPipe[i-1];
        }
    }
    // make the array of size items 
    // and initialize it with 0
    vector<int>ans(size,0);
    // if there is no close apartment
    // then return the empty array with size of items
    if(leftPipe[size-1]==-1)
    {
        return ans;
    }
    // pre calculate the rightmost pipe location
    int rightPipe[size+1];
    // Initialize it with the rightmost position
    for(int i=0;i<=size;i++)
    {
        rightPipe[i]=size+1;
    }
    // Iterate items from backwards
    for(int i=size-1;i>=0;i--)
    {
        // if pipe/close apartment
        if(str[i]=='|')
        {
            // update right most close apartent index
            rightPipe[i+1]=i+1;
        }
        else
        {
            // else update according to the index
            rightPipe[i+1]=i<size-1?rightPipe[i+2]:size+1;
        }
    }
    // to keep track of ans
    vector<int>res;
    for(int i=0;i<n;i++)
    {
        // start Index
        int startIndex=startIndices[i];
        // end Index
        int endIndex=endIndices[i];
        // leftmost pipe location
        int lPipe=rightPipe[startIndex];
        // right most pipe location
        int rPipe=leftPipe[endIndex];
        // if valid
        if(lPipe<rPipe)
        {
            // then push the total stars between two pipe
            res.push_back(preCalStars[rPipe]-preCalStars[lPipe]);
        }
        else
        {
            // else push zero
            res.push_back(0);
        }
    }
    // return resulting array
    return res;
}

int main()
{
    // input items
    string str;
    cin>>str;
    // size of indices
    int n;
    cin>>n;
    int startIndices[n],endIndices[n];
    // input of start indices
    for(int i=0;i<n;i++)
    {
        cin>>startIndices[i];
    }
    // input of end indices
    for(int i=0;i<n;i++)
    {
        cin>>endIndices[i];
    }
    vector<int>ans;
    ans=solve(str,startIndices,endIndices,n);
    // print ans
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    return 0;

}