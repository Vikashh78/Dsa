#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int x) {
        this->data = x;
        this->next = NULL;
    }
};

// class to implement stack using linked list
class Stack {

   private:
    Node * top;

    public:
    //constructor
    Stack() { 
    Node* top = nullptr;
    }

    //destructor
    ~Stack() {
        while(top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    //push function
    void push(int x) {
        Node* newNode = new Node(x);
        newNode-> next = top; // Point new node to the current top
        top = newNode;
        cout<<"Element pushes to stack"<<endl;
    }

    void pop() {
        if(isEmpty()) {
            cout<<"stack underflow"<<endl;
        }
        else {
            Node* temp = top;
            top = top->next;
            cout<<"popped from stack"<<endl;
            delete temp;
        }
    }

    bool isEmpty() {
        if(top == nullptr)
        return top;
    }

    // Function to display the stack elements
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->data <<endl;
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {

   Stack st;

   st.push(65);
   st.push(4);
   st.push(75);

   st.display();

    return 0;
}