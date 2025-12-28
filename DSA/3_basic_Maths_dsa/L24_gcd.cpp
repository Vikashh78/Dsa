#include <iostream>
using namespace std;

int gcd(int a, int b){

    if(a==0 || b==0){
        return 0;
    }

    while(a != b){

        if(a > b){
            a = a-b;
        }
        else{
            b = b-a;
        }
    }
    return b; // return either 'a' or 'b'
    }

int main(){

    cout<<"Enter two number : ";
    int a, b;
    cin>>a >>b;

    int result = gcd(a, b);
    cout<<"GCD of "<<a <<" and "<<b <<" is : "<<result <<endl;

    return 0;
}
