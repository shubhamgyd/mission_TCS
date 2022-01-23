/*
You want to buy a laptop. Each laptop has two parameters: Rating & Price. Your task is to 
buy a laptop with the highest rating within a given price range. Given Q tasks, each query 
consisting of price range required, you have to print the highest rated laptop that can be 
bought within that price range.

Input format:

The first line contains N denoting the number of inputs.
The following N lines contain P & R denoting price and range of a laptop.
Next line contains Q denoting the number of queries.
The following Q lines contain two integers X & Y denoting the price range (inclusive).
Output format:
For each task Q, print the highest rating that can be bought within the range.
If you cannot get any laptop within the range, print -1.

Constraints:
image

Sample Input:
5
1000 300
1100 400
1300 200
1700 500
2000 600
3
1000 1400
1700 1900
0 2000

Sample Output:
400
500
600

ans link: https://leetcode.com/discuss/interview-question/370770/Postman-or-HackerEarth-or-Software-Engineering-Intern-or-Bengaluru-India
*/

#include<bits/stdc++.h>
using namespace std;

void constructTree(int node, int l, int r, vector<int> &tree, vector<vector<int>> &nums){
    if(l == r){
        tree[node] = nums[l][1];
        return;
    }
    int m = (l + r) / 2;
    constructTree(node * 2 + 1, l, m, tree, nums);
    constructTree(node * 2 + 2, m + 1, r, tree, nums);
    tree[node] = max(tree[node * 2 + 1], tree[node * 2 + 2]);
}

int getMax(int node, int qs, int qe, int ss, int se, vector<int> &tree, vector<vector<int>> &nums){
    if(nums[se][0] < qs || qe < nums[ss][0])
        return 0;
    if(qs <= nums[ss][0] && nums[se][0] <= qe)
        return tree[node];
    int m = (ss + se) / 2;
    return max(getMax(2 * node + 1, qs, qe, ss, m, tree, nums), getMax(2 * node + 2, qs, qe, m + 1, se, tree, nums));
}

int main(){
    int n, q, size;

    cin >> n;
    vector<vector<int>> nums(n, vector<int>(2));

    for(int i = 0; i < n; i++)
        cin >> nums[i][0] >> nums[i][1];
    sort(nums.begin(), nums.end());
    size = 2 * pow(2, ceil(log2(n)));
    vector<int> tree(size);
    constructTree(0, 0, n - 1, tree, nums);

    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << getMax(0, l, r, 0, n - 1, tree, nums) << endl;
    }
    return 0;
}
// Time Complexity:O(nlogn) for construction a tree and O(logn) for getting the max value
