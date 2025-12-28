#include<iostream>
using namespace std;

void printArray(int arr[], int size){
    int i=0;
    while(i<size){
        cout<<arr[i]<<" ";
        i++;
    }
}

void mergeArray(int arr1[], int n, int arr2[], int m, int arr3[]){
    int i=0, j=0, k=0;

    while(i<n && j<m){
        if(arr1[i] < arr2[j]){
            arr3[k] = arr1[i];
            i++;
            k++;
        }
        else{
            arr3[k] = arr2[j];
            j++;
            k++;        
        }
    }
    // copying remaining elements of arr1 into arr3
    while(i<n){
        arr3[k] = arr1[i];
        i++;
        k++;
    }
    // copying remaining elements of arr2 inti arr3 
    while(j<m){
        arr3[k] = arr2[j];
        j++;
        k++;
    }
    return ;
}

//sorting
void insertionSort(int arr1[], int size){
    for(int i=1; i<size; i++){
        int temp=arr1[i], j;
        for(j=i-1; j>=0; j--){
            if(temp < arr1[j]){
                arr1[j+1]=arr1[j];
            }
            else{
                break;
            }
        }
        arr1[j+1]=temp;
    }
}

int main(){
    
    int arr1[7]={1,3,5,7,0,0,0};
    int arr2[3]={2,4,6};
    int arr3[10]={0};
    insertionSort(arr1, 7);
    mergeArray(arr1, 7, arr2, 3, arr3);
    cout<<"Array after merging : ";
    printArray(arr3, 10);

    return 0;
}