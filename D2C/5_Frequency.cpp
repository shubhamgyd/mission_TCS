// // #include<bits/stdc++.h>
// // using namespace std;

// // int main()
// // {
// //     string str;
// //     cin>>str;
// //     int n=str.length();
// //     map<char,int>mp;
// //     int i;
// //     for(i=0;i<n/2;i++)
// //     {
// //         mp[str[i]]++;
// //     }
// //     int ct=0;
// //     set<char>st;
// //     for(i;i<n;i++)
// //     {
// //         if(mp.find(str[i])!=mp.end())
// //         {
// //             st.insert(str[i]);
// //         }
// //     }
// //     cout<<st.size()<<endl;
// //     return 0;
// // }



// // CPP code for Dynamic Programming based  
// // solution for 0-1 Knapsack problem 
// #include <bits/stdc++.h> 
  
// // A utility function that returns maximum of two integers 
// int max(int a, int b) { return (a > b) ? a : b; } 
  
// // Prints the items which are put in a knapsack of capacity W 
// void printknapSack(int W, int wt[], int val[], int n) 
// { 
//     int i, w; 
//     int K[n + 1][W + 1]; 
  
//     // Build table K[][] in bottom up manner 
//     for (i = 0; i <= n; i++) { 
//         for (w = 0; w <= W; w++) { 
//             if (i == 0 || w == 0) 
//                 K[i][w] = 0; 
//             else if (wt[i - 1] <= w) 
//                 K[i][w] = max(val[i - 1] +  
//                     K[i - 1][w - wt[i - 1]], K[i - 1][w]); 
//             else
//                 K[i][w] = K[i - 1][w]; 
//         } 
//     } 
  
//     // stores the result of Knapsack 
//     int res = K[n][W];     
//     printf("%d", res); 
      
//     w = W; 
//     for (i = n; i > 0 && res > 0; i--) { 
          
//         // either the result comes from the top 
//         // (K[i-1][w]) or from (val[i-1] + K[i-1] 
//         // [w-wt[i-1]]) as in Knapsack table. If 
//         // it comes from the latter one/ it means  
//         // the item is included. 
//         if (res == K[i - 1][w])  
//             continue;         
//         else { 
  
//             // This item is included. 
//             printf("%d ", wt[i - 1]); 
              
//             // Since this weight is included its  
//             // value is deducted 
//             res = res - val[i - 1]; 
//             w = w - wt[i - 1]; 
//         } 
//     } 
// } 
  
// // Driver code 
// int main() 
// { 
//     int val[] = {1,1,1,1,1,1}; 
//     int wt[] = { 1,2,3,4,5,6 }; 
//     int W = 9; 
//     int n = sizeof(val) / sizeof(val[0]); 
      
//     printknapSack(W, wt, val, n); 
      
//     return 0; 
// } 


#include<bits/stdc++.h>
using namespace std;

int main()
{
    char ch='a';
    int y=ch;
    cout<<y<<endl;
}