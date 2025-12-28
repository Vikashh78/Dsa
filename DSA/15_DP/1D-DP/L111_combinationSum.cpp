//return the num of the all possible subsets whose sum is equals to target
#include <iostream>
#include <vector>
using namespace std;

//recursive solution : O(exponetial)
int solveRec(vector<int> &nums, int target) {
    //base case
    if(target == 0)
        return 1;
    if(target < 0)
        return 0;

    int ans = 0;
    for(int i=0; i<nums.size(); i++) {
        ans = ans + solveRec(nums, target-nums[i]);
    }

    return ans;
}



//Memoization : O(target)
int solveMemo(vector<int> &nums, int target, vector<int> &dp) {
    //base case
    if(target == 0)
        return 1;
    if(target < 0)
        return 0;

    //step.3
    if(dp[target] != -1)
        return dp[target];

    int ans = 0;
    for(int i=0; i<nums.size(); i++) {
        ans = ans + solveRec(nums, target-nums[i]);
    }
    dp[target] = ans;
    return dp[target];
}


//Tabulation method : O(N*M)
int solveTabu(vector<int> &nums, int tar) {

    vector<int> dp(tar+1, 0);
    dp[0] = 1;

    //traversing on dp[] from 1 to target
    for(int i=1; i<=tar; i++) {
        //traversing on nums[]
        for(int j=0; j<nums.size(); j++) {
            if(i - nums[j] >= 0) 
                dp[i] = dp[i] + dp[i - nums[j]];
        }
    }
    return dp[tar];
}



int main() {

    vector<int> nums = {1,2};
    int target = 3;

    // int ans = solveRec(nums, target);

    // vector<int> dp(target+1, -1);
    // int ans = solveMemo(nums, target, dp);
    // cout<<ans<<endl;

    int ans = solveTabu(nums, target);
    cout<<ans<<endl;

    return 0;
}