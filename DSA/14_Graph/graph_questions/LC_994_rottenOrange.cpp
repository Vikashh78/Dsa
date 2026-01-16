/*
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();          
        int m = grid[0].size();       

        // visited matrix to track oranges that are already rotten/processed
        vector<vector<int>> visited(n, vector<int>(m));

        int cntFresh = 0;             // total number of fresh oranges

        // queue stores: {{row, col}, time}
        queue<pair<pair<int,int>, int>> q;

        // STEP 1: Traverse the grid
        // - Push all initially rotten oranges into queue with time = 0
        // - Count fresh oranges
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 2) {
                    // initially rotten orange → starting points of BFS
                    q.push({{i, j}, 0});
                    visited[i][j] = 2;
                }
                else {
                    visited[i][j] = 0;
                }

                if(grid[i][j] == 1)
                    cntFresh++;     
            }
        }

        // STEP 2: BFS traversal (multi-source BFS)
        int time = 0;                 
        int count = 0;                // number of fresh oranges that become rotten

        // direction arrays (up, right, down, left)
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};

        while(!q.empty()) {

            int row = q.front().first.first;
            int col = q.front().first.second;
            int tm  = q.front().second;
            q.pop();

            time = max(time, tm);   

            // check all 4 adjacent cells
            for(int i = 0; i < 4; i++) {

                int nRow = row + delRow[i];
                int nCol = col + delCol[i];

                // valid cell + fresh orange + not visited
                if(nRow >= 0 && nRow < n &&
                   nCol >= 0 && nCol < m &&
                   visited[nRow][nCol] == 0 &&
                   grid[nRow][nCol] == 1) {

                    // rot the fresh orange
                    q.push({{nRow, nCol}, tm + 1});
                    visited[nRow][nCol] = 2;
                    count++;          // increase rotten count
                }
            }
        }

        // STEP 3: If all fresh oranges are not rotten
        if(count != cntFresh)
            return -1;

        // otherwise, return total time taken
        return time;
    }
};

int main() {
    
    Solution s;

    vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    int ans = s.orangesRotting(grid);
    cout<<ans<<endl;
}
