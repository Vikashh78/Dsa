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
};

void insertAtHead(Node* &head, int data){

    //creating new node
    Node* a = new Node(data);
    a -> next = head;
    head = a;

}


//function to reverese LinkedList Approach:1
void reverseNode(Node* &head){

    if(head == nullptr || head-> next == nullptr) return;

    Node* prev = nullptr;     
    Node* forward = nullptr; 
    Node* curr = head;       

    while (curr != nullptr) {
        forward = curr->next;    
        curr->next = prev;       
        prev = curr;             
        curr = forward;          
    }
    head = prev;

}



// Recursive solution to reverse
void reverse(Node* &head, Node* curr, Node* prev){

    //base case
    if(curr == NULL){
        head = prev;
        return;
    }

    Node* forward = curr-> next;
    //recursive call
    reverse(head, forward, curr);
    curr-> next = prev;

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

    Node* head = nullptr;

    insertAtHead(head, 50);
    insertAtHead(head, 40);
    insertAtHead(head, 30);
    insertAtHead(head, 20);
    print(head);
    cout<<"Head "<< head->data <<endl;

    cout<<endl;

    //reverseNode(head);

    Node* prev = NULL;
    Node* curr = head;
    reverse(head, curr, prev);

    print(head);
    cout<<"Head "<< head->data <<endl;

    return 0;
}