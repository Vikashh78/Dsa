#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* prev;
    Node* next;

    //constructor
    Node(int d){
        this-> data = d;
        this-> prev = nullptr;
        this-> next = nullptr;
    }

    //destructor
    ~Node(){
        if(this-> next != NULL){
            delete next;
            this-> next = NULL;
        }
    }
};

void print(Node* &head){
    Node* temp = head;
    while(temp != nullptr){
        cout<<temp-> data <<" ";
        temp = temp-> next;
    }
    cout<<endl;
}



void insertAtHead(Node* &head, Node* &tail, int data){

    // If list is Empty
    if(head == nullptr){
        Node* node1 = new Node(data);
        head = node1;
        tail = node1;
    }
    else{
        Node* temp = new Node(data);
        temp-> next = head;
        head-> prev = temp;
        head = temp;  //updating head every time
    }
}




void insertAtTail(Node* &head, Node* &tail, int data){
    // Empty list
    if(tail == NULL){
        Node* node1 = new Node(data);
        head = node1;
        tail = node1;
    }
    else{
        Node* temp = new Node(data);
        tail-> next = temp;
        temp-> prev = tail;
        tail = temp;
    }
}


void insertAtIndex(Node* &head, Node* &tail, int data, int position){

    if(position == 1){
        insertAtHead(head, tail, data);
        return;
    }

    int count = 1;
    Node* temp = head;
    while(count < position-1){
        temp = temp-> next;
        count+=1;
    }
    // for last position
    if(temp-> next == nullptr){
        insertAtTail(head, tail, data);
        return;
    }

    //insert at index
    Node* nodeToInsert = new Node(data);

    nodeToInsert-> next = temp-> next;
    temp-> next-> prev = nodeToInsert;
    nodeToInsert-> prev = temp;
    temp-> next = nodeToInsert;

}


void deletion(Node* &head, int position){

     if(position == 1){
        Node* ptr = head;

        ptr-> next-> prev = nullptr;
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
        current-> prev = NULL;
        prev-> next = current-> next;
        current-> next = NULL;
        
        delete current;
    }
}

int main() {

    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head, tail, 5);
    print(head);
    insertAtHead(head, tail, 2);
    print(head);
    insertAtHead(head, tail, 1);
    print(head);
    // cout<<"Head "<<head->data<<endl;
    // cout<<"Tail "<<tail->data<<endl;
    
    
    insertAtTail(head, tail, 9);
    print(head);
    insertAtTail(head, tail, 12);
    print(head);
    insertAtTail(head, tail, 14);
    print(head);
    // cout<<"Head "<<head->data<<endl;
    // cout<<"Tail "<<tail->data<<endl;


    insertAtIndex(head, tail, 10, 1);
    print(head);
    insertAtIndex(head, tail, 18, 8);
    print(head);
    insertAtIndex(head, tail, 11, 6);
    print(head);
    cout<<"Head "<<head->data<<endl;
    cout<<"Tail "<<tail->data<<endl;


    deletion(head, 1);
    print(head);
    deletion(head, 5);
    print(head);
    cout<<"Head "<<head->data<<endl;
    cout<<"Tail "<<tail->data<<endl;


    return 0;
}