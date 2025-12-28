#include <iostream>
using namespace std;

int fibb(int n){

    // Base case
    if(n == 0)
    return 0;

    if(n == 1)
    return 1; 

    return fibb(n-1) + fibb(n-2); 

}

int main(){

    int n;
    cout<<"Enter the terms of the fibonacci series : ";
    cin>> n;

    int ans = fibb(n);

    cout<< n <<"th term is "<< ans<< endl;

    return 0;
}