#include<iostream>
using namespace std;

int uniqueElement(int *arr, int size){
    int ans = 0;
    for(int i=0; i<7; i++){
        ans = ans ^ arr[i];
    }
    return ans;
}

int main(){
    int arr[]={2,5,7,6,5,7,6};
    int size = sizeof(arr)/sizeof(arr[0]);
    int result = uniqueElement(arr, size);
    cout<< "unique element of array is : "<< result <<endl;

    return 0;
}