#include<iostream>
#include<climits>
using namespace std;

// Taking array input
void inArray(int arr[], int size){
    for(int j=0; j<size; j++){
        cin>> arr[j] ;
    }
}

int getMax(int arr[], int size){
    int max = INT_MIN;             // initially max me sabse small element rakha h.
    for(int i=0; i<size; i++){

        // maxi = max(maxi, num[i]);   -- ye ek inbuilt function hai for the same

        if(arr[i]>max){
            max = arr[i];      // after comparision with all elements max me sabse bada element daal diya.
        }
    }
    return max;
}

int getMin(int arr[], int size){
    int min = INT_MAX;              // vice versa here
    for(int i=0; i<size; i++){

         //mini = min(mini, num[i]);   //-- ye ek inbuilt function hai for the same

        if(arr[i]<min){
            min = arr[i];
        }
    }
    return min;
}

int main(){
    int arr[]={};
    int size;
    cout<< "Enter size of array : ";
    cin>> size;
    cout<< "Enter elements of array : ";
    inArray(arr, size);

    cout << "Maximum element is " << getMax(arr, size) << endl;
    cout << "Minimum element is " << getMin(arr, size) << endl;
    return 0;
}