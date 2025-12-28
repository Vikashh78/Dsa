#include <iostream>
using namespace std;

class Node{
    public:
    //properties-
    int data;
    Node* next;

    //constructor
    Node(int d){
        this-> data = d;
        this-> next = nullptr;
    }

};

void insertAtTail(Node* &head, Node* &tail, int data){

    Node* node1 = new Node(data);

    if(tail == NULL){
        head = node1;
        tail = node1;
    }
    else{
       tail-> next = node1;
       tail = node1;
    }
}



Node* getMiddle(Node* &head){
    
    if(head == nullptr || head->next == nullptr) return head;

    //for 2 nodes 
    if(head-> next-> next == nullptr) return head-> next;

    Node* slow = head;
    Node* fast = head-> next;
    while(fast != nullptr){

        fast = fast-> next;
        //again check
        if(fast != nullptr){
            fast = fast-> next;
        }

        slow = slow-> next;
    }
    return slow;

}



void print(Node* head){
    if(head == nullptr){
        cout<<"List is empty"<<endl;
    }
    else{
        Node* ptr = head;
        while(ptr != nullptr){
            cout<<ptr-> data <<" ";
            ptr = ptr-> next;
        }
        cout<<endl;
    }
}

int main() {

    Node* tail = nullptr;
    Node* head = nullptr;

    insertAtTail(head, tail, 5);
    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 12);
    insertAtTail(head, tail, 16);
    insertAtTail(head, tail, 21);
    
    print(head);
    cout<<"Head "<<head-> data <<endl;
    cout<<"Tail "<<tail-> data <<endl;

    Node* middle = getMiddle(head);
    cout<<"Middle "<<middle-> data <<endl;

    return 0;
}