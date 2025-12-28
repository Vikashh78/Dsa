#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int d) {
        this-> data = d;
        this-> next = nullptr;
    }
};

//first linked list
void list1(Node* &head1, int data){

    Node* temp = new Node(data);
    temp-> next = head1;
    head1 = temp;
}

//second linked list
void list2(Node* &head2, int data){

    Node* temp = new Node(data);
    temp-> next = head2;
    head2 = temp;
}


// logic to add two sorted list is here
Node* solve(Node* &head1, Node* &head2) {

    Node* curr1 = head1;
    Node* next1 = curr1-> next;

    Node* curr2 = head2;
    Node* next2 = curr2-> next;

    while(next1 != nullptr && curr2 != nullptr) {

        if((curr2-> data >= curr1-> data) && (curr2-> data <= next1-> data)) {
            //add node in between
            curr1-> next = curr2;
            next2 = curr2-> next;
            curr2-> next = next1;

            //update pointers
            curr1 = curr2;
            curr2 = next2; 
        }

        else { //curr1 and next1 ko aage badha do

            curr1 = next1;
            next1 = next1-> next;

            if(next1 == nullptr) {
                curr1-> next = curr2;
                return head1;
            }

        }
    }
}


Node* sortTwoList(Node* &head1, Node* &head2) {
    
    if(head1 == nullptr) return head2;

    if(head2 == nullptr) return head1;

    if(head1-> data <= head2-> data) {// the list having the smaller data will passed first
        solve(head1, head2);
    }
    else{
        solve(head2, head1);
    }
}

void print1(Node* &head1){

    //creating a temporary node equal to head
    Node* temp = head1;
    while(temp != NULL){
        cout<< temp-> data <<" ";
        temp = temp-> next;
    }
    cout<<endl;
}

void print2(Node* &head2){

    //creating a temporary node equal to head
    Node* temp = head2;
    while(temp != NULL){
        cout<< temp-> data <<" ";
        temp = temp-> next;
    }
    cout<<endl;
}


int main() {

    //creating a head for the first list
    Node* head1 = new Node(6);
    list1(head1, 5);
    list1(head1, 3);
    list1(head1, 1);
    cout<<"First list is : ";
    print1(head1);
    cout<<endl;

    //creating a head for second list
    Node* head2 = new Node(5);
    list2(head2, 4);
    list2(head2, 2);
    cout<<"Second list is : ";
    print2(head2);
    cout<<endl;

    //merge list
    sortTwoList(head1, head2);
    cout<<"Merged list is : ";
    print1(head1);
    cout<<endl;

    return 0;
}