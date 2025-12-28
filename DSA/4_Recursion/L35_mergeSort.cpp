#include <iostream>
using namespace std;

void merge(int *arr, int start, int end){

    int mid = start+(end-start)/2;

    int len1 = mid - start+1;
    int len2 = end - mid;

    // creating array dynamically in the heap memory-
    int *arr1 = new int[len1];
    int *arr2 = new int[len2];

    //copying the elemnts in the 1st array-
    int mainArrayIndex = start;
    for(int i=0; i<len1; i++){
        arr1[i] = arr[mainArrayIndex++];
    }

    //copying the elements in second array-
    mainArrayIndex = mid+1;
    for(int j=0; j<len2; j++){
        arr2[j] = arr[mainArrayIndex++];
    }





    //merging two sorted arrays-
    int index1 = 0, index2 = 0;
    mainArrayIndex = start;

    while(index1 < len1 && index2 < len2){
        if(arr1[index1] < arr2[index2]){
            arr[mainArrayIndex++] = arr1[index1++];
        }
        else{
            arr[mainArrayIndex++] = arr2[index2++];
        }
    }
    //copying extra elements-
    while(index1 < len1){
        arr[mainArrayIndex++] = arr1[index1++];
    }

    while(index2 < len2){
        arr[mainArrayIndex++] = arr2[index2++];
    }

    //Clearing the heap memory-
    delete []arr1;
    delete []arr2;
    

}

void mergeSort(int *arr, int start, int end){

    //base case- 
    if(start >= end)
    return;

    int mid = start+(end-start)/2;

    //merge left part-
    mergeSort(arr, start, mid);

    //merge right part-
    mergeSort(arr, mid+1, end);

    //calling merge function-
    merge(arr, start, end);


}

int main(){

    int arr[] = {88,0,32,44,5,21,45,89,104,453};
    int size = sizeof (arr)/sizeof (arr[0]);

    mergeSort(arr, 0, size-1);

    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;



    return 0;
}