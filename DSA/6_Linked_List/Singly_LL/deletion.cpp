#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int data){
        this-> data = data;
        this-> next = NULL;
    }

    //destructor
    ~Node(){
        int value = this-> data;
        //memory free
        if(this-> next != NULL){
            delete next;
            this-> next = NULL;
        }
        cout<<"memory is free for the node with data "<<value <<endl;
    }
};

void insertAtHead(Node* &head, int data){

    Node* temp = new Node(data);
    temp-> next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int data) {

    Node* temp = new Node(data);
    tail-> next = temp;
    tail = temp;

}

void insertAtIndex(Node* &head, Node* &tail, int data, int position){

    // if position is 1
    if(position == 1){
        insertAtHead(head, data);
        return;
    }

    Node* ptr = head;
    int count = 1;
    while(count != position-1){
        ptr = ptr-> next;
        count+=1;
    }

    //insert at last
    if(ptr-> next == NULL){
        insertAtTail(tail, data);
        return;
    }

    Node* newNode = new Node(data);
    newNode-> next = ptr->next;
    ptr-> next = newNode;
   
}


// Code for deletion start from here

void deletion(Node* &head, int position) {

    if(position == 1){
        Node* ptr = head;
        head = head-> next;
        ptr-> next = NULL;
        delete ptr;
    }

    else{
        //deleting any middle or last node
        Node * current = head;
        Node* prev = NULL;
        
        int count = 1;
        while(count < position){
            prev = current;
            current = current-> next;
            count+=1;
        }
        prev-> next = current-> next;
        current-> next = NULL;
        delete current;
    }

}




void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp-> data <<" "<<endl;
        temp = temp-> next;
    }
    cout<<endl;
}

int main() {

    Node* node1 = new Node(10);
    
    Node* head = node1;
    Node* tail = node1;

    //inserting at head
    insertAtHead(head, 20);
    insertAtHead(head, 30);
    insertAtHead(head, 35);
    //print(head);

    insertAtTail(tail, 18);
    insertAtTail(tail, 12);
    //print(head);

    insertAtIndex(head, tail, 14, 5);
    print(head);

    //deletion calling
    deletion(head, 6);
    print(head);

    cout<<"Head is -> "<<head-> data<<endl;
    cout<<"Tail is -> "<<tail-> data<<endl;

    return 0;
}