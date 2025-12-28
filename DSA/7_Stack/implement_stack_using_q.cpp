#include <iostream>
using namespace std;
#include <deque>  // we are using doubly ended queue to implement stack

class stackUsingQueue {
    private:
        deque<int> q;

        
    public:
    // push function      
    void push(int x) {
        q.push_back(x);
    }
    
    // pop function
    int pop() {
        if(q.empty()) {
            return -1;
        }
        else {
            int x = q.back();
            q.pop_back();
            return x;
        }
    }
    
    // top function
    int top() {
        if(q.empty()) {
            return -1;
        }
        else{
            return q.back();
        }        
    }
     

    // empty function
    bool empty() {
        if(q.empty()) {
            return true;
        }
        else {
            return false;
        }
    }
};

int main() {

    stackUsingQueue s;

    s.push(2);
    s.push(6);

    cout<<"top is "<<s.top()<<endl;

    s.pop();

    cout<<"top is "<<s.top()<<endl;

    s.pop();

    if(s.empty()) {
        cout<<"stack empty"<<endl;
    }
    else {
        cout<<"Not empty"<<endl;
    }

    return 0;
}