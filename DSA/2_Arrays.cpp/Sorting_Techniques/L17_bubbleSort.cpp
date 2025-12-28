#include<iostream>
using namespace std;

void bubbleSort(int arr[], int size){
    for(int i=0; i<size-1; i++){
        bool swapped = false;
        for(int j=0; j<size-1-i; j++){
            if(arr[j] > arr[j+1])
            swap(arr[j], arr[j+1]);
            swapped = true;
        }
         if(swapped == false) // for already sort caseS
            break;
    }
    return;
}

void printArray(int arr[], int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[6]={6,2,8,4,10,9};
    cout<<"Arrya after sorting : ";
    bubbleSort(arr, 6);
    printArray(arr, 6);

    return 0;
}