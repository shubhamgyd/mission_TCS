/*
Given a grid of numbers, find maximum length Snake sequence and print it. 
If multiple snake sequences exists with the maximum length, print any one of them.
A snake sequence is made up of adjacent numbers in the grid such that for each number, 
the number on the right or the number below it is +1 or -1 its value. For example, 
if you are at location (x, y) in the grid, you can either move right i.e. (x, y+1) 
if that number is ± 1 or move down i.e. (x+1, y) if that number is ± 1.
For example,
9, 6, 5, 2 
8, 7, 6, 5 
7, 3, 1, 6 
1, 1, 1, 7
In above grid, the longest snake sequence is: (9, 8, 7, 6, 5, 6, 7)
*/


// DP_maxLenSnakeSeq.cpp
/*
	Author: silent_decoder
	@nilesh1206
	Created: 10 Sep 2021
	Approach: DFS
	Max. Length of Snake Sequence i.e. (abs(a-b)==1)
*/
#include <bits/stdc++.h>
using namespace std;

int mat[10][10] = 
    { 
        {9, 6, 5, 2}, 
        {8, 7, 6, 5}, 
        {7, 3, 1, 6}, 
        {1, 1, 1, 7}, 
    }; 
int vis[10][10];
int n,m;
int dx[] = {0,1};
int dy[] = {1,0};
vector<int> path;

bool isvalid(int x,int y) {
	return (x>=0 && y>=0 && x<n && y<m && vis[x][y]==0);
}

void findMaxLen(int i,int j,int &ans,int val,int d,vector<int> temp) {
	if(i==n-1 && j==m-1) {
		temp.push_back(mat[i][j]);
		if(ans<d) {
			ans = d;
			path = temp;
		}
		return;
	}
	vis[i][j] = 1;
	temp.push_back(mat[i][j]);
	for(int k=0;k<2;k++) {
		int u = i+dx[k];
		int v = j+dy[k];
		if(isvalid(u,v) && abs(val-mat[u][v])==1) {
			findMaxLen(u,v,ans,mat[u][v],d+1,temp);
		}
	}
	temp.pop_back();
	vis[i][j] = 0;
}


int main() {
	n = 4 , m = 4;
	int ans=0;
	memset(vis,0,sizeof vis);
	vector<int> v;
	findMaxLen(0,0,ans,mat[0][0],0,v);
	cout<<ans<<endl;
	cout<<"Path: ";
	for(int x:path)
		cout<<x<<" ";
	cout<<endl;
	return 0;
}