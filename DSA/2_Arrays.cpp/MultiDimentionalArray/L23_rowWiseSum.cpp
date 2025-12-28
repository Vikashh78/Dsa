// you are given with an array you have to return row wise sum--

#include<iostream>
using namespace std;
#include<limits.h>

void rowWiseSum(int arr[][3], int row, int col){
    
    for(int row=0; row<3; row++){
        int sum = 0;
        for(int col=0; col<3; col++){
            sum = sum + arr[row][col];
        }
        cout<<"Row wise sum is : ";
        cout<<sum <<endl;
    }
    return;
}

// Function to return largest sum and its index number-

int largestSum(int arr[][3], int row, int col){

    int max = INT_MIN;
    int index = -1;

    for(int row=0; row<3; row++){
        int sum = 0;
        for(int col=0; col<3; col++){
            sum = sum + arr[row][col];
        }
        if(sum > max){
            max = sum;
           index = row;
        }
        
    
    }
   cout<<"Maximum sum is : " <<max <<endl;
   return index;
}

int main(){

    int arr[][3]={20,4,11,22,12,10,7,8,6};
    rowWiseSum(arr, 3, 3);
    cout<<endl;

    int result = largestSum(arr, 3, 3);
    cout<<"Index of maximum sum is at : "<<result<<" row"<<endl;
    return 0;
}