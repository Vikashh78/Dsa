#include<iostream>
using namespace std;

int linearSearch(int arr[], int size, int key){
    for(int i=0; i<size; i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}

void inArray(int arr[], int size){
    for(int j=0; j<size; j++){
        cin>> arr[j] ;
    }
}

int main(){
     int arr[]={};
     int size ;
    cout<< "Enter the size of array : ";
    cin>> size;
    cout<< "Enter the array elements : ";
    inArray(arr, size);
    int key;
    cout<<"Enter the key value in array : ";
    cin>> key;

    int result = linearSearch(arr, size, key);
    if(result != -1){
        cout<<"key "<< key <<" is found at index : "<< result <<endl; 
    }
    else{
        cout<<"The key is not found in array "<<endl;
    }

    return 0;
}