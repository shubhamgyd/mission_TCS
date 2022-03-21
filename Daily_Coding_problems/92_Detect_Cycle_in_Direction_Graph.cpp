/*
A rule looks like this:

A NE B

This means this means point A is located northeast of point B.

A SW C

means that point A is southwest of C.

Given a list of rules, check if the sum of the rules validate. For example:

A N B
B NE C
C N A
does not validate, since A cannot be both north and south of C.

A NW B
A N B
is considered valid.

*/

#include<bits/stdc++.h>
using namespace std;


bool dfs(int src,vector<int>&visited,vector<int>&order,set<int>adj[])
    {
        visited[src]=1;
        order[src]=1;
        for(auto it:adj[src])
        {
            if(!visited[it])
            {
                bool t=dfs(it,visited,order,adj);
                if(t==true)
                {
                    return t;
                }
            }
            else if(order[it])
            {
                return true;
            }
        }
        order[src]=0;
        return false;
    }



int main()
{
    map<char,int>mp;
    mp['N']=0;
    mp['S']=1;
    mp['W']=2;
    mp['E']=3;
    map<char,int>index;
    int j=0;
    for(char i='A';i<='Z';i++)
    {
        index[i]=j;
        j++;
    }
    int n;
    cin>>n;
    set<int>north_south[26];
    // map<char,set<char>>north_south;
    // map<char,set<char>>east_west;
    set<int>east_west[26];
    for(int i=0;i<n;i++)
    {
        char dest,source;
        string direction;
        cin>>dest>>direction>>source;
        int src=source-'A';
        int dst=dest-'A';
        // cout<<"src: "<<src<<" dst: "<<dst<<endl;
        if(direction=="N")
        {
            // north_south[source].insert(dest);
            
            north_south[src].insert(dst);
        }
        else if(direction=="S")
        {
            // north_south[dest].push_back(source);
            north_south[dst].insert(src);

        }

        else if(direction=="W")
        {
            // east_west[source].push_back(dest);
            east_west[src].insert(dst);
        }
        else if(direction=="E")
        {
            // east_west[dest].push_back(source);
            east_west[dst].insert(src);
        }

        else if(direction=="NW")
        {
            // north_south[source].push_back()
            north_south[src].insert(dst);
            east_west[src].insert(dst);
        }
        else if(direction=="NE")
        {
            north_south[src].insert(dst);
            east_west[dst].insert(src);
        }
        else if(direction=="SE")
        {
            north_south[dst].insert(src);
            east_west[dst].insert(src);
        }
        else if(direction=="SW")
        {
            north_south[dst].insert(src);
            east_west[src].insert(dst);
        }
    }
    cout<<"North-South Graph"<<endl;
    for(int i=0;i<26;i++)
    {
        if(north_south[i].size()>0)
        {
            cout<<i<<"->";
            for(auto it:north_south[i])
            {
                cout<<it<<" ";
            }
            cout<<endl;
        }
    }
    cout<<"East-West Graph"<<endl;
    for(int i=0;i<26;i++)
    {
        if(east_west[i].size()>0)
        {
            cout<<i<<"->";
            for(auto it:east_west[i])
            {
                cout<<it<<" ";
            }
            cout<<endl;
        }
    }


    // now detect cycle either in north-south graph or wast-west graph
    //  if we detect a cycle in any graph then this is invalid expression 
    vector<int>visited(26,0);
	vector<int>order(26,0);
    for(int i=0;i<26;i++)
    {
        if(north_south[i].size()>0 && !visited[i])
        {
	   	    bool c=dfs(i,visited,order,north_south);
	   	    if(c==true)
	   	    {
	   	        cout<<"Invalid expression"<<endl;
                return 0;
	   	    }
        }
    }
    visited.resize(26,0);
    order.resize(26,0);
    for(int i=0;i<26;i++)
    {
        if(east_west[i].size()>0 && !visited[i])
        {
	   	    bool c=dfs(i,visited,order,east_west);
	   	    if(c==true)
	   	    {
	   	        cout<<"Invalid expression"<<endl;
                return 0;
	   	    }
        }
    }
    cout<<"Valid Expression: "<<endl;
    return 0;
}
// Time Complexity:O(26+Edges)
// Space Complexity:O(26)