#include <iostream>
#include <vector>
using namespace std;

// Leetcode : 130 -- read the question description from there only.
/* catch: if any O is prasent at boundary and other zeros connected to that boundary zero then, we will not convert it into 'X' */

class Solution {
private:
    void checkDfs(vector<vector<char>>& board, vector<vector<char>>& visited, int row, int col, int n, int m) {
        visited[row][col] = '1';
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, 0, -1};
        
        for(int i=0; i<4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && board[nrow][ncol] == 'O' && visited[nrow][ncol] == 'O') {
                checkDfs(board, visited, nrow, ncol, n, m);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();
        vector<vector<char>> visited(n, vector<char>(m, 'O'));
    
        //1. check for upper boundary
        for(int j=0; j<m; j++) {
            if(board[0][j] == 'O') {
                checkDfs(board, visited, 0, j, n, m);
            }
        }
        //2. check for right boundary
        for(int i=0; i<n; i++) {
            if(board[i][m-1] == 'O') {
                checkDfs(board, visited, i, m-1, n, m);
            }
        }
        //3. check for lower boundary
        for(int j=m-1; j>=0; j--) {
            if(board[n-1][j] == 'O') {
                checkDfs(board, visited, n-1, j, n, m);
            }
        }
        //4. check for left boundary
        for(int i=n-1; i>=0; i--) {
            if(board[i][0] == 'O') {
                checkDfs(board, visited, i, 0, n, m);
            }
        }

        // after all the checks, its safe to convert so just flip O to X insted of doing bfs again :
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j] == 'O' && visited[i][j] == 'O') {
                    // dfs(board, visited, i, j, n, m);
                    board[i][j] = 'X';
                }
            }
        }
    }
};

int main() {
    vector<vector<char>> board = {
        {'X','X','X','X'},
        {'X','O','O','X'},
        {'X','X','O','X'},
        {'X','O','X','X'}
    };

    Solution s;
    s.solve(board);

    for(int i=0; i<board.size(); i++) {
        for(int j=0; j<board[i].size(); j++) {
            cout<<board[i][j] << " ";
        }
        cout<<endl;
    }

    return 0;
}