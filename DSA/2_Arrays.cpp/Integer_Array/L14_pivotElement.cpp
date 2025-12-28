#include<iostream>
using namespace std;
/*
int pivotElement(int arr[], int size){
    int start=0, end=size-1;
    while(start < end){      
        int mid = (start + (end-start)/2);
        if(arr[mid] >= arr[0]){
            start = mid+1;
        }
        else{
            end = mid;
        }
    }
    return start;
}*/

int peakElement(int arr[], int size) {
    
    int start = 0, end = size-1;
    while(start < end) {
        int mid = start+ (end-start)/2;

        if(arr[mid] > arr[mid+1]) {
            end = mid;
        }
        else start = mid+1;
    }
    return start;
}

int main(){
    int arr[7]={4,5,7,8,10};

    // int result = pivotElement(arr, 7);
    // cout<<"The index of pivot element is : "<< result<< endl;

    int result = peakElement(arr, 5);
    cout<<"The index of peak element is : "<< result<< endl;

    return 0;
}