#include <iostream>
using namespace std;
#include <time.h>

int binarySearch(int arr[], int start, int end, int key){

    //base case-
    if(start > end){
        return -1;
    }

    int mid = start + (end - start)/2;

    //base case-
    if(arr[mid] == key)
    return mid;

    if(key > arr[mid]){
        return binarySearch(arr, mid+1, end, key);
    }

    else{
        return binarySearch(arr, start, mid-1, key);
    }

}

int main(){

    int arr[]={1,2,3,4,5,6,7,8,9};

    int key = 7;

    int size = sizeof(arr)/sizeof(arr[0]);

    clock_t start, stop;
    double time_taken;

    start = clock();
    int result = binarySearch(arr, 0, size-1, key);
    stop = clock();

    cout<<"Element "<< key<<" found at "<<result <<" index "<<endl;

    time_taken = double(stop - start) / CLOCKS_PER_SEC;

    cout<<"Time taken to execute the code is "<<time_taken <<" seconds"<<endl;


    return 0;
}