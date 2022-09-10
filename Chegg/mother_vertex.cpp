#include<bits/stdc++.h>
using namespace std;

int maxIndexDiff(int* arr, int n)
{
    int maxDiff = n-1;
    int i, j;

    while (maxDiff>0)
    {
        j=n-1;
        while(j>=maxDiff)
        {
            i=j-maxDiff;
            if(arr[j]>arr[i])
            { 
                return maxDiff;  
            }
            j=j-1;
        }
        maxDiff=maxDiff-1;
    }
    return -1;  
}


int x[] = {0, 1, 1, -1, 1, 0, -1, -1};
int y[] = {1, 0, 1, 1, -1, -1, 0, -1};

bool isvalid(int i, int j,int m,int n)
{
    if (i < 0 || j < 0 || i >= m || j >= n)
    {
        return false;
    }
    return true;
}
 

bool isadjacent(char prev, char curr)
{
    return ((curr - prev) == 1);
}

int getLenUtil(char** path, int i, int j, int m,int n,char prev,vector<vector<int>>&dp)
{
    if (!isvalid(i, j,m,n) || !isadjacent(prev, path[i][j]))
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int ans = 0;  
    for (int k=0; k<8; k++)
    {
        ans = max(ans, 1 + getLenUtil(path, i + x[k],j + y[k],m,n,path[i][j],dp));
    }
    return dp[i][j] = ans;
}
 

int LongestConsecutivePath(char** path,int m,int n,char ch)
{
    vector<vector<int>>dp(m,vector<int>(n,-1));
    int ans = 0;
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (path[i][j] == ch) {
                for (int k=0; k<8; k++)
                {
                    ans = max(ans, 1 + getLenUtil(path,i + x[k], j + y[k],m,n, ch,dp));
                }
            }
        }
    }
    return ans;
}


struct TreeNode
{
    int data;
    struct TreeNode *left, *right;
};

void printkdistanceNodeDown(TreeNode *root, int k,int &sum)
{

    if (root == NULL || k < 0)  return;
    if (k==0)
    {
        sum+=root->data;
        return;
    }
    printkdistanceNodeDown(root->left, k-1,sum);
    printkdistanceNodeDown(root->right, k-1,sum);
}

int printkdistanceNode(struct TreeNode* root, int target,int k,int &sum)
{

    if (root == NULL) 
    {
        sum=-1;
        return 0;
    }
    if (root->data == target)
    {
        printkdistanceNodeDown(root, k,sum);
        return 0;
    }

    int dl = printkdistanceNode(root->left, target, k,sum);
    if (dl != -1)
    {
        if (dl + 1 == k)
        {
            sum+=root->data;
        }
        else
        {
            printkdistanceNodeDown(root->right, k-dl-2,sum);
        }
        return 1 + dl;
    }
    int dr = printkdistanceNode(root->right, target, k,sum);
    if (dr != -1)
    {
        if (dr + 1 == k)
        {
            sum+=root->data;
        }
        else
        {
            printkdistanceNodeDown(root->left, k-dr-2,sum);
        }
        return 1 + dr;
    }
}

int kDistanceFromNode(struct TreeNode* node,int k,int n)
{
    int sum=-1;
    if(node==NULL) return -1;
    printkdistanceNode(node,n,k,sum);
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // int n;
    // cin>>n;
    // vector<int>nums(n);
    // for(int i=0;i<n;i++)
    // {
    //     cin>>nums[i];
    // }
    // vector<int>prev(n);
    // prev[0]=nums[0];
    // for(int i=1;i<n;i++)
    // {
    //     prev[i]=min(prev[i-1],nums[i]);
    // }
    // int diff=INT_MIN;
    // int i=n-1;
    // int j=n-1;
    // int firstInd=n;
    // int secondInd=n;
    // while(i>=0 and j>=0)
    // {
    //     if(nums[j]>=prev[i])
    //     {
    //         diff= max(diff, j-i);
    //         if(j<=secondInd)
    //         {
    //             secondInd=j;
    //             firstInd=i;
    //         }
    //         i--;
    //     }
    //     else 
    //         j--;
    // }
    // cout<<secondInd-firstInd<<endl;
    int m,n;

    return 0;
}