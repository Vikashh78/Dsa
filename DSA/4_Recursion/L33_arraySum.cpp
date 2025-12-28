#include <iostream>
using namespace std;

int arraySum(int *arr, int size){

    //base case-
    if(size == 0)
    return 0;

    int sum = arr[0] + arraySum(arr+1, size-1);

    return sum;
   
}

int main(){

    int array[]={1,2,3,4,5};
    int size = sizeof(array)/sizeof(array[0]);

    int result = arraySum(array, size);

    cout<<"The sum of the elements are : "<< result<< endl;

    return 0;
}