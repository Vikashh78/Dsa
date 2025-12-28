#include<iostream>
using namespace std;

//Function to reverse array both odd and even array

// void swapArray(int arr[], int size){
//     int start = 0, end = size-1, temp;
//      while(start <= end){
//         // temp = arr[start];
//         // arr[start] = arr[end];
//         // arr[end] = temp;

//          swap(arr[start], arr[end]);  // method to swap 
//         start+=1;  
//         end-=1;   // (start+=2 OR end-=2) condition to reverse altenate elements
//      }
//      return;
// }

//function to swap alternate elements --

void swapAlternate(int arr[], int size){
    for(int i=0; i<size; i++){
        if(i+1 < size){
            swap(arr[i], arr[i++]);
        }
    }
}

void printArray(int arr[], int size){
    for(int j=0; j<size; j++){
        cout<< arr[j] << " ";
    }
}

void arrayIn(int arr[], int size){
    for(int i=0; i<size; i++){
        cin>> arr[i];
    }
}

int main()      
{
    int arr[]={};
    int size;
    cout<<"Enter the size of the array : ";
    cin>> size;
    cout<< "Enter the elements of the array : ";
    arrayIn(arr, size);
    //swapArray(arr, size);
    swapAlternate(arr, size);
    cout<<"Array after revesing the elements : ";
    printArray(arr, size);

    return 0;
}