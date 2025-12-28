#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printMatrix(vector<vector<int>>& matrix){
    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix.size(); j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

void rotate(vector<vector<int>>& matrix) {
        //transpose of matrix
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<i; j++){

                // because it reduce the Run time of program
                int temp = matrix[i][j];   
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
        }
        // column exchange
         for (int i = 0; i < matrix.size(); i++) {
        reverse(matrix[i].begin(), matrix[i].end());
        }
        
}

int main(){

    vector<vector<int>> matrix = {{1,2,3}
                                ,{4,5,6}
                                ,{7,8,9}};

    cout<<"Matrix before rotation ->"<<endl;
    printMatrix(matrix);                            

    rotate(matrix);
    cout<<"Matrix after rotation ->"<<endl;
    printMatrix(matrix);

    return 0;
}