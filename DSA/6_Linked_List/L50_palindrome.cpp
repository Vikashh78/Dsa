#include <iostream>
using namespace std;

class Node {
    public :
    int data;
    Node* next;

    Node(int d) {
        this-> data = d;
        this-> next = nullptr;
    }
};

// Approach 1 -> copy the elements of the linked list into an vector array and check if it is palinddrome or not
// space complexity will be O(n)












// Approach 2 -> find middle of the list and reverse right half of the list and now compare it from left part
// space complexity will be O(1)

void insertAtHead(Node* &head, int data) {
    Node* temp = new Node(data);
    temp-> next = head;
    head = temp;
}

//finding the middle of the lisnked list
Node* getMiddle(Node* &head) {
    Node* fast = head;
    Node* slow = head;

    while(fast != nullptr && fast-> next != NULL) {
        fast = fast-> next-> next;
        slow = slow-> next;
    }
    return slow;
}

//code to reverse the linked list
Node* reversed(Node* head) {

    Node* curr = head;
    Node* prev = nullptr;
    Node* next = NULL;

    while(curr != nullptr) {
        next = curr-> next;
        curr-> next = prev;
        prev = curr; // Move prev and curr one step forward
        curr = next;
    }
    return prev;
}

bool getResult(Node* &head){

    Node* middle = getMiddle(head);

    Node* temp = middle-> next;
    middle-> next = reversed(temp);

    Node* head1 = head;
    Node* head2 = middle-> next;

    while(head2 != nullptr) {
        if(head2-> data != head1-> data) {
            return false;
        }
        head1 = head1-> next;
        head2 = head2-> next;
    }

    return true;
}


int main() {

    Node* head = new Node(1);
    insertAtHead(head, 2);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 4);

    if(head-> next == nullptr){
        cout<<"palindrome"<<endl;
    }

    else if(!getResult(head)) {
        cout<<"Not palindrome"<<endl;
    }

    else {
        cout<<"pelindrome"<<endl;
    }


    return 0;
}