#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size){

    //base case-
    if(size == 0)
    return;

    //solving one time-
    for(int i=0; i<size-1; i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i], arr[i+1]);
        }
    }

    //Recursive call-
    bubbleSort(arr, size-1);
}

int main(){

    int arr[] = {2,0,8,3,5,6};

    bubbleSort(arr, 6);

    int i = 0;
    while(i < 6){
        cout<<arr[i]<<" ";
        i++;
    }
   cout<<endl;

    return 0;
}