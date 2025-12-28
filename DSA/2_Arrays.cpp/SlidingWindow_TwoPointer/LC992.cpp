//992. Subarrays with K Different Integers
/*Given an integer array nums and an integer k, return the number of good subarrays of nums.
A good array is an array where the number of different integers in that array is exactly k.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.*/

/*!IMP catch : when you don't know when to increase or dec window size
then use this concept : [solve(arr, k) - solve(arr, k-1)] */
 
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int solve(vector<int>& nums, int k) {

        int l=0, r=0, cnt=0;
        unordered_map<int, int> mpp;
        while(r < nums.size()) {
            mpp[nums[r]]++;

            while(mpp.size() > k) {
                mpp[nums[l]]--;
                if(mpp[nums[l]] == 0) mpp.erase(nums[l]);
                l++;
            }
            cnt+=r-l+1;
            r++;
        }
        return cnt;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k-1);
    }
};