/*
Find k spikes in list of int. Basically the problem is that there is a value k that is the minimum number of elemens that are less than a particular number (array[i]), so for example:
array: 1,2,8,5,3,4
k = minimum number of elements are less than the current value array[i] = 2 in this test case.

so 1,2 < 8 and 5, 3 < 8
AND
1, 2 < 5 AND 3,4 < 5

so the answer is 2.
*/

#include <bits/stdc++.h>
using namespace std;

class Block
{
public:
    int total;
    unordered_map<int, int> num2count;
};

class Blocks
{
public:
    vector<Block> blocks;
    int block_size;

    Blocks(int n)
    {
        block_size = sqrt(n);
        blocks = vector<Block>(block_size + 1, Block());
    }

    int count_smaller(int num)
    {
        int count = 0;
        int index = num / block_size;
        for (int i = 0; i < index; i++)
        {
            count += blocks[i].total;
        }

        for (auto it : blocks[index].num2count)
        {
            if (it.first < num)
            {
                count += it.second;
            }
        }

        return count;
    }

    void insert(int num)
    {
        int index = num / block_size;
        blocks[index].num2count[num]++;
        blocks[index].total++;
    }
};
class Solution
{
public:
    vector<int> countOfSmallerNumberII(vector<int> &A)
    {
        // write your code here
        vector<int> result;
        if (A.empty())
            return result;

        Blocks b(10000);
        for (auto num : A)
        {
            int count = b.count_smaller(num);
            result.push_back(count);
            b.insert(num);
        }

        return result;
    }
};

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
}