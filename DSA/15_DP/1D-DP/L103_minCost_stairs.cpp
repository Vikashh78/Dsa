#include <iostream>
#include <vector>
using namespace std;
//LeetCode : prob-746
/*You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.
You can either start from the step with index 0, or the step with index 1.*/


//1st. simple recursion method  
int solve(vector<int> &cost, int k) {
    //base case
    if(k==0) return cost[0];
    if(k==1) return cost[1];

    int result = min(solve(cost, k-1), solve(cost, k-2)) + cost[k];
    return result;
}

//2nd. DP: recursion + memoization (T-O(n), S-O(n)+O(n))
int solve2(vector<int> &dp, vector<int> &cost, int k) {
    //base case
    if(k==0) return cost[0];
    if(k==1) return cost[1];

    //step.3
    if(dp[k] != -1) return dp[k];

    //step.2
    dp[k] = min(solve2(dp, cost, k-1), solve2(dp, cost, k-2)) + cost[k];
    return dp[k];
}


//3rd. DP: Tabulation method(Bottom-up) (T-O(n), S-O(n))
int solve3(vector<int> &cost, int n) {
    //step1.
    vector<int> dp(n+1);

    // step.2 base case analysis
    dp[0] = cost[0];
    dp[1] = cost[1];

    // step.3
    for(int i=2; i<n; i++) {
        dp[i] = cost[i]+ min(dp[i-1], dp[i-2]);
    }

    return min(dp[n-1], dp[n-2]);
}


//4th. TODO: try to optimize (T-O(n), S-O(1))
int solve4(vector<int> &cost, int n) {
    int prev1 = cost[1];
    int prev2 = cost[0];

    for(int i=2; i<n; i++) {
        int curr = cost[i]+ min(prev1, prev2);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main() {

    vector<int> cost = {1,100,1,1,1,100,1,1,100,1};
    int n = cost.size();

    // int ans = min(solve(cost, n-1), solve(cost, n-2));
    // cout<<ans<<endl;

    // vector<int> dp(n+1, -1); //step.1
    // int ans2 = min(solve2(dp, cost, n-1), solve2(dp, cost, n-2));
    // cout<<ans2<<endl;

    // int ans = solve3(cost, n);
    // cout<<ans<<endl;

    int ans = solve4(cost, n);
    cout<<ans<<endl;

    return 0;
}