/* You have planned some train traveling one year in advance. The days of the year in which you will travel are given as an integer array days. Each day is an integer from 1 to 365.

Train tickets are sold in three different ways:

a 1-day pass is sold for costs[0] dollars,
a 7-day pass is sold for costs[1] dollars, and
a 30-day pass is sold for costs[2] dollars.
The passes allow that many days of consecutive travel.

For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
Return the minimum number of dollars you need to travel every day in the given list of days.

Example 1:
Input: days = [1,4,6,7,8,20], costs = [2,7,15]
Output: 11
Explanation: For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 1-day pass for costs[0] = $2, which covered day 1.
On day 3, you bought a 7-day pass for costs[1] = $7, which covered days 3, 4, ..., 9.
On day 20, you bought a 1-day pass for costs[0] = $2, which covered day 20.
In total, you spent $11 and covered all the days of your travel. */

#include<iostream>
using namespace std;
#include <vector>
#include <limits.h>
 
class Solution {
public:
    int solveMemo(int n, vector<int>& days, vector<int>& costs, int idx, vector<int> &dp) {
        //base case
        if(idx >= n)
            return 0;

        if(dp[idx] != -1) {
            return dp[idx];
        }

        //1 day pass
        int opt1 = costs[0] + solveMemo(n, days, costs, idx+1, dp);

        int i;
        //7 day pass
        for(i=idx; i<n && days[i]<days[idx]+7; i++);
        int opt2 = costs[1] + solveMemo(n, days, costs, i, dp);

        //30 days pass
        for(i=idx; i<n && days[i]<days[idx]+30; i++);
        int opt3 = costs[2] + solveMemo(n, days, costs, i, dp);

        dp[idx] = min(opt1, min(opt2, opt3));
        return dp[idx];
    }

    int solveTabu(vector<int>& days, vector<int>& costs, int n) { //bottom up
        //step.1
        vector<int> dp(n+1, INT_MAX);
        dp[n] = 0;

        for(int k=n-1; k>=0; k--) {
            //1 day pass
            int opt1 = costs[0] +dp[k+1];

            int i;
            //7 day pass
            for(i=k; i<n && days[i]<days[k]+7; i++);
            int opt2 = costs[1] + dp[i];

            //30 days pass
            for(i=k; i<n && days[i]<days[k]+30; i++);
            int opt3 = costs[2] + dp[i];

            dp[k] = min(opt1, min(opt2, opt3));
        }
        return dp[0];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        // vector<int> dp(n+1, -1);
        // return solveMemo(n, days, costs, 0, dp);

        return solveTabu(days, costs, n);
    }
};