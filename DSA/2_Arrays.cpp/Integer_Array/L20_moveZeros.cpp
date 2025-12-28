#include<iostream>
#include<vector>
using namespace std;

vector<int> moveZeros(vector<int> arr){
    int i = 0;
    for(int j=0; j<arr.size(); j++){
        if(arr[j] != 0){
            swap(arr[i], arr[j]);
            i++;
        }
    }
    return arr;
}

void printArray(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    vector<int> arr;

    arr.push_back(0);
    arr.push_back(0);
    arr.push_back(0);
    arr.push_back(0);
    arr.push_back(12);
    arr.push_back(0);
    arr.push_back(23);

    printArray(moveZeros(arr));


    return 0;
}