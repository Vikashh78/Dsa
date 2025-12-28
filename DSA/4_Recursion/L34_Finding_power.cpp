#include <iostream>
using namespace std;
#include <limits.h>

int findPower(double a, int b){

    //Handle the special case when n is INT_MIN
    if(b == INT_MIN){
        return 1/(findPower(b, INT_MAX) * b); // Avoid overflow
    }

    //base case-
    if(b == 0)
    return 1;

    if(b == 1)
    return a;

    if(b < 0){
        return 1 / findPower(a, -b); // Change to positive for recursion
    }

    //Recursive call
    double ans = findPower(a, b/2);

    if(b%2 == 0){
        return ans * ans;
    }
    else{  //b is odd
        return a * ans * ans;
    }
}

int main(){

    double a;
    int b;
    cout<<"Enter the number and its power : ";
    cin>> a>> b;

    double result = findPower(a, b);

    cout<< "Ans is : "<< result <<endl;

    return 0;
}