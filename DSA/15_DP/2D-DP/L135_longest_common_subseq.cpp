#include <iostream>
#include <string>
#include <vector>
using namespace std;

    int solve(string &text1, string &text2, int i, int j) {
        //base case
        if(i>=text1.size() || j>=text2.size()) {
            return 0;
        }
        // for matching
        if(text1[i] == text2[j]) {
            return 1+ solve(text1, text2, i+1, j+1);
        }
        //not matching
        else {
            return max(solve(text1, text2, i+1, j), solve(text1, text2, i, j+1));
        }
    }

    //Top down 
    int solveMemo(string &text1, string &text2, int i, int j, vector<vector<int>>& dp) {
        //base case
        if(i>=text1.size() || j>=text2.size()) {
            return 0;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        // for matching
        if(text1[i] == text2[j]) {
            return dp[i][j] = 1+ solveMemo(text1, text2, i+1, j+1, dp);
        }
        //not matching
        else {
            return dp[i][j] = max(solveMemo(text1, text2, i+1, j, dp), solveMemo(text1, text2, i, j+1, dp));
        }
    }

    //Bottom Up
    int solveTab(string &text1, string &text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        for(int i=n-1; i>=0; i--) {
            for(int j=m-1; j>=0; j--) {
                //matching
                if(text1[i] == text2[j]) {
                    dp[i][j] = 1 + dp[i+1][j+1];
                }
                //not matching
                else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        return dp[0][0]; //yaha pe function call ke parameters return hote hai, i.e. dp[0][0];
    }


    //space optimization
    int solveSO(string &text1, string &text2) {
        
        int n = text1.size(), m = text2.size();
        vector<int> curr(m+1, 0);
        vector<int> next(m+1, 0);

        int ans = 0;
        for(int i=n-1; i>=0; i--) {
            for(int j=m-1; j>=0; j--) {
                //matching
                if(text1[i] == text2[j]) {
                    ans = 1+ next[j+1];
                }
                //not matching
                else {
                    ans = max(next[j], curr[j+1]);
                }
                curr[j] = ans;
            }
            next = curr;
        }
        return next[0]; // curr array is just above the next array, so according to 0 we are returning next.
        
    }

    int longestCommonSubsequence(string &text1, string &text2) {
        // return solve(text1, text2, 0, 0);

        // vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
        // return solveMemo(text1, text2, 0, 0, dp);

        // return solveTab(text1, text2);

        return solveSO(text1, text2);
    }

    int main() {

        string text1, text2;
        cin>>text1 >>text2;

        int ans = longestCommonSubsequence(text1, text2);
        cout<<ans<<endl;

        return 0;
    }