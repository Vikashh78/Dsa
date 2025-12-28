#include<iostream>
using namespace std;

int arraySum(int arr[], int size){
    int sum = 0;
    for(int i=0; i<size; i++){
         sum = sum + arr[i];   
    }
    return sum;
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
 
    cout<<"The sum of elements of array is : " << arraySum(arr, size) <<endl;

    return 0;
}