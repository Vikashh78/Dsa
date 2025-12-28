#include <iostream>
using namespace std;
#include <vector>

vector<int> solve(vector<int>& arr) {

    vector<int> ans;
    int size = arr.size();

    for(int i=0; i<size-1; i++) {
        int count = i;
        for(int j=i+1; j<size; j++) {
            if(arr[i] > arr[j]) {
                count++;
            }
            else {
                break;
            }
        }
        if(count == size-1) {
            ans.push_back(arr[i]);
        }
    }
    ans.push_back(arr[size-1]);

    return ans;
}


int main() {

    vector<int> arr = {16,17,5,3,2,4};

    vector<int> result = solve(arr);
    for(int i=0; i<result.size(); i++) {
        cout<<result[i]<<" ";
    }

    return 0;
}