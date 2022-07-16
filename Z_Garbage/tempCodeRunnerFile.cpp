
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    struct TreeNode *left, *right;
};

struct TreeNode *newNode(int data)
{
    struct TreeNode *node = new (struct TreeNode);
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

int max(int a, int b)
{
    return (a >= b) ? a : b;
}

int maxPathSum(struct TreeNode *root, int &res)
{

    if (root == NULL)
    {
        return 0;
    }
    if (!root->left && !root->right)
    {
        return root->data;
    }
    int leftSum = maxPathSum(root->left, res);
    int rightSum = maxPathSum(root->right, res);

    if (root->left && root->right)
    {
        res = max(res, leftSum + rightSum + root->data);
        return max(leftSum, rightSum) + root->data;
    }
    return (!root->left) ? rightSum + root->data : leftSum + root->data;
}

int MaxNodesSum(struct TreeNode *root)
{
    int res = INT_MIN;
    int val = maxPathSum(root, res);
    if (root->left && root->right)
    {
        return res;
    }
    return max(res, val);
}

struct Job
{
    int st;
    int et;
    int profit;
};

int MaxProfit(struct Job *jobs, int m)
{
    vector<int> startTime(m);
    vector<int> endTime(m);
    vector<int> profit(m);
    for (int i = 0; i < m; i++)
    {
        int start = jobs[i].st;
        int end = jobs[i].et;
        int pf = jobs[i].profit;
        startTime[i] = start;
        endTime[i] = end;
        profit[i] = pf;
    }
    map<int, int> times;
    unordered_map<int, vector<pair<int, int>>> jobSchedular;
    int n=m;
    for (int i = 0; i < n; i++)
    {
        times[startTime[i]] = 0;
        jobSchedular[startTime[i]].push_back({endTime[i], profit[i]});
    }
    int max_profit = 0;
    for (auto it = rbegin(times); it != rend(times); ++it)
    {
        for (auto job : jobSchedular[it->first])
        {
            auto it = times.lower_bound(job.first);
            max_profit = max(max_profit, (it == end(times) ? 0 : it->second) + job.second);
        }
        it->second = max_profit;
    }
    return max_profit;
}

int main()
{
    // struct TreeNode *root = newNode(8);
    // root->left = newNode(7);
    // root->right = newNode(-10);
    // root->left->left = newNode(-3);
    // root->left->right = newNode(9);
    // root->left->left->left = newNode(6);
    // root->left->left->right = newNode(1);
    // root->right->left = newNode(1);
    // root->right->right = newNode(-2);
    // cout << "Max pathSum of the given binary tree is "
    //      << MaxNodesSum(root);
    int m;
    cin>>m;
    struct Job job[m];
    // vector<Job*>job(m);
    for(int i=0;i<m;i++)
    {
        cin>>job[i].st>>job[i].et>>job[i].profit;
    }
    int ans=MaxProfit(job,m);
    cout<<ans<<endl;
}