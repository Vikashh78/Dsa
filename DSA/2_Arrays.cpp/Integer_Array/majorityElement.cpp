#include <iostream>
using namespace std;
#include <vector>

int majorityElement(vector<int>& nums){

    int start=0, result, count=0, res=0;
    while(start < nums.size()){
        result=nums[start];
        for(int i=start+1; i<nums.size(); i++){
            if(result == nums[i]){
                count++;
                if(count > res)
                res = count;
            }
        }
        start++;
    }
    if(res >= nums.size()/2)
    return result;
    else
    return 0;
   
}


int main(){

    vector<int> nums ={2,2,-1,2,-1,-1,-1};

    int res = majorityElement(nums);

    cout<<res<<endl;

    return 0;
}