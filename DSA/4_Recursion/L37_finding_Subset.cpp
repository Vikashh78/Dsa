#include <iostream>
using namespace std;
#include <vector>

void subset(vector<vector<int>>& ans, vector<int>& arr, vector<int> output, int index){
    //base case-
    if(index >= arr.size()){
        ans.push_back(output);
        return;
    }

    //exclude case-
    subset(ans, arr, output, index+1);

    //include case-
    output.push_back(arr[index]);
    subset(ans, arr, output, index+1);

}

void print(vector<vector<int>>& ans) {
    for(int col=0; col<ans.size(); col++) {
        cout << "[ "; 
        for(int row=0; row<ans[col].size(); row++) {
            cout << ans[col][row] << " "; 
        }
        cout << "]" << endl; 
    }
}


int main(){

    vector<int> arr = {1,2,3};

    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    subset(ans, arr, output, index);

    print(ans);
    

    return 0;
}