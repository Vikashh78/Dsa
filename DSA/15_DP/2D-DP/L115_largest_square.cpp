// Given a binary matrix mat, find out the maximum length of a side of a square sub-matrix with all 1s.
// LeetCode - 221

#include <iostream>
#include <vector>
using namespace std;


class Solution {
  public:
    int solveRec(vector<vector<int>>& mat, int &maxi, int i, int j) {
        //base case
        if(i>=mat.size() || j>=mat[0].size())
            return 0;
        
        int right = 1+solveRec(mat, maxi, i, j+1);
        int diagonal = 1+solveRec(mat, maxi, i+1, j+1);
        int down = 1+solveRec(mat, maxi, i+1, j);
        
        if(mat[i][j] == 1) {
            int ans = min(right, min(diagonal, down));
            maxi = max(maxi, ans);
            return ans;
        } 
        else {
            return 0;
        }
    }
    
    
    int solveMemo(vector<vector<int>>& mat, int &maxi, int i, int j, vector<vector<int>> &dp) {
        //base case
        if(i>=mat.size() || j>=mat[0].size())
            return 0;
        
        //step.3    
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int right = 1+ solveMemo(mat, maxi, i+1, j, dp);
        int diagonal = 1+ solveMemo(mat, maxi, i+1, j+1, dp);
        int down = 1+ solveMemo(mat, maxi, i, j+1, dp);
        
        if(mat[i][j] == 1) {
            int ans = min(right, min(diagonal, down));
            maxi = max(maxi, ans);
            //step.2
            dp[i][j] = ans;
            return dp[i][j];
        } 
        else {
            return dp[i][j] = 0;
        }
    }
    
    //bottom up approach
    void solveTabu(vector<vector<int>>& matrix, int &area, int i, int j) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> dp(row+1, vector<int>(col+1, 0));

        for(int i=row-1; i>=0; i--) {
            for(int j=col-1; j>=0; j--) {

                int right = 1+ dp[i][j+1];
                int diagonal = 1+ dp[i+1][j+1];
                int down = 1+ dp[i+1][j];

                if(matrix[i][j] == 1) {
                    dp[i][j] = min(right, min(diagonal, down));
                    area = max(dp[i][j], area);
                } 
                else {
                    dp[i][j] = 0;
                }
            }
        }
    }

    
    int maxSquare(vector<vector<int>>& mat) {
        // code here
        // int maxi = 0;
        // int x = solveRec(mat, maxi, 0, 0);
        // return maxi;
        
        vector<vector<int>> dp(mat.size(), vector<int>(mat[0].size(), -1));
        int maxi = 0;
        int x = solveMemo(mat, maxi, 0, 0, dp);
        return maxi;
        
        // int maxi = 0;
        // int x = solveTab(mat, maxi, i, j);
        // return maxi;
        
    }
};

int main() {

    return 0;
}