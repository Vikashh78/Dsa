#include <iostream>
using namespace std;

class abstraction{
    private:
    int a;
    int b;

        public:
        void setValue(int x, int y){
            a = x;
            b = y;
        }
    void display(){ //hidden from user
        cout<< "a = "<<a <<endl;
        cout<< "b = "<<b <<endl; 
    }
};

int main() {

    abstraction obj;
    obj.setValue(10, 20);

    obj.display();
    
    return 0;
}