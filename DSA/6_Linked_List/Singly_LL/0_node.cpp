#include <iostream>
using namespace std;

class Node { //creating a node
    public:
    int data;
    Node* next;

    //constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }


};

int main() {
    
    //creating an object for Node
    Node* a = new Node(10);

    cout<<a->data<<endl;
    cout<<a->next<<endl;

    return 0;
}