#include <iostream>
using namespace std;

bool binarySearch(int matrix[][3], int row, int col, int target){

    int start = 0, end = (row*col)-1;
    
    while(start <= end){

        int mid = start + (end - start)/2;

        int element = matrix[mid/col][mid%col];  //calculating for matrix index

        if(element == target){
            return true;
        }
        else if(element > target){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return 0;
}

int main(){

    int matrix[][3]={{1,2,3},{4,5,6},{7,8,9}};
    int target = 7;

    int result = binarySearch(matrix, 3, 3, target);

    if(result != false){
        cout<<"Target is found in matrix"<<endl;
    }
    else{
        cout<<"Terget is not found in matrix"<<endl;
    }

    return 0;
}