// #include<bits/stdc++.h>
// using namespace std;

// struct Node
// {
//     int data;
//     Node* left;
//     Node* right;
// };

// vector<int> leftView(Node *root)
// {
//    // Your code here
//    vector<int>v;
//    if(!root)
//    {
//        return v;
//    }
//    int ct=0;
//    int count=0;
//    queue<Node*>q;
//    q.push(root);
//    while(!q.empty())
//    {
//         count=q.size();
//         while(count--)
//         {
//             Node* curr=q.front();
//             q.pop();
//             if(ct==0)
//             {
//                 v.push_back(curr->data);
//             }
//             ct++;
//             if(curr->left)
//             {
//                 q.push(curr->left);
//             }
//             if(curr->right)
//             {
//                 q.push(curr->right);
//             }
//         }
//         ct=0;
//    }
//    return v;
// }

// // Time :O(n)
// // Space : O(h) , h-height of the tree

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {

        queue<TreeNode *> q;
        q.push(root);
        int level = 0;
        if(depth==1)
        {
            TreeNode* node=new TreeNode(val);
            node->left=root;
            return node;
        }
        depth-=2;
        int flag = 0;
        while (!q.empty())
        {
            if (level == depth)
            {
                int size = q.size();
                flag = 1;
                while (size--)
                {
                    auto it = q.front();
                    q.pop();
                    TreeNode *curr = it->left;
                    it->left =  new TreeNode(val);
                    it->left->left = curr;


                    curr = it->right;
                    it->right =  new TreeNode(val);
                    it->right->right = curr;
                }
                if (flag == 1)
                {
                    break;
                }
            }
            else
            {
                int size = q.size();
                while (size--)
                {
                    auto it = q.front();
                    q.pop();
                    if (it->left)
                    {
                        q.push(it->left);
                    }
                    if (it->right)
                    {
                        q.push(it->right);
                    }
                }
            }
            level++;
        }
        q={};
        return root;
    }
};
TreeNode *CreateNode(int data)
{
    TreeNode *newNode = new TreeNode();
    if (!newNode)
    {
        cout << "Memory error\n";
        return NULL;
    }
    newNode->val = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void sum(TreeNode* root)
{
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
        auto size=q.size();
        int sum=0;
        while(size--)
        {
            auto curr=q.front();
            q.pop();
            sum+=curr->val;
            if(curr->left)
            {
                q.push(curr->left);
            }
            if(curr->right)
            {
                q.push(curr->right);
            }
        }
        cout<<sum<<endl;
    }
}

int main()
{
    TreeNode *root = CreateNode(4);
    root->left = CreateNode(2);
    root->right = CreateNode(6);
    root->left->left = CreateNode(3);
    root->left->right = CreateNode(1);
    root->right->left = CreateNode(5);
    Solution obj;
    //cout<<"Hello"<<endl;
    TreeNode *temp = obj.addOneRow(root, 1, 2);
    queue<TreeNode *> q;
    q.push(temp);
    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            auto it = q.front();
            q.pop();
            cout << it->val << " ";
            if (it->left)
            {
                q.push(it->left);
            }
            if (it->right)
            {
                q.push(it->right);
            }
        }
        cout << endl;
    }
    return 0;
}