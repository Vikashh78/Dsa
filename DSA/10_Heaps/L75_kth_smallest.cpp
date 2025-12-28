#include <iostream>
using namespace std;
#include <queue>


// Note: to find kth Smallest element always use maxHeap
int kthSmallest(int arr[], int k, int size) {

        // algo:
        // 1.push first k elements into [max heap]
        // 2.compare the root element with remaining elements if root is greater the pop root
        //     and push the remaining elements by comparing with root
        // 3.after all the comparision the root is your desire ans
        
        priority_queue<int> maxHeap;
        
        for(int i=0; i<k; i++) {
            maxHeap.push(arr[i]);
        }
        
        //step.2
        for(int i=k; i<size; i++) {
            
            if(arr[i] <= maxHeap.top()) {
                
                maxHeap.pop();
                
                maxHeap.push(arr[i]);
                
            }
        }
        
    int ans = maxHeap.top();
    return ans;   
}



// to find kth Largest element always use minHeap.
int kthLargest_element(int arr[], int k, int size) {

    priority_queue<int, vector<int>, greater<int> > minHeap;
        
        for(int i=0; i<k; i++) {
            minHeap.push(arr[i]);
        }
        
        //step.2
        for(int i=k; i<size; i++) {
            
            if(arr[i] >= minHeap.top()) { //one change is here i.e. >=
                
                minHeap.pop();
                
                minHeap.push(arr[i]);
                
            }
        }

    int ans = minHeap.top();
    return ans;
}



int main() {

    int arr[5] = {7,10,4,20,15};
    int k = 4;

    int ans = kthSmallest(arr, k, 5);
    cout<<k <<"th smallest element is : " << ans <<endl;


    int result = kthLargest_element(arr, k, 5);
    cout<<k <<"th Largest element is : " << result <<endl;

    return 0;
}