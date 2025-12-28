#include<iostream>
using namespace std;

void rotateArray(int arr[], int size, int k){
    int temp[size];
    for(int i=0; i<size; i++){
        temp[(i+k) % size] = arr[i];
    }

// There is no use of nested loop here
    for(int i=0; i<size; i++){    
        arr[i] = temp[i];
    }
}

void printArray(int arr[], int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[]={2,4,5,3,6,1,8};
    int size = sizeof(arr)/sizeof(arr[0]);
    int key = 2;

    rotateArray(arr, size, key);
    printArray(arr, size);

    return 0;
}