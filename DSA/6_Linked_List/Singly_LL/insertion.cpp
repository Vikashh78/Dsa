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

// this->data = data;
// this is a pointer to the current object (the Node being created).
// This line assigns the value of the parameter data to the object's data member variable.

// this->next = NULL;
// It initializes the next pointer to NULL by default.
// This means that the node does not point to any other node initially, making it a standalone node.

};


//inserting data at the begning of the linked list
void insertAtHead(Node* &head, int data){

    //creating new node
    Node* a = new Node(data);
    a -> next = head;
    head = a;

}


// inserting data at the end of the linked list
void insertAtTail(Node* &tail, int data){

    Node* temp = new Node(data);
    tail-> next = temp;
    tail = temp;  
}


//insering at index
void insertAtIndex(Node* &head, Node* &tail, int position, int data){
    
    // For first Position
    if(position == 1){
        insertAtHead(head, data);
        return;
    }

    // For any middle position
    Node* temp = head;
    int count = 1;

    while(count != position-1){
        temp = temp-> next;
        count++;
    }

    // For last Position
    if(temp-> next == NULL){
        insertAtTail(tail, data);
        return;
    }

    Node* nodeToInsert = new Node(data);
    nodeToInsert-> next = temp-> next;
    temp-> next = nodeToInsert;

}


void print(Node* &head){

    //creating a temporary node equal to head
    Node* temp = head;
    while(temp != NULL){
        cout<< temp-> data <<" ";
        temp = temp-> next;
    }
    cout<<endl;
}

int main() {

    Node* node1 = new Node(5);  // `this` points to the object `node1`

    Node* head = node1;
    Node* tail = node1;

    // insertAtHead(head ,10);

    // insertAtHead(head ,20);
    
    // insertAtHead(head ,30);

    // insertAtHead(head ,40);


    insertAtTail(tail, 10);

    insertAtTail(tail, 12);

    insertAtTail(tail, 15);

    insertAtTail(tail, 18);

    print(head);

    insertAtIndex(head, tail, 6, 14);
    print(head);

    cout<<"Head is-> "<<head-> data <<endl;
    cout<<"Tail is-> "<<tail-> data <<endl;

    return 0;
}