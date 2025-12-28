#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int d) {
        this->data = d;
        this->next = nullptr;
    }
};


//function to insert the values
void insertAtTail(Node* &head, Node* &tail, int d) {
    Node* temp = new Node(d);

    if(head == nullptr){
        head = temp;
        tail = temp;
        return;
    }

    else {
        tail->next = temp;;
        tail = temp;
        
    }
}


//reverse the linked list
Node* reverse(Node* &head) {
    if(head == nullptr || head-> next == nullptr) return head;

    Node* curr = head;
    Node* forward = nullptr;
    Node* prev = nullptr;

    while(curr != nullptr) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;  
}


//function to add both lists
Node* addList(Node* &head1, Node* &head2) {

    int carry = 0;

    Node* ansHead = nullptr;
    Node* ansTail = nullptr;

    while(head1 != nullptr || head2 != nullptr || carry != 0) {

        int val1 = 0; //created to store the node values
        int val2 = 0; 
        if(head1 != nullptr) { //generalized case to check till null values
            val1 = head1->data;
        }
        
        if(head2 != nullptr) {
            val2 = head2->data;
        }

        int sum = carry + val1 + val2;
        int digit = sum%10;

        insertAtTail(ansHead, ansTail, digit); //function will insert the value of digit in ansList

        carry = sum/10; // this carry will used further

        if(head1 != nullptr)
        head1 = head1->next;

        if(head2 != nullptr)
        head2 = head2->next;
    }

    return ansHead;
}


//a print function to display the list
void print(Node* &ans) {
    Node* temp = ans;
    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}


int main() {

    //for first list
    Node* head1 = nullptr;
    Node* tail1 = nullptr;
    insertAtTail(head1, tail1, 4);
    insertAtTail(head1, tail1, 5);

    //for second list
    Node* head2 = nullptr;
    Node* tail2 = nullptr;
    insertAtTail(head2, tail2, 3);
    insertAtTail(head2, tail2, 4);
    insertAtTail(head2, tail2, 5);

    //calling the reverse function
    head1 = reverse(head1);
    head2 = reverse(head2);

    Node* ans = addList(head1, head2); // function called to add the lists

    //again calling raverse function to reverse the final list
    ans = reverse(ans);

    print(ans);


    return 0;
}