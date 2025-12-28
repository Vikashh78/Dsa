#include <iostream>
using namespace std;

int partition(int arr[], int start, int end){

    int pivot = arr[start]; 
    int count = 0;

    for(int i=start+1; i<=end; i++){
        if(arr[i] <= pivot){
            count++;
        }
    }
    //place pivot at right position
    int pivotIndex = start+count;
    swap(arr[start], arr[pivotIndex]);


    //left and right wala part smbhal lete h 
    int i = start; 
    int j = end;
    while(i < pivotIndex && j > pivotIndex){

        while(arr[i] <= pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        if(i < pivotIndex && j > pivotIndex){
            swap(arr[i++], arr[j--]);
        }
    }
    
    return pivotIndex;
}

void quickSort(int arr[], int start, int end){

    //baseCase-
    if(start >= end)
    return;

    int p = partition(arr, start, end);

    //sorting left part-
    quickSort(arr, start, p-1);

    //sorting right part-
    quickSort(arr, p+1, end);


}

int main(){

    int arr[] = {88,0,32,44,5,21,45,89,104,453};
    int size = sizeof (arr)/sizeof (arr[0]);

    quickSort(arr, 0, size-1);

    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;



    return 0;
}