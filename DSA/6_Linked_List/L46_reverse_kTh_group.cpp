#include <iostream>
using namespace std;

class Node {
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


Node* kReverse(Node* head, int k) {
    
    // Check if there are at least k nodes in the current segment
        Node* temp = head;
        int count = 0;
         while (temp != NULL && count < k) {
            temp = temp->next;
            count++;
        }

        // If fewer than k nodes, return the list as-is
        if (count < k) {
            return head;
        }

    //iterative solution for kth node
    Node* prev = nullptr;
    Node* curr = head;
    Node* forward = nullptr;
    count = 0;

    while(curr != NULL && count < k){
        forward = curr-> next;
        curr-> next = prev;
        prev = curr;
        curr = forward;
        count+=1;
    }

    //recursive call
    if (forward != nullptr) {
        head->next = kReverse(forward, k);
    }

    return prev;


}

int main() {

    return 0;
}