#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <queue>


// approach.1 -- taking TC: O(n^2)  and SC: O(n^2)
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






// Approach.2 using min heap--
/* algo:
    1.create a minHeap
    2.find the subArray sum 
    3. agar minHeap ka size k se chhota hai to sum ko push kar do minHeap me
    4. else - agar sum ki value top se jayada hai to push kar do
    5. retur kar do top ko wahi second largest sum hoga */
int kthLargest(vector<int> arr, int k){
   
    priority_queue<int, vector<int>, greater<int> > minHeap;

    for(int i=0; i<arr.size(); i++) {
        int sum = 0;
        for(int j=i; j<arr.size(); j++) {
            sum += arr[j];

            if(minHeap.size() < k) {
                minHeap.push(sum);
            }

            else {
                if(sum > minHeap.top()) {
                    minHeap.pop();
                    minHeap.push(sum);
                }
            }
        }
    }

    return minHeap.top();
}



int main() {

    vector<int> arr = {1, 2, 3};
    int k = 2;

    // int result = getKthLargest(arr, k);
    // cout<<k <<"th largest subArray sum is : "<<result <<endl;


    int result = kthLargest(arr, k);
    cout<<k <<"th largest subArray sum is : "<<result <<endl;

	
    return 0;
}