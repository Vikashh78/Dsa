#include <iostream>
using namespace std;

class A{

    public:
    int add(int a, int b){
        return a+b;
    }

    int add(int a, int b, int c=0){
        return a+b+c;
    }

    double add(double a, double b){
        return a+b;
    }

};

int main() {

    A obj1;
    cout<<obj1.add(10.11, 20.0)<<endl;

    cout<<obj1.add(1, 33, 2);
    
    return 0;
}