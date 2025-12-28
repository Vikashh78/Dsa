#include <iostream>
using namespace std;

int factorial(int n){
    //base case
    if(n == 0)
        return 1;

    //cout<<n<<endl;

    //recursive relation
    int smallerProblem = factorial(n-1);
    int biggerProblem = n * smallerProblem;

    return biggerProblem;

    // OR
    //return n * factorial(n-1);
}

int main(){

    int n;
    cout<<"Enter a number : ";
    cin>> n;

    int result = factorial(n);
    cout<<"factorial of "<<n <<" is : "<<result <<endl;

    return 0;
}