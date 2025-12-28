/*There is a pizza with 3n slices of varying size, you and your friends will take slices of pizza as follows:
You will pick any pizza slice.
Your friend Alice will pick the next slice in the anti-clockwise direction of your pick.
Your friend Bob will pick the next slice in the clockwise direction of your pick.
Repeat until there are no more slices of pizzas.
Given an integer array slices that represent the sizes of the pizza slices in a clockwise direction, return the maximum possible sum of slice sizes that you can pick.*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int solve(int idx, int endIdx, vector<int> &slices, int n) {
        //base case
        if(n == 0 || idx > endIdx) return 0;

        int incl = slices[idx] + solve(idx+2, endIdx, slices, n-1);
        int excl = 0 + solve(idx+1, endIdx, slices, n);

        return max(incl, excl);
    }

    //Top down
    int solveMemo(int idx, int endIdx, vector<int> &slices, int n, vector<vector<int>> &dp) {
        //base case
        if(n == 0 || idx > endIdx) return 0;

        if(dp[idx][n] != -1)
            return dp[idx][n];

        int incl = slices[idx] + solveMemo(idx+2, endIdx, slices, n-1, dp);
        int excl = 0 + solveMemo(idx+1, endIdx, slices, n, dp);

        dp[idx][n] = max(incl, excl);
        return dp[idx][n];
    }

    //bottom up
    int solveTab(vector<int>& slices) {
        int k = slices.size();
        vector<vector<int>> dp1(k+2, vector<int>(k+2, 0));
        for(int idx=k-2; idx>=0; idx--) {
            for(int n=1; n<=k/3; n++) {
                int incl = slices[idx] + dp1[idx+2][n-1];
                int excl = 0 + dp1[idx+1][n];

                dp1[idx][n] = max(incl, excl);
            }
        }
        int case1 = dp1[0][k/3];

        vector<vector<int>> dp2(k+2, vector<int>(k+2, 0));
        for(int idx=k-1; idx>=1; idx--) {
            for(int n=1; n<=k/3; n++) {
                int incl = slices[idx] + dp2[idx+2][n-1];
                int excl = 0 + dp2[idx+1][n];

                dp2[idx][n] = max(incl, excl);
            }
        }
        int case2 = dp2[1][k/3];

        return max(case1, case2);
    }


    //optimal solution by using only 3 array instead of 2D array
    int solveOptimal(vector<int>& slices) {
        int k = slices.size();
        vector<int> prev1(k+2, 0);
        vector<int> curr1(k+2, 0);
        vector<int> next1(k+2, 0);

        for(int idx=k-2; idx>=0; idx--) {
            for(int n=1; n<=k/3; n++) {
                int incl = slices[idx] + next1[n-1];
                int excl = 0 + curr1[n];

                prev1[n] = max(incl, excl);
            }
            next1 = curr1;
            curr1 = prev1;

        }
        int case1 = curr1[k/3];

        vector<int> prev2(k+2, 0);
        vector<int> curr2(k+2, 0);
        vector<int> next2(k+2, 0);

        for(int idx=k-1; idx>=1; idx--) {
            for(int n=1; n<=k/3; n++) {
                int incl = slices[idx] + next2[n-1];
                int excl = 0 + curr2[n];

                prev2[n] = max(incl, excl);
            }
            next2 = curr2;
            curr2 = prev2;
        }
        int case2 = curr2[k/3];

        return max(case1, case2);
    }

    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size(), n = k/3;

        // int a = solve(0, k-2, slices, n);
        // int b = solve(1, k-1, slices, n);
        // return max(a, b);

        // vector<vector<int>> dp1(k, vector<int>(k, -1));
        // int case1 = solveMemo(0, k-2, slices, n, dp1);
        // vector<vector<int>> dp2(k, vector<int>(k, -1));
        // int case2 = solveMemo(1, k-1, slices, n, dp2);
        // return max(case1, case2);

        // return solveTab(slices);

        return solveOptimal(slices);
    }
};

int main() {

    return 0;
}