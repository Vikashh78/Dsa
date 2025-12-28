#include <iostream>
using namespace std;

void spiralPrint(int arr[][3], int row, int col){

    int count = 0;
    int total = (row)*col;

    int startingRow = 0;
    int startingCol = 0;
    int endingRow = row-1;
    int endingCol = col-1;

    while(count < total){

        //printing starting row-
        for(int index = startingCol; count < total  && index <= endingCol; index++){
            cout<< arr[startingRow][index]<<" ";  //here column is indicated by index
            count++;
        }
        startingRow++;

        //printing ending column-
        for(int index = startingRow; count < total  && index <= endingRow; index++){
            cout<< arr[index][endingCol]<<" ";  //here row is indicated by index
            count++;
        }
        endingCol--;

        //printing ending row-
        for(int index = endingCol; count < total  && index >= startingCol; index--){
            cout<< arr[endingRow][index]<<" ";
            count++;
        }
        endingRow--;

        //printing starting col-
        for(int index = endingRow; count < total  && index >= startingRow; index--){
            cout<< arr[index][startingCol]<<" ";
            count++;
        }
        startingCol++;
    }

}

int main(){
 
    int arr[][3]={1,2,3,4,5,6,7,8,9};

    cout<<"Printing matrix in spiral way ->"<<endl;
    spiralPrint(arr, 3, 3);
        
    return 0;
}