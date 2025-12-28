#include<iostream>
using namespace std;

//Taking array elements as input--

void inArray(int arr[], int size){
    for(int j=0; j<size; j++){
        cin>> arr[j] ;
    }
}
//Function to print array --

void printArray(int arr[], int size){
    for(int i=0; i<size; i++){
        cout<< arr[i] << " ";
    }
}

int main(){
   int arr[100] = {0}; // "Always make sure that you are not going to pass a variable array size , it should not be (arr[size])"
   int size;
   cout<<"Enter the size of array : "; 
   cin>> size;
   cout<<"Enter the elements of array : " ;
   inArray(arr, size);

   cout<<"Priting tha array "<< endl;
   printArray(arr, size);

    return 0;
}