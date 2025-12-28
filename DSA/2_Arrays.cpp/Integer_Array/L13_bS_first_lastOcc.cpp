#include<iostream>
using namespace std;

int firstOccur(int arr[], int size, int key){
    int start = 0, end = (size-1), ans = -1 ;
    while(start <= end){
        int mid = start + (end-start)/2;

        if(arr[mid]==key){
            ans = mid;
            end = mid-1;
        }
        else if(key > arr[mid]){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return ans;
}

int lastOccur(int arr[], int size, int key){
    int start = 0, end = (size-1), ans = -1 ;
    while(start <= end){
        int mid = start + (end-start)/2;

        if(arr[mid]==key){
            ans = mid;
            start = mid+1;
        }
        else if(key > arr[mid]){
           start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return ans;
}

int main(){
    int arr[1]={1};
    int key = 0;
    int result1 = firstOccur(arr, 1, 0);
    int result2 = lastOccur(arr, 1, 0);
    cout<<"first occurance of 3 is at index "<< result1  <<endl;;
    cout<<"last occurance of 3 is at index "<<  result2 <<endl;
    if(result1 != -1 && result2!= -1){
    int totalNoOfOccur = (result2 - result1) + 1;
    cout<< "Total no of occcurance of 3 in array is "<< totalNoOfOccur << endl;
    }
    else{
        cout<<"key is not present in the array"<<endl;
    }
    return 0;
}