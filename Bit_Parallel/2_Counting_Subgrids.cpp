// In this algorithm we are going to find the number of subgrids , whose corners are black

#include<bits/stdc++.h>
using namespace std;
#define N 5

// int grid(int color[][N] , int n)
// {
//     int subgrid=0;
//     for(int a=0;a<n;a++)
//     {
//         for(int b=a+1;b<n;b++)
//         {
//             int count=0;
//             for(int i=0;i<n;i++)
//             {
//                 if(color[a][i]==1 && color[b][i]==1)
//                 {
//                     count++;
//                 }
//             }
//             subgrid=count*(count-1)/2;
//         }
//     }
//     return subgrid;
// }

int  main()
{
    int n;
    cin>>n;
    int color[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>color[i][j];
        }
    }
    vector<int>v;
    int subgrid=0;
    for(int a=0;a<n;a++)
    {
        for(int b=a+1;b<n;b++)          // First two loops iterate all the kind of pair of rows i.e (a,b) 
        {
            int count=0;                // Count the number of subgrids int a,b
            for(int i=0;i<n;i++)        // This loop iterater all the columns of row a and row b
            {
                if(color[a][i]==1 && color[b][i]==1)         // If the condition satisfies then, increment the count
                {
                    count++;
                }
                
            }
            subgrid+=count*(count-1)/2;  
            // This is choosing the the square or rectangle formed i.e. nC2 ways . Here 2 because minimum number of coulmns required to 
            // satisfies the given condition i.e to make subgrid 
            // Or we can use bit manupulation
            // like

            // for(int i=0;i<=n/64;i++)
            // {
            //     count+=__builtin_popcount(color[a][i]&color[b][i]);
            // }
            // subgrid+=count*(count-1)/2;
            
            // This algorithm works in O(n^3/N) times .... Optimised algo
        }
    }
    cout<<"Toal number of subgrids: "<<subgrid<<endl;
    return 0;
}

/*
There is an O(n3) time algorithm for solving the problem: go through all O(n2)
pairs of rows, and for each pair(a, b) calculate, in O(n)time, the number of columns
that contain a black square in both rows a and b.
*/