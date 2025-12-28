#include <iostream>
using namespace std;
#include <vector>

void sort012(int arr[], int size) {
    int i = 0, j = 0, k = size - 1;

    while (j <= k) {
        if (arr[j] == 0) {
            swap(arr[i], arr[j]);
            i++;
            j++;

        } else if (arr[j] == 1) {
            j++;

        } else { // arr[j] == 2
            swap(arr[j], arr[k]);
            k--;
        }
    }
}

void printArray(int arr[], int size){
    for(int i=0; i<size-1; i++){ 
        cout<<arr[i]<<" ";
    }
}

int main(){

    int arr[7]={0,1,1,2,1,2,2};
    sort012(arr, 7);
    printArray(arr, 7);
    cout<<arr;

    return 0;
}