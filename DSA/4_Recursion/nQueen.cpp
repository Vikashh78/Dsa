#include <iostream>
#include<string>
#include <vector>
using namespace std;

class Solution {
public:
bool isSafe(vector<string> &board, int currrow, int currcol, int n) {
        // //horizontal
        // for(int i=0; i<n; i++) {
        //     if(board[currrow][i] == 'Q')
        //         return false;
        // }
        
        //vertical
        for(int i=0; i<n; i++) {
            if(board[i][currcol] == 'Q')
                return false;
        }
        //check for diagonals (left)
        for(int i=currrow,j=currcol; i>=0 && j>=0; i--,j--) {
            if(board[i][j] == 'Q')
                return false;
        }
        //check for diagonals (right)
        for(int i=currrow,j=currcol; i>=0 && j<n; i--,j++) {
            if(board[i][j] == 'Q')
                return false;
        }

        return true;
    }

    void nQueen(int n, vector<string>& board, vector<vector<string>>& result, int row) {
        //base case
        if(row == n) {
            result.push_back(board);
            return;
        }

        for(int j=0; j<n; j++) {
            if(isSafe(board, row, j, n)) {
                board[row][j] = 'Q';
                nQueen(n, board, result, row+1);
                board[row][j] = '.'; //backtrack
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> result;
        int row = n-1, col = n-1;
        nQueen(n, board, result, 0);
        
        // print results
        for (auto &sol : result) {
            for (auto &row : sol)
                cout << row << " ";
            cout<< endl;
        }
    }
};

int main() {
    
    Solution s;
    s.solveNQueens(8);

    return 0;
}