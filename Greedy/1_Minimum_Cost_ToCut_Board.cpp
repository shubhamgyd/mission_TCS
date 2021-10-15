// In this probelm we are going to find the minimum cost to cut the board

#include<bits/stdc++.h>
using namespace std;


int MinimumCost(int X[],int Y[],int m, int n)
{
    sort(X,X+m,greater<int>());              //  Sorting the vertical (for columns) cost array  in reverse way
    sort(Y,Y+n,greater<int>());              // Sorting the horizantal (for rows) cost array in reverse way  
    int vert=1,horiz=1;                      // Before cutting piece is always one
    int i=0,j=0;
    int res=0;
    while(i<m && j<n)
    {
        if(X[i]>Y[j])
        {
            res+=X[i]*vert;          // Total_cost= total_cost  + edge_cost * pieces;
            horiz++;                 //  increase current horizontal part count by 1
            i++;
        }
        else
        {
            res+=Y[j]*horiz;
            vert++;                   //  increase current vertical part count by 1
            j++;
        }
    }

    int total=0;
    // Loop for horizantal part, if remain
    while(i<m)
    {
        total+=X[i++];
    }
    res+=total*vert;

    total=0;
    // Loop for vertical part , if remain
    while(j<n)
    {
        total+=Y[j++];
    }
    res+=total*horiz;
    return res;

}

int main()
{
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    //fast();
    int m=6,n=4;
    int X[m-1]={2, 1, 3, 1, 4};
    int Y[n-1]={4,1,2};
    cout<<"minimum cost to cut the board is: "<<MinimumCost(X,Y,m-1,n-1)<<endl;
    return 0;
}


