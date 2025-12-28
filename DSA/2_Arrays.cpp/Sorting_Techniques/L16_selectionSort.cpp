#include<iostream>
using namespace std;

void selectionSort(int arr[], int size){
    for(int i=0; i<size; i++){
        int minIndex = i;
        for(int j=i+1; j<size; j++){
            if(arr[minIndex] > arr[j])
                minIndex = j;
            }
             swap(arr[minIndex], arr[i]);
       }
    return;
}

void arrayIn(int arr[], int size){
    for(int k=0; k<size; k++){
        cin>>arr[k];
    }
}

void printArray(int arr[], int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[]={};
    int size;
    cout<<"Ente the size of array : ";
    cin>>size;
    cout<<"Enter elements of array : ";
    arrayIn(arr, size);
    cout<<endl;
    cout<<"After sorting the array : ";
    selectionSort(arr, size);
    printArray(arr, size);

    return 0;
}
