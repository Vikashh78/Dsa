//you are given with a nums array you have to return the max sum from the nums by taking adjacent elements.
#include <iostream>
#include <vector>
using namespace std;

//Recursive approach
int solveRec(vector<int> &nums, int n) {
    //base case
    if(n < 0) 
        return 0;

    if(n == 0) 
        return nums[0];

    int incl = solveRec(nums, n-2) + nums[n];
    int excl = solveRec(nums, n-1) + 0;

    return max(incl, excl);
}


//Memoization method
int solveMemo(vector<int> &nums, int n, vector<int> &dp) {

    //base case
    if(n < 0) return 0;
    if(n == 0) return nums[0];

    //step.3
    if(dp[n] != -1)
        return dp[n];
    
    int incl = solveMemo(nums, n-2, dp) + nums[n];
    int excl = solveMemo(nums, n-1, dp) + 0;

    //step.2
    dp[n] = max(incl, excl);
    return dp[n];
}


//Tabulation method
int solveTabu(vector<int> &nums, int n) {

    vector<int> dp(n, 0);

    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for(int i=2; i<n; i++) {
        int incl = nums[i] + dp[i-2];
        int excl = 0 + dp[i-1];
        dp[i] = max(incl, excl);
    }
    return dp[n-1];
}

int main() {

    vector<int> nums = {9,9,8,2};
    int n = nums.size();

    // int result = solveRec(nums, n-1);

    // vector<int> dp(n+1, -1);
    // int result = solveMemo(nums, n-1, dp);

    int result = solveTabu(nums, n-1);

    cout<<"Max sum is : "<<result <<endl;

    return 0;
}