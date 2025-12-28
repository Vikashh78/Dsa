#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>


int getKthLargest(vector<int> &arr, int k) {
	vector<int> nums;

	for(int i=0; i<arr.size(); i++) {
		int sum = 0;

		for(int j=i; j<arr.size(); j++) {
			
			sum = sum+ (arr[j]);

			nums.push_back(sum);
		}
	}

	sort(nums.begin(), nums.end());
	
	return nums[nums.size() - k];
}


int main() {

    vector<int> arr = {1, -2, 3, -4, 5};
    int k = 2;

    int result = getKthLargest(arr, k);
    cout<<k <<"th largest subArray sum is : "<<result <<endl;
	
    return 0;
}