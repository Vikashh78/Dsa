#include <iostream>
using namespace std;

void print(int arr[][3], int row, int col){

    for(int i=0; i<col; i++){   // will print column wise data
        for(int j=0; j<row; j++){
            cout<<arr[j][i]<<" ";
        } 
        cout<<endl; 
    }
}

void waveLikePrint(int arr[][3], int rows, int colm){

    for(int col=0; col<colm; col++){

        int row = rows-1;
        if(col & 1){
            for(row ; row>=0; row--){
                cout<<arr[row][col]<<" ";
            }
            cout<<endl;
        }
        else{
            for(int row=0; row<rows; row++){
                cout<<arr[row][col]<<" ";
            }
            cout<<endl;
        }
    }
}

int main(){

    int arr[][3]={1,2,3,4,5,6,7,8,9,10,11,12};

    print(arr, 4, 3);
    cout<<"\n"<<endl;

    waveLikePrint(arr, 4, 3);
    

}