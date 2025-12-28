// Question-- if the given array is Sorted as well as Rotated the Return True

#include<iostream>
using namespace std;

bool sortedRotated(int arr[], int size){
    int count = 0;
    for(int i=1; i<size; i++){
        if(arr[i-1] > arr[i])
        count++;
    }
    
    if(arr[size-1] > arr[0]){
      count++;
    }
    
    return count<=1;
}


int main(){

    //Test case
    int arr[]={3,4,5,6,1,2};
    // int arr[]={3,4,5,6,1,20};

    int size = sizeof(arr)/sizeof(arr[0]);

    cout<< sortedRotated(arr, size) <<endl;

    return 0;
}