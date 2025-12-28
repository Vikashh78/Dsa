#include<iostream>
using namespace std;

//time comlexity of O(log n)

void arrayIn(int arr[], int size){
    for(int i=0; i<size; i++){
        cin>> arr[i];
    }
}

int peakElement(int arr[], int size){
    int start = 0, end = size-1;
    while(start < end){
        int mid = start + (end - start)/2;
        if(arr[mid] < arr[mid+1]){
            start = mid+1; 
            return start;
        }
        else{
            end = mid;
        }
    }
}

int main(){
    int arr[]={};
    int size;
    cout<<"Enter the size of array : ";
    cin>> size;
    cout<<"Enter the elements of array : ";
    arrayIn(arr, size);
    cout<<"Index of peak element in array is "<< peakElement(arr, size) <<endl;

    return 0;
}