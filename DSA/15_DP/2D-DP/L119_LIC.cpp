/*  Input: arr[] = [5, 8, 3, 7, 9, 1]
    Output: 3
    Explanation: The longest strictly increasing subsequence could be [5, 7, 9], which has a length of 3.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // T. S - (n^2)
    int solveMemo(int n, vector<int> &nums, int curr, int prev, vector<vector<int>> &dp) { //Top-down
        //base case
        if(curr == n) 
            return 0;

        //step.3 Dp
        if(dp[curr][prev+1] != -1) 
            return dp[curr][prev+1];

        int incl = 0;
        if(prev == -1 || nums[curr]>nums[prev]) {
            incl = 1+ solveMemo(n, nums, curr+1, curr, dp);
        }
        int excl = 0+ solveMemo(n, nums, curr+1, prev, dp);

        //step.2 DP
        dp[curr][prev+1] = max(incl, excl);
        return dp[curr][prev+1];
    }

    //Bottom up Approch
    int solveTab(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int curr = n-1; curr>=0; curr--) {
            for(int prev = curr-1; prev>=-1; prev--) {
                int incl = 0;
                if(prev == -1 || nums[curr]>nums[prev]) {
                    incl = 1 + dp[curr+1][curr+1];
                }
                int excl = 0 + dp[curr+1][prev+1];
                dp[curr][prev+1] = max(incl, excl);
            }
        }
        //bcoz, curr iterates to 0 and prev iterates upto -1
        return dp[0][-1+1];
    }

    //space optimizaton
    int solveSO(vector<int>& nums) {
        int n = nums.size();
        vector<int> currRow(n+1, 0);
        vector<int> nextRow(n+1, 0);

        for(int curr = n-1; curr>=0; curr--) {
            for(int prev = curr-1; prev>=-1; prev--) {
                int incl = 0;
                if(prev == -1 || nums[curr]>nums[prev]) {
                    incl = 1 + nextRow[curr+1];
                }
                int excl = 0 + nextRow[prev+1];
                currRow[prev+1] = max(incl, excl);
            }
            nextRow = currRow;
        }
        //bcoz, curr iterates to 0 and prev iterates upto -1
        return nextRow[-1+1];
    }




    //Most Optimal solution : TC O(N*logN) , SC O(n)
    //Dp with binary search
    int solveOptimal(vector<int> &nums, int n) {
        if(n == 0) 
            return 0;

        vector<int> ans;
        ans.push_back(nums[0]);
        for(int i=1; i<n; i++) {
            if(nums[i] > ans.back()) {
                ans.push_back(nums[i]);
            }
            else {
                //finding index of just bada wala element in ans with Binary Search
                int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin(); 
                ans[index] = nums[i];
            }
        }
        return ans.size();
    }


    
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();
        // int curr = 0, prev = -1;
        // vector<vector<int>> dp(n, vector<int>(n+1, -1));
        // // return solveMemo(n, nums, curr, prev, dp);

        // return solveTab(nums);

        // return solveSO(nums);

        return solveOptimal(nums, n);
    }
};

int main() {

    return 0;
}