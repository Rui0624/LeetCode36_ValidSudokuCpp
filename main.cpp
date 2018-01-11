//
//  main.cpp
//  LeetCode36_Valid Sudoku
//
//  Created by Rui on 1/10/18.
//  Copyright © 2018 Rui. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if(board.empty() || board[0].empty())
            return false;
        
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<bool>> rowFlag(m, vector<bool>(n, false));
        vector<vector<bool>> colFlag(m, vector<bool>(n, false));
        vector<vector<bool>> cellFlag(m, vector<bool>(n, false));
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] >= '1' && board[i][j] <= '9')
                {
                    int c = board[i][j] - '1';
                    if(rowFlag[i][c] || colFlag[c][j] || cellFlag[3 * (i / 3) + (j / 3)][c])
                        return false;
                    
                    rowFlag[i][c] = true;
                    colFlag[c][j] = true;
                    cellFlag[3 * (i / 3) + (j / 3)][c] = true;
                }
                
            }
        }
        
        return true;
    }
};
