#include <iostream>
using namespace std;

int main(){

    //creating a 2D array dynamically in Heap memory
    int row, col;
    cout<<"Enter no of rows and columns : ";
    cin >> row >> col;

    int **arr = new int* [row];
    for(int i=0; i<row; i++){
        arr[i] = new int[col];
    }

    //taking input 
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin>> arr[i][j];
        }
    }cout<< endl;

    //printing output-
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<< endl;
    }

    //clearing the memory-
    for(int i=0; i<row; i++){
        delete[] arr[i];
    }
    delete [] arr;

    return 0;
}