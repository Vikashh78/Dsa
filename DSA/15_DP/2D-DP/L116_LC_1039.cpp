#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

/*You have a convex n-sided polygon where each vertex has an integer value. You are given an integer array values where values[i] is the value of the ith vertex in clockwise order.
Polygon triangulation is a process where you divide a polygon into a set of triangles and the vertices of each triangle must also be vertices of the original polygon. Note that no other shapes other than triangles are allowed in the division. This process will result in n - 2 triangles.
You will triangulate the polygon. For each triangle, the weight of that triangle is the product of the values at its vertices. The total score of the triangulation is the sum of these weights over all n - 2 triangles.
Return the minimum possible score that you can achieve with some triangulation of the polygon. */

class Solution {
public:
    int solve(vector<int> &values, int i, int j) {
        //base case
        if(i+1 == j)
            return 0;

        int ans = INT_MAX;
        for(int k=i+1; k<j; k++) {
            ans = min(ans, values[i]*values[j]*values[k] + solve(values, i, k) + solve(values, k, j));
        }
        return ans;   
    }

    int solveMemo(vector<int> &values, int i, int j, vector<vector<int>> &dp) {
        //base case
        if(i+1 == j)
            return 0;

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        int ans = INT_MAX;
        for(int k=i+1; k<j; k++) {
            ans = min(ans, values[i]*values[j]*values[k] + solve(values, i, k) + solve(values, k, j));
        }
        dp[i][j] = ans;
        return dp[i][j];   
    }

    int tabulation(vector<int>& values, int n) { //bottom up
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i=n-1; i>=0; i--) {
            for(int j=i+2; j<n; j++) {

                int ans = INT_MAX;
                for(int k=i+1; k<j; k++) {
                    ans = min(ans, values[i]*values[j]*values[k] + dp[i][k] + dp[k][j]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][n-1];
    }

    int minScoreTriangulation(vector<int>& values) {
        int i=0, j=values.size()-1;
        // return solve(values, i, j);  TLE

        //since i and j both values are changing so we need a 2D Dp
        // vector<vector<int>> dp(values.size(), vector<int>(values.size(), -1));
        // return solveMemo(values, i, j, dp);  TLE

        int n = values.size();
        return tabulation(values, n);
    }
};

int main() {

    return 0;
}