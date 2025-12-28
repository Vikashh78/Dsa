#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    //constructor
    Node(int d){
        this-> data = d;
        this-> next = NULL;
    }

    //destructor
    ~Node(){
        int value = this-> data;
        if(this-> next != nullptr){
            delete next;
            next = nullptr;
        }
        cout<<" memory is free for the node with data "<< value <<endl;
    }
};

void insertNode(Node* &tail, int element, int data){

    //if list is empty
    if(tail == nullptr){
        Node* newNode = new Node(data);
        newNode-> next = newNode;
        tail = newNode;
    }
    else{
        //non-empty list, assuming the e;ement is present in the list
        Node* curr = tail;

        while(curr-> data != element){
            curr = curr-> next;
        }

        Node* temp = new Node(data);
        temp-> next = curr-> next;
        curr-> next = temp;
    }
}


void deleteNode(Node* &tail, int value){

    if(tail == nullptr){
        cout<<"List is Empty check data again"<<endl;
        return;
    }
    else{
        
    Node* prev = tail;
    Node* curr = prev->next;

    while(curr-> data != value){
        prev = curr;
        curr = curr->next;
    }
    prev-> next = curr-> next;

    //1 Node Linked List
        if(curr == prev) {
            tail = NULL;
        }

        //>=2 Node linked list
        else if(tail == curr ) {
            tail = prev;
        }

        curr -> next = NULL;
        delete curr;
    }
}


void print(Node* &tail){
    Node* temp = tail;

    //empty-list
    if(tail == nullptr){
        cout<<"List is empty"<<endl;
        return;
    }
    do
    {
        cout<<tail-> data <<" ";
        tail = tail-> next;
    } while (tail != temp);

    cout<<endl;
    
}

int main() {

    Node* tail = nullptr;

    print(tail);

    // insertNode(tail, 2, 3);
    // print(tail);
    // insertNode(tail, 3, 6);
    // print(tail);
    // insertNode(tail, 6, 9);
    // print(tail);
    insertNode(tail, 3, 4);
    print(tail);

    cout<<"Tail "<<tail-> data<<endl;

    deleteNode(tail, 4);
    print(tail);

    cout<<"Tail "<<tail-> data<<endl;


    return 0;
}