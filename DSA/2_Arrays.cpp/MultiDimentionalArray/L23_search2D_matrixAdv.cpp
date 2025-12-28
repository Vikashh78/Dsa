#include <iostream>
using namespace std;
#include <vector>
// This matrix is sorted both row as well as column wise so we can not use the concept of MID,
// The approch is slightly different

bool searchMatrix(vector<vector<int>>& matrix, int target){
    int row = matrix.size();
    int col = matrix[0].size();

    int rowIndex = 0;
    int colIndex = col-1;

    // This element is FIXED in entire process

    while(rowIndex < row && colIndex >= 0){

        int element = matrix[rowIndex][colIndex];

        if(element == target){
            return true;
        }

        else if(element < target){
            rowIndex++;
        }

        else{
            colIndex--;
        }
    }
    return false;
}


int main(){

    vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12,10},{3,6,9,16,22},{10,13,14,17,24}};

    int result = searchMatrix(matrix, 3);

    if(! result){
        cout<<"Element is not present"<< endl;
    }
    else{
        cout<<"Element is present"<< endl;
    }

    return 0;
}