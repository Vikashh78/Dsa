#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int mid = 0, size = numbers.size();
        int i = 0;
        while(i < size-1) {
            mid = target - numbers[i];
            int j = i+1;

            while(j < size) {
                if(numbers[j] == mid){
                    return {i, j};
                }

                else{
                    j++;
                }
            }

            i++;
        }

        return {};    //correct solution, but only T.L.E deu to nested loop


    //     int start = 0, end = numbers.size()-1;
    //     while(start < end) {
    //         int sum = (numbers[start] + numbers[end]);

    //         if(sum == target){
    //             return {start, end};
    //         }

    //         else if(sum < target){
    //             start++;
    //         }

    //         else{
    //             end--;
    //         }
    //     }

    //     return {};
    }
};

int main() {

    Solution obj;
    
    vector<int> numbers = {2,7,11,15};
    int target = 22;

    vector<int> res = obj.twoSum(numbers, target);

    cout<<"Index of the numbers are : "<<res[0]<<","<<res[1]<<endl;

    return 0;
}