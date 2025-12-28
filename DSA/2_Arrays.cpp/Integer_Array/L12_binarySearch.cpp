#include<iostream>
using namespace std;

int binarySearch(int arr[], int size, int key){
    int start=0, end=(size-1);
    
    while(start <= end){
        int mid = start+(end-start)/2;   // To avoid the higher value rather then int

        if(arr[mid]==key){
            return mid;
        }
        else if(key > arr[mid]){
            start=mid+1;
        }
         else{
            end=mid-1;
        }
    }
    return -1;
}

void arrayIn(int arr[], int size){
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }
}

int main(){
    int arr[]={};
    int size, key;;
    cout<<"Enter the size of array : ";
    cin>> size;
    cout<<"Enter the elements of array : ";
    arrayIn(arr, size);
    cout<<"Enter the key value : ";
    cin>>key;
    int result = binarySearch(arr, size, key);
    cout<< "The element "<< key <<" is found at index : "<< result <<endl;
    
    return 0;
}