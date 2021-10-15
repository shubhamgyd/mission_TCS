#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int used1[9][9] = {0}, used2[9][9] = {0}, used3[9][9] = {0};
        
        for(int i = 0; i < board.size(); ++ i)
            for(int j = 0; j < board[i].size(); ++ j)
                if(board[i][j] != '.')
                {
                    int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
                    if(used1[i][num] || used2[j][num] || used3[k][num])
                        return false;
                    used1[i][num] = used2[j][num] = used3[k][num] = 1;
                }
        
        return true;
        
        
        
    //     map<char,int> row[9],col[9],blk[9];
    // char c;
    // for(int i = 0;i<9;i++){
    //     for(int j =0;j<9;j++){
    //         c = board[i][j];
    //         if((c!='.')&&(0<row[i][c]++ || 0<col[j][c]++ || 0<blk[i/3*3+j/3][c]++)) return false;
    //     }
    // }
    // return true;
    }
};