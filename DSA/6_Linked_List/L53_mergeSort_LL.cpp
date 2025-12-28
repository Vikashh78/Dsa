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

// Function to insert values at the tail of the linked list
void insertAtTail(Node*& head, Node*& tail, int d) {
    Node* temp = new Node(d);

    if (head == nullptr) {
        head = temp;
        tail = temp;
        return;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

// Function to find the middle of the linked list
Node* findMid(Node*& head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// Function to merge two sorted linked lists
Node* merge(Node*& left, Node*& right) {
    if (left == nullptr) return right;
    if (right == nullptr) return left;

    // Dummy node to start the merged list
    Node* ans = new Node(-1);
    Node* ptr = ans;

    while (left != nullptr && right != nullptr) {
        if (left->data < right->data) {
            ptr->next = left;
            ptr = left;
            left = left->next;
        } else {
            ptr->next = right;
            ptr = right;
            right = right->next;
        }
    }

    // Attach the remaining part if any list is left
    if (left != nullptr) {
        ptr->next = left;
    }
    if (right != nullptr) {
        ptr->next = right;
    }

    // Get the merged list, skipping the dummy node
    Node* result = ans->next;
    delete ans; // Free the dummy node
    return result;
}

// Function to perform merge sort on the linked list
Node* mergeSort(Node*& head) {
    if (head == nullptr || head->next == nullptr) return head;

    // Find the middle of the list and split it
    Node* mid = findMid(head);
    Node* left = head;
    Node* right = mid->next;
    mid->next = nullptr; // Split the list into two halves

    // Recursively sort both halves
    left = mergeSort(left);
    right = mergeSort(right);

    // Merge the two sorted halves
    return merge(left, right);
}

// Function to print the linked list
void print(Node* head) {
    Node* ptr = head;
    while (ptr != nullptr) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    // Insert some values into the linked list
    insertAtTail(head, tail, 5);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 9);
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 4);
    insertAtTail(head, tail, 8);

    // Perform merge sort on the linked list
    Node* finalAns = mergeSort(head);

    // Print the sorted list
    cout << "Sorted list is: ";
    print(finalAns);

    return 0;
}
