#include<iostream>
using namespace std;

bool searchIndex(int arr[][3], int n, int m, int key){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(arr[i][j] == key){
               
                return true;
            }
        }
    }
     return false;
 }

int main(){

    int arr[][3]={1,2,3,4,5,6,7,8,9,10,0,0};
    int key = 6;
    bool ans = searchIndex(arr, 4, 3, key);
    if(ans){
        cout<<key<<" is found in the array "<<endl;
    }
    else{
        cout<<key<<" is not found in the array "<<endl; 
    }

    return 0;
}