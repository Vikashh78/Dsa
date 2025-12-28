#include <iostream>
using namespace std;
#include <vector>

//A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same elements.

bool isToeplitzMatrix(vector<vector<int>>& matrix){

    int row = matrix.size(), col = matrix[0].size();

        for(int i=0; i<row-1; i++){
            for(int j=0; j<col-1; j++){
                if(matrix[i][j] != matrix[i+1][j+1]){
                    return false;
                }
            }
        } 
    return true;
}

int main(){

    vector<vector<int>> matrix = {{1,2,3,4},{5,1,2,3},{9,5,1,2}};
    //vector<vector<int>> matrix = {{1,2},{2,2}};

    bool result = isToeplitzMatrix(matrix);

    result ? cout<<"yes toeplitz" : cout<<"not toeplitz"; 
    

    return 0;
}