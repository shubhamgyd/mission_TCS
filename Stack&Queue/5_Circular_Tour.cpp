#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


 // } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
    // bool dfs(int petrol,int num,bool visited[],vector<pair<int,int>>graph[])
    // {
    //     if(visited[num] && petrol >=0 ) return true;
    //     if(visited[num]) return false;
    //     visited[num]=true;
    //     for(auto ele:graph[num])
    //     {
    //         int v=ele.first;
    //         int w=ele.second;
    //         if(petrol>=w)
    //         {
    //             petrol-=w;
    //             petrol+=v;
    //         }
    //         else
    //         {
    //             return false;
    //         }
    //         dfs(petrol,v,visited,graph);
    //     }
    //     return true;
    // }
    
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       //Your code here
    //   vector<pair<int,int>>graph[n];
    //   for(int i=0;i<n;i++)
    //   {
    //       if(i!=n-1)
    //       {
    //           int u=p[i].petrol;
    //           int v=p[i+1].petrol;
    //           int w=p[i].distance;
    //           graph[u].push_back({v,w});
    //       }
    //       else
    //       {
    //           int u=p[i].petrol;
    //           int v=p[0].petrol;
    //           int w=p[i].distance;
    //           graph[u].push_back({v,w});
    //       }
    //   }
    //   bool visited[n];
    //   for(int i=0;i<n;i++)
    //   {
    //       visited[i]=false;
    //   }
    //   for(int i=0;i<n;i++)
    //   {
    //       int petrol=p[i].petrol;
    //       //visited[p[i]->petrol]=true;
    //       if(dfs(petrol,p[i].petrol,visited,graph))
    //       {
    //           return i;
    //       }
    //   }
    //   return -1;
    int start=0,difict=0;
    int capacity=0;
    for(int i=0;i<n;i++)
    {
        capacity+=p[i].petrol-p[i].distance;
        // Means current points se hmm aage ke petrol pump tk ja sakte hai ki nahi...if positive then we can
        // If not then follow the following process



        // Means uss point se pichla loss gas + last point ke aage ka profit ..inn dono ka summation 
        // positive aata hai to starting pointer return kro ..jo store kiya hai wo ..if not
        // then -1 return kro
        if(capacity<0)         // Means here we are in loss , and we are storing this loss for 
        {                      // calculating final result
            start=i+1;
            difict+=capacity;      // How much we have loss 
            capacity=0;
        }
    }
    return (difict+capacity)>=0?start:-1;
    }
};



// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}
  // } Driver Code Ends