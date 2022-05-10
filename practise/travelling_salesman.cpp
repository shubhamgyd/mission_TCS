#include<bits/stdc++.h>
using namespace std;


int final_res=INT_MAX;
int final_path[1001];
bool visited[1001];

// Function to find the minimum edge cost 
// having an end at the vertex i
int firstMin(vector<vector<int>>&res,int i,int n)
{
    int mn=INT_MAX;
    for(int k=0;k<n;k++)
    {
        if(res[i][k]<mn and i!=k)
        {
            mn=res[i][k];
        }
    }
    return mn;
}


// function to find the second minimum edge cost 
// having an end at the vertex i 
int secondMin(vector<vector<int>>&res,int i,int n)
{
    int first=INT_MAX;
    int second=INT_MAX;
    for(int k=0;k<n;k++)
    {
        if(i==k) continue;
        if(res[i][k]<=first)
        {
            second=first;
            first=res[i][k];
        }
        else if(res[i][k]<=second and res[i][k]!=first)
        {
            second=res[i][k];
        }
    }
    return second;
}


void TSPRec(vector<vector<int>>&res,int curr_bound,int curr_weight,int level,int curr_path[],int n)
{
    //base case it means we have reached to the level n
    // means we have visited all nodes once
    if(level==n)
    {
        // now check is there is an edge between last visited node to the root node
        if(res[curr_path[level-1]][curr_path[0]]!=0)
        {
            int curr_res=curr_weight+res[curr_path[level-1]][curr_path[0]];
            // Update final result and final path if 
            // current result is better. 
            if (curr_res < final_res) 
            { 
                for(int i=0;i<n;i++)
                {
                    final_path[i]=curr_path[i];
                }
                final_path[n]=curr_path[0];
                final_res = curr_res; 
            } 
        }
        return;
    }

    // for any other level iterate for all vertices to 
    // build the search space tree recursively 

    for(int i=0;i<n;i++)
    {
        // Consider next vertex if it is not same (diagonal 
        // entry in adjacency matrix and not visited 
        // already) 
        if(res[curr_path[level-1]][i]!=0 and !visited[i])
        {
            int temp = curr_bound; 
            curr_weight += res[curr_path[level-1]][i]; 

            // different computation of curr_bound for 
            // level 2 from the other levels

            if(level==1)
            {
                curr_bound-=((firstMin(res,curr_path[level-1],n)+firstMin(res,i,n))/2);
            }
            else
            {
                curr_bound-=((secondMin(res,curr_path[level-1],n)+firstMin(res,i,n))/2);
            }

            // curr_bound + curr_weight is the actual lower bound 
            // for the node that we have arrived on 
            // If current lower bound < final_res, we need to explore 
            // the node further 

            if(curr_bound+curr_weight<final_res)
            {
                curr_path[level]=i;
                visited[i]=true;



                // call TSPRec for the next level 
                TSPRec(res,curr_bound,curr_weight,level+1,curr_path,n);
            }


            // Else we have to prune the node by resetting 
            // all changes to curr_weight and curr_bound 
            curr_weight -= res[curr_path[level-1]][i]; 
            curr_bound = temp; 
  
            // Also reset the visited array 
            memset(visited, false, sizeof(visited)); 
            for (int j=0; j<=level-1; j++) 
                visited[curr_path[j]] = true;
        }
    }
}


void TSP(vector<vector<int>>&res,int n,int m)
{

    int curr_path[n+1];
    

    // now calculate the initial lower bound for the root node using the formula
    // 1/2*(sum of first min + second min)
    // also initialise the curr_path and visited array
    
    int curr_bound=0;
    memset(curr_path,-1,sizeof(curr_path));
    memset(visited,0,sizeof(visited));



    // Compute initial bound 
    for(int i=0;i<n;i++)
    {
        curr_bound+=firstMin(res,i,n)+secondMin(res,i,n);
    }


    // rounding off the curr_bound
    if(curr_bound&1)
    {
        curr_bound=(curr_bound/2)+1;
    }
    else
    {
        curr_bound/=2;
    }


    // We start at vertex 1 so the first vertex 
    // in curr_path[] is 0 
    visited[0] = true; 
    curr_path[0] = 0; 

    // Call to TSPRec for curr_weight equal to 
    // 0 and level 1 
    TSPRec(res, curr_bound, 0, 1, curr_path,n); 

    cout<<"Minimum Weight: "<<final_res<<endl;
    cout<<"Path: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<final_path[i]<<" ";
    }
    cout<<final_path[0]<<endl;


}


int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>res(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>res[i][j];
        }
    }
    TSP(res,n,m);
    return 0;
}

// Time Complexity:O(2^n*n^3)