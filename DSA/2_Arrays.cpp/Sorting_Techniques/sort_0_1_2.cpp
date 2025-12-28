#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Using three pointers
        int low = 0, mid = 0, high = nums.size() - 1;

        while (mid <= high) { 
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {  // Use else if to prevent multiple increments
                mid++;
            } else { // nums[mid] == 2
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};


int main()
{
   vector<int> nums = {1,1,0,1,2,0,0,1,2,1,1,0,1,0};
    Solution sol;
    sol.sortColors(nums);

    // Print sorted array
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;


    return 0;
}