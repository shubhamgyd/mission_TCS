#include<bits/stdc++.h>
using namespace std;



/* A utility function to check if the vertex v can be added at
   index 'pos' in the Hamiltonian Cycle constructed so far (stored
   in 'path[]') */
bool isSafe(int v,vector<vector<int>>&res,int path[],int pos)
{
    // check v is adjaent to previously added vertex
    // basically it is checking ther is an edge between the last added node and v
    if(res[path[pos-1]][v]==0)
    {
        return false;
    }

    // check this vertes has been already included or not
    for(int i=0;i<pos;i++)
    {
        if(path[i]==v) return false;
    }
    return true;
}


/* A recursive utility function to solve hamiltonian cycle problem */
bool hamCycleUtil(vector<vector<int>>&res,int path[],int pos,int n)
{
    // base case: if all nodes are included into the hamiltanion cycle
    if(pos==n)
    {
        // now check if there is a edge from last vertex to the first vertex
        if(res[path[pos-1]][path[0]]==1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }


    // now try for other vertices for the next candidats, we can't add 0 because we have already
    // added it
    for(int i=1;i<n;i++)
    {
         /* Check if this vertex can be added to Hamiltonian Cycle */
        if(isSafe(i,res,path,pos))
        {
            path[pos]=i;

            /* recur to construct rest of the path */
            if(hamCycleUtil(res,path,pos+1,n))
            {
                return true;
            }
            /* If adding vertex v doesn't lead to a solution,
               then remove it */
            path[pos]=-1;
        }
    }

    /* If no vertex can be added to Hamiltonian Cycle constructed so far,
       then return false */
    return false;

}


void printSolution(int path[],int n)
{
    cout<<"Solution exists: Hamiltanion path "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<path[i]<<" ";
    }

    // printing the starting node
    cout<<path[0]<<endl;
    return;
}


// Utility function which prints the hamiltanion cycle if there exist
bool hamCycle(vector<vector<int>>&res,int n,int m)
{
    int path[n];
    for(int i=0;i<n;i++)
    {
        path[i]=-1;
    }
    /* Let us put vertex 0 as the first vertex in the path. If there is
       a Hamiltonian Cycle, then the path can be started from any point
       of the cycle as the graph is undirected */
       path[0]=0;
        
       if(hamCycleUtil(res,path,1,n)==false)
       {
           cout<<"There is no hamilatanion cycel present!!"<<endl;
           return false;
       }

       printSolution(path,n);
       return true;
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
    hamCycle(res,n,m);
    return 0;
}
// DFS + Backtracking 
// Time Complexity:O(n!)
