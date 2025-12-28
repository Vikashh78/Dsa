#include <iostream>
using namespace std;
//implementation of stack using array (without STL)

class Stack {

    //properties
    public:
    int *arr;
    int top;
    int size;

    //behaviour
    Stack(int size) {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    
    //method for push
    void push(int element) {
        if(size-top > 1){  // if space is available or not
            arr[top] = element;
            top++;
        }
        else {
            cout<<"stack overflow"<<endl;
        }
    }

    //method for pop
    void pop() {
        if(top >= 0) {
            top--;
        }
        else {
            cout<<"stack underflow"<<endl;
        }
    }

    //method for peek
    int peek() {
        if(top >= 0) {
            return arr[top];
        }
        else {
            cout<<"stack is empty"<<endl;
            return -1;
        }
    } 

    //method for empty
    bool empty() {
        if(top == -1) {
            return true;
        }
        else {
            return false;
        }
    }

};

int main() {

    Stack st(4);

    st.push(5);
    st.push(13);
    st.push(11);
    st.push(2);

    st.pop();

    int res = st.peek();
    cout<<"top element is "<<res <<endl;
    

    if(!st.empty()){
        cout<<"stack is not empty"<<endl;
    }
    else {
        cout<<"stack is empty"<<endl;
    }

    
    return 0;
}