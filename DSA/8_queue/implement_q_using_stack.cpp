/*To implement a queue using two stacks in C++, we can use two stacks to mimic the enqueue and dequeue operations of a queue. 
The idea is to use one stack for incoming elements (enqueue) and another stack for outgoing elements (dequeue). Here’s the step-by-step
logic:
Enqueue Operation: To enqueue an element, simply push the element onto the first stack (let's call it stack1).
Dequeue Operation: To dequeue an element, check if the second stack (let's call it stack2) is empty:

If stack2 is not empty, pop the top element from stack2.
If stack2 is empty, transfer all elements from stack1 to stack2 (by popping from stack1 and pushing to stack2), and then pop the top 
element from stack2.*/

#include <iostream>
using namespace std;
#include <stack>

class queueUsingStack {

    private:
    stack<int> s1;  // used for enqueue operation
    stack<int> s2;  // used for dequeue operation 

    public:

    // push function
    void push(int x) {
        s1.push(x);
    }

    // pop function
    int pop() {
        // if both stacks are empty then queue is empty
        if(s1.empty() && s2.empty()) {
            return -1;
        }

        if(s2.empty()) {
            // pop the elements from s1 and push into s2
            while(! s1.empty()) {
                int temp = s1.top();
                s1.pop();

                s2.push(temp);
            }
        }
        // Pop the top element from stack2 (dequeue operation)
        int x = s2.top();
        s2.pop();
        return x;
    }

    // empty function
    bool isEmpty() {
        if(s1.empty() && s2.empty()) {
            return true;
        }
        else{
            return false;
        }
    }

    // peek function
    int peek() {
        if(s1.empty() && s2.empty()) {
            return -1;
        }

        if(s2.empty()) {
            while(! s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        return s2.top(); 
    }
};

int main() {

    queueUsingStack q;

    q.push(2);
    q.push(5);

    cout<<"front is "<<q.peek()<<endl;

    q.pop();
    //q.pop();

    int x = q.peek();     // result the front element of queue
    cout<<"front is "<<x <<endl;

    if(q.isEmpty()) {
        cout<<"Queue is empty"<<endl;
    }
    else {
        cout<<"q is not empty"<<endl;
    }

    return 0;
}