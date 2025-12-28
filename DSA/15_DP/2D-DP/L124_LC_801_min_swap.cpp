/*You are given two integer arrays of the same length nums1 and nums2. In one operation, you are allowed to swap nums1[i] with nums2[i].
For example, if nums1 = [1,2,3,8], and nums2 = [5,6,7,4], you can swap the element at i = 3 to obtain nums1 = [1,2,3,4] and nums2 = [5,6,7,8].
Return the minimum number of needed operations to make nums1 and nums2 strictly increasing. The test cases are generated so that the given input always makes it possible.*/

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;


class Solution {
public:
    int solve(vector<int> &nums1, vector<int> &nums2, int idx, bool swapped) {
        //base case
        if(idx >= nums1.size()) return 0;

        int ans = INT_MAX;

        int prev1 = nums1[idx-1];
        int prev2 = nums2[idx-1];

        //main catch of the program
        if(swapped)
            swap(prev1, prev2);

        //no swap case : if curr element is greater than its previous element then no swap
        if(nums1[idx]>prev1 && nums2[idx]>prev2) 
            ans = 0 + solve(nums1, nums2, idx+1, 0);

        //swap case : it's clear that curr element is not greater than its previous element, so check if curr1 element is greater than prev2 and vice versa
        if(nums1[idx]>prev2 && nums2[idx]>prev1)
            ans = min(ans,  1+ solve(nums1, nums2, idx+1, 1));

        return ans;
    }

    //Top down : Recursion + Memoization
    int solveMemo(vector<int> &nums1, vector<int> &nums2, int idx, bool swapped, vector<vector<int>> &dp) {
        //base case
        if(idx >= nums1.size()) return 0;

        if(dp[idx][swapped] != -1) {
            return dp[idx][swapped];
        }

        int ans = INT_MAX;
        int prev1 = nums1[idx-1];
        int prev2 = nums2[idx-1];

        //main catch of the program
        if(swapped)
            swap(prev1, prev2);

        //no swap case : if curr element is greater than its previous element then no swap
        if(nums1[idx]>prev1 && nums2[idx]>prev2) 
            ans = 0 + solveMemo(nums1, nums2, idx+1, 0, dp);

        //swap case : it's clear that curr element is not greater than its previous element, so check if curr1 element is greater than prev2 and vice versa
        if(nums1[idx]>prev2 && nums2[idx]>prev1)
            ans = min(ans,  1+ solveMemo(nums1, nums2, idx+1, 1, dp));

        dp[idx][swapped] = ans;
        return dp[idx][swapped];
    }



    //Bottom up : Tabulation
    int solveTab(vector<int>& nums1, vector<int>& nums2) {
        //creation of dp array
        int n = nums1.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        for(int idx=n-1; idx>=1; idx--) {
            for(int swapped=1; swapped>=0; swapped--) {
                int ans = INT_MAX;
                int prev1 = nums1[idx-1];
                int prev2 = nums2[idx-1];

                //main catch of the program
                if(swapped)
                    swap(prev1, prev2);

                //no swap case : if curr element is greater than its previous element then no swap
                if(nums1[idx]>prev1 && nums2[idx]>prev2) 
                    ans = 0 + dp[idx+1][0];

                //swap case : it's clear that curr element is not greater than its previous element, so check if curr1 element is greater than prev2 and vice versa
                if(nums1[idx]>prev2 && nums2[idx]>prev1)
                    ans = min(ans, 1+ dp[idx+1][1]);

                dp[idx][swapped] = ans;
            }
        }
        return dp[1][0];
    }


    int minSwap(vector<int>& nums1, vector<int>& nums2) {

        //insert -1 at the begining of both arrays
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        bool swapped = 0;

        // return solve(nums1, nums2, 1, swapped);

        // vector<vector<int>> dp(nums1.size()+1, vector<int>(2, -1)); //only 2 columns, as swapped will be 0/1
        // return solveMemo(nums1, nums2, 1, swapped, dp);

        return solveTab(nums1, nums2);
    }
};

int main() {

    return 0;
}