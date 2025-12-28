#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void solve(vector<int> nums, int index, vector<vector<int>>& update){

        //base case-
        if(index >= nums.size()){     //3>=3 yes
            update.push_back(nums);
            return;
        }

        for(int i=index; i<nums.size(); i++){
            swap(nums[index], nums[i]);
            //Recursive call-
            solve(nums, index+1, update);
            
            //backtracked-
            swap(nums[index], nums[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> update;
        int index = 0; 
        solve(nums, index, update);

        return update;
    }
};