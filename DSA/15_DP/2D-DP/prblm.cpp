/*hack with infy - you are given an array of nums of size n. you have to perform the following operation that the neighbour of any element in array
k times and return the minimum sum array possible
constrains : 1 <= n <=1e5
             1 <= k <= 10;
*/

/* input - [1 2 3] k=1
op- [1 1 3]=5, k=0
    [2 2 3]=7, k=0
    [1 2 2]=5, k=0
    [1 3 3]=7, k=0
    so, minimum sum of array is 5 which is aour desire ans
*/

#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <numeric>
using namespace std;

int solve(vector<int>& nums, int k, int i) {
    //base case
    int ans = 0;
    if (k == 0 || i >= nums.size()) {
        return accumulate(nums.begin(), nums.end(), 0);
    }

    int original = nums[i];
    int minSum = INT_MAX;

    // Option 1: don’t change
    minSum = min(minSum, solve(nums, k, i+1));

    // Option 2: change to left neighbor (if exists)
    if (i - 1 >= 0) {
        nums[i] = nums[i - 1];
        minSum = min(minSum, solve(nums, k - 1, i + 1));
        nums[i] = original; // backtrack
    }

    // Option 3: change to right neighbor (if exists)
    if (i + 1 < nums.size()) {
        nums[i] = nums[i + 1];
        minSum = min(minSum, solve(nums, k - 1, i + 1));
        nums[i] = original; // backtrack
    }

    return minSum;
}


int main() {
    // int n, k;
    // cin>>n >>k;
    vector<int> nums = {1,2,3,5};
    int n = nums.size(), k=2;
    int ans = solve(nums, k, 0);
    cout<<ans<<endl;

    return 0;
}