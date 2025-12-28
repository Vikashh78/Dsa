#include <iostream>
using namespace std;
#include <vector>


// this algo find the maximum subarray sum in TC - O(n)
int maxSubArraySum(vector<int>& nums) {

    int maxSum = nums[0];
    int currentSum = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        currentSum = max(nums[i], currentSum + nums[i]);
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}




int main() {

    vector<int> nums = {1,1,1};

    int result = maxSubArraySum(nums);

    cout<<"Maximum subArray sum is " <<result <<endl; 


    return 0;
}