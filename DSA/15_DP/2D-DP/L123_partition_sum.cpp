//leetCode : 416
//Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //Top-Down
    bool solveMemo(int idx, vector<int> &nums, int n, int target, vector<vector<int>> &dp) {
        //base case
        if(idx >= n || target < 0) 
            return 0;
        if(target == 0)
            return 1;

        if(dp[idx][target] != -1)
            return dp[idx][target];
        
        bool incl = solveMemo(idx+1, nums, n, target-nums[idx], dp);
        bool excl = solveMemo(idx+1, nums, n, target, dp);

        dp[idx][target] = (incl or excl);
        return dp[idx][target];
    }


    //Bottom-up
    bool solveTab(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        //acc to base case
        for(int i=0; i<=n; i++) {
            dp[i][0] = 1;
        }

        for(int idx=n-1; idx>=0; idx--) {
            for(int tar=0; tar<=target; tar++) {
                bool incl = 0; //to check -ve idx
                if((tar-nums[idx]) >= 0)    
                    incl = dp[idx+1][tar-nums[idx]];

                bool excl = dp[idx+1][tar];

                dp[idx][tar] = (incl or excl);
            }
        }
        return dp[0][target];
    }


    //space optimization
    bool solveSO(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> curr(target +1, 0);
        vector<int> next(target +1, 0);
        curr[0] = 1;
        next[0] = 1;

        for(int idx=n-1; idx>=0; idx--) {
            for(int tar=0; tar<=target; tar++) {
                bool incl = 0; //to check -ve idx
                if((tar-nums[idx]) >= 0)    
                    incl = next[tar-nums[idx]];

                bool excl = next[tar];

                curr[tar] = (incl or excl);
            }
            next = curr;
        }
        return next[target];
    }

    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            totalSum+= nums[i];
        }
        if(totalSum%2 != 0) 
            return 0;
        
        int target = totalSum/2;

        // vector<vector<int>> dp(n, vector<int>(target+1, -1));
        // return solveMemo(0, nums, n, target, dp);

        // return solveTab(nums, target);

        return solveSO(nums, target);
    }
};

int main() {

    return 0;
}