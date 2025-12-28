#include<iostream>
using namespace std;

void insertionSort(int arr[], int size){
    for(int i=1; i<size; i++){   // this loop for showing rounds upto (size-1)
        int temp = arr[i], j=i-1;
        for( ; j>=0; j--){
            if(arr[j] > temp){
                // shift karna hai 
                arr[j+1] = arr[j];
            }
            else  // stop here and come out from the loop
            break;
        }
        arr[j+1] = temp;
    }
}

void printArray(int arr[], int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[7]={1,7,4,8,0,0,0};
    cout<<"Array after sorting : ";
    insertionSort(arr, 7);
    printArray(arr, 7);

    return 0;
}