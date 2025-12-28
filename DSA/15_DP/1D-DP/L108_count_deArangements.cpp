// Given a number 'N', find the total number of dearangements of a set of 'N' elements. Num starting from 0 only.

#include <iostream>
#include <vector>
using namespace std;

//Recursive method : exponential complexity
int solveRec(int n) {
    //base case
    if(n == 1) 
        return 0;
    if(n == 2)
        return 1;

    int ans = (n-1)*(solveRec(n-1) + solveRec(n-2));
    return ans;
}


//Memoization : O(N), O(n)+O(n)
int solveMemo(int n, vector<int> &dp) {
    //base case
    if(n == 1) 
        return 0;
    if(n == 2)
        return 1;

    //step3.
    if(dp[n] != -1) {
        return dp[n];
    }

    dp[n] = (n-1)*(solveMemo(n-1, dp) + solveMemo(n-2, dp));
    return dp[n];
}


//Bottom-up : O(N), O(n)
int solveTabu(int n) {
    //step.1
    vector<int> dp(n+1, 0); //for n>0

    dp[1] = 0; //from base case
    dp[2] = 1;

    for(int i=3; i<=n; i++) {//index considaeration from 1
        int first = dp[i-1];
        int second = dp[i-2];
        int sum = first+second;

        int ans = (i-1)*sum;
        dp[i] =ans;
    }
    return dp[n];
}


//space optimization : O(n), O(1)
int solveOptm(int n) {
    //index considaeration from 1
    int prev2 = 0;
    int prev1 = 1;

    for(int i=3; i<=n; i++) {//index considaeration from 1
        int first = prev1;
        int second = prev2;
        int sum = (prev1 + prev2);

        int ans = (i-1)*sum; //relation
        prev2 = prev1;
        prev1 = ans;

    }
    return prev1;
}


int main() {

    int n = 3; //0,1,2
    // int ans = solveRec(n);

    // vector<int> dp(n+1, -1);
    // int ans = solveMemo(n, dp);
    // cout<<"No of ways for dearangemets are : "<<ans<<endl;

    // int ans = solveTabu(n);
    // cout<<"No of ways for dearangemets are : "<<ans<<endl;

    int ans = solveOptm(n);
    cout<<"No of ways for dearangemets are : "<<ans<<endl;

    return 0;
}
