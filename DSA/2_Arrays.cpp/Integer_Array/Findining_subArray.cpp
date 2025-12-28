#include <iostream>
using namespace std;
#include <vector>

void subArray(vector<int> arr){

    for(int i=0; i<arr.size(); i++){
        for(int j=i; j<arr.size(); j++){
            cout<<"[ ";
            for(int k=i; k<=j; k++){
                cout<<arr[k]<<" ";
            }
            cout<<"]" <<endl;
        }
    }
}

int main(){

    vector<int> arr;

    arr={1,2,3};

    subArray(arr);

    return 0;
}