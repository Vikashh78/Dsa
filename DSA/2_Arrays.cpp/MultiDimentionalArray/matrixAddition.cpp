#include<iostream>
using namespace std;

//Taking 2D rry input-
void matrixIn(int arr[3][3], int size){
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            cin>>arr[i][j];
        }
    }
}

void matrixAdd(int arr1[3][3], int arr2[3][3], int arr3[3][3], int size){
    for(int k=0; k<size; k++){
        for(int t=0; t<size; t++){
        arr3[k][t]=arr1[k][t] + arr2[k][t];
        }
    }
}

//printing 2D array as output-
void printMatrix(int arr3[3][3], int size){
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            cout<<arr3[i][j]<<" ";
        }
        cout<<endl;
    }

}

int main(){

    int arr1[3][3]={};
    int arr2[3][3]={};
    int arr3[3][3]={};
    cout<<"Enter first array : "<<endl;
    matrixIn(arr1, 3);

    cout<<"Enter second array : "<<endl;
    matrixIn(arr2, 3);

    cout<<"After addition of matrix is : "<<endl;
    matrixAdd(arr1, arr2, arr3, 3);
    printMatrix(arr3, 3);


    return 0;
}