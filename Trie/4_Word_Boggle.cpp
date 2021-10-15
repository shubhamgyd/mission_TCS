
#include <bits/stdc++.h>
using namespace std;

class Solution
{

    vector<string> res;
    set<string> st;
    struct Trie
    {
        Trie *children[256];
        bool endOfWord;
    };

    Trie *getNode()
    {
        Trie *pnode = new Trie;
        pnode->endOfWord = false;
        for (int i = 0; i < 256; i++)
        {
            pnode->children[i] = NULL;
        }
        return pnode;
    }

    void insert(struct Trie *root, string s)
    {
        Trie *p = root;
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            int index = s[i] - 'A';
            if (!p->children[index])
            {
                p->children[index] = getNode();
            }
            p = p->children[index];
        }
        p->endOfWord = true;
    }

    bool isSafe(int i, int j, vector<vector<bool>> &visited)
    {
        int n = visited.size();
        int m = visited[0].size();
        return (i >= 0 && i < n && j >= 0 && j < m && !visited[i][j]);
    }

    void Search(Trie *root, vector<vector<char>> &board, int i, int j, vector<vector<bool>> &visited, string str)
    {
        if (root->endOfWord == true)
        {
            //res.push_back(str);
            st.insert(str);
            //return;
        }

        if (isSafe(i, j, visited))
        {
            visited[i][j] = true;

            for (int k = 0; k < 256; k++)
            {
                if (root->children[k] != NULL)
                {
                    char ch = (char)k + (char)'A';

                    if (isSafe(i + 1, j + 1, visited) && board[i + 1][j + 1] == ch)
                    {
                        Search(root->children[k], board, i + 1, j + 1, visited, str + ch);
                    }
                    if (isSafe(i, j + 1, visited) && board[i][j + 1] == ch)
                    {
                        Search(root->children[k], board, i, j + 1, visited, str + ch);
                    }
                    if (isSafe(i - 1, j + 1, visited) && board[i - 1][j + 1] == ch)
                    {
                        Search(root->children[k], board, i - 1, j + 1, visited, str + ch);
                    }
                    if (isSafe(i - 1, j, visited) && board[i - 1][j] == ch)
                    {
                        Search(root->children[k], board, i - 1, j, visited, str + ch);
                    }
                    if (isSafe(i - 1, j - 1, visited) && board[i - 1][j - 1] == ch)
                    {
                        Search(root->children[k], board, i - 1, j - 1, visited, str + ch);
                    }
                    if (isSafe(i, j - 1, visited) && board[i][j - 1] == ch)
                    {
                        Search(root->children[k], board, i, j - 1, visited, str + ch);
                    }
                    if (isSafe(i + 1, j - 1, visited) && board[i + 1][j - 1] == ch)
                    {
                        Search(root->children[k], board, i + 1, j - 1, visited, str + ch);
                    }
                    if (isSafe(i + 1, j, visited) && board[i + 1][j] == ch)
                    {
                        Search(root->children[k], board, i + 1, j, visited, str + ch);
                    }
                }
            }
            visited[i][j] = false;
        }
    }

public:
    vector<string> wordBoggle(vector<vector<char>> &board, vector<string> &dictionary)
    {

        Trie *root = getNode();
        int size = dictionary.size();
        for (int i = 0; i < size; i++)
        {
            insert(root, dictionary[i]);
        }
        int n = board.size();
        int m = board[0].size();
        string str = "";
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int temp = board[i][j] - 'A';
                if (root->children[temp])
                {
                    str += board[i][j];
                    Search(root->children[temp], board, i, j, visited, str);
                    str = "";
                }
            }
        }
        vector<string> ans(st.begin(), st.end());
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i)
        {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }

        int R, C;
        cin >> R >> C;
        vector<vector<char>> board(R);
        for (int i = 0; i < R; i++)
        {
            board[i].resize(C);
            for (int j = 0; j < C; j++)
                cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else
        {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++)
                cout << output[i] << " ";
        }
        cout << endl;
    }
}

/*
Expected Time Complexity: O(N*W + R*C^2)
Expected Auxiliary Space: O(N*W + R*C)


Time complexity: O(4^(N^2)). 
    Even after applying trie the time complexity remains same. For every cell there are 4 directions and there are N^2 cells. So the time complexity is O(4^(N^2)).
Auxiliary Space: O(N^2). 
    The maximum length of recursion can be N^2, where N is the side of the matrix. So the space Complexity is O(N^2).
*/

//Easy
// another solution

int R, C;
struct Trie
{
    string val;
    int count;
    Trie *child[256];
    Trie()
    {
        for (int i = 0; i < 256; ++i)
            child[i] = NULL;
        count = 0;
    }
};
void insertTrie(Trie *cur, string s)
{
    for (int i = 0; i < s.length(); ++i)
    {
        if (cur->child[s[i]] == NULL)
              cur->child[s[i]] = new Trie();
        cur = cur->child[s[i]];
    }
    cur->val = s;
    cur->count += 1;
}

void helper(vector<vector<char>> &board, vector<string> &res, int i, int j, Trie *curr)
{
    if (i < 0 || i >= R || j < 0 || j >= C || board[i][j] == '#' || !curr->child[board[i][j]])
        return;

    int index = board[i][j];
    curr = curr->child[index];
    if (curr->count > 0)
    {
        while (curr->count)
        {
            res.push_back(curr->val);
            curr->count--;
        }
    }
    char c = board[i][j];
    board[i][j] = '#';
    helper(board, res, i - 1, j, curr);
    helper(board, res, i - 1, j + 1, curr);
    helper(board, res, i, j + 1, curr);
    helper(board, res, i + 1, j + 1, curr);
    helper(board, res, i + 1, j, curr);
    helper(board, res, i + 1, j - 1, curr);
    helper(board, res, i, j - 1, curr);
    helper(board, res, i - 1, j - 1, curr);
    board[i][j] = c;
}
vector<string> wordBoggle(vector<vector<char>> &board, vector<string> &dictionary)
{
    // Code here
    Trie *root = new Trie();
    for (int i = 0; i < dictionary.size(); ++i) insertTrie(root, dictionary[i]);
    int r = board.size();
    int c = board[0].size();
    vector<string> res;

    for (int i = 0; i < r; ++i)
    {
        for (int j=0;j<c;++j)
        {
            if (root->child[board[i][j]])
                helper(board, res, i, j, root);
        }
    }
    return res;
}
