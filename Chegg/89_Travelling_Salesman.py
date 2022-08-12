# #include<bits/stdc++.h>
# using namespace std;
# int dp[101][101];

# class Solution
# {
#     int visited_all;         // total number of cities i.e. mask 1111...n;
# public:
#     void set(int n)
#     {
#         visited_all=(1<<n)-1;
#     }
#     int tsp(vector<vector<int>>&graph,int n,int mask,int pos)
#     {
#         if(mask==visited_all)
#         {
#             return graph[pos][0];
#         }
#         if(dp[mask][pos]!=-1)
#         {
#             return dp[mask][pos];
#         }

#         // now from the current node we trying to visited all the possible nodes and take the min weight
#         // from visited nodes
#         int ans=INT_MAX;                // because we want minimum weight
        
#         // Iterate to all possible cities
#         for(int city=0;city<n;city++)
#         {
#             if((mask&(1<<city))==0)              // means we are visiting those cities , which are not visited
#             {                                   // means 001&(1<<0) == (001&010) == 000 i.e 1st city is not visited
                
#                 int newDist=graph[pos][city]+tsp(graph,n,(mask|(1<<city)),city);
#                 // here if city is not visited , then we are storing the current branch weight in one variable
#                 // and we recursively iterate to the next city by using bitmask
#                 // like mask|(1<<city)== 001|(1<<0) ==(001|010) == 011 
#                 // and again we checking 2nd city is visited or not  and so on...

#                 ans=min(ans,newDist);        //strong the minimum distance of current branch
#             }
#         }
#         return dp[mask][pos]=ans;               // storing the ans and returning it.
#     }
# };

# /*
# Time complexity is O(n^2 * 2 ^ n) as we are filling each value in the dp table and to 
# compute the optimal value for each cell in dp table we are traversing to all 
# possible next cities which are n.
# */

# int main()
# {
#     memset(dp,-1,sizeof(dp));
#     int n,m;
#     cin>>n>>m;
#     vector<vector<int>>graph(n,vector<int>(m,0));
#     for(int i=0;i<n;i++)
#     {
#         for(int j=0;j<m;j++)
#         {
#             cin>>graph[i][j];
#             //graph[j][i]=graph[i][j];
#         }
#     }
#     Solution obj;
#     obj.set(n);
#     cout<<"Minimum distance visited to all cities is: ";
#     cout<<obj.tsp(graph,n,1,0);
#     return 0;

# }



n=4
m=6
charInd={}
charsInalpbahet="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
ind=0
for char in charsInalpbahet:
    charInd[char]=ind
    ind=ind+1
adjList=[0]*n
for i in range(n):
    adjList[i]=[]

# Given Graph
