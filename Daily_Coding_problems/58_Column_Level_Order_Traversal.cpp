

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void Traverse(TreeNode* node,int x,int y,map<int,map<int,multiset<int>>>&mp)
{
    if(node)
    {
        // it will store the element in map increasing order of index
        // i.e from left most element to the rightmost element
        mp[x][y].insert(node->val);
        
        // here we are decreasing the level  so that left part comes before right part
        Traverse(node->left,x-1,x+1,mp);


        // here we are increasing the level so that right part comes after left part
        Traverse(node->right,x+1,y+1,mp);
    }
}


vector<vector<int>> ColumnLevelOrder(TreeNode* node)
{
    map<int,map<int,multiset<int>>>mp;
    Traverse(node,0,0,mp);
    vector<vector<int>>res;
    for(auto it:mp)
    {
        vector<int>ans;
        for(auto ele:it.second)
        {
            ans.insert(ans.end(),ele.second.begin(),ele.second.end());
        }
        res.push_back(ans);
    }
    return res;
}
// Time Complexity:O(h+h*h)
// Space Complexity:O(h*h)


int main()
{

}
