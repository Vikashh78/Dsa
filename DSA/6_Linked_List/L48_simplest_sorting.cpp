#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
};

// Function to insert a new node at the end of the list
void insert(Node** head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (*head == nullptr) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to print the linked list
void printList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Function to sort the linked list
void sortLinkedList(Node* head) {
    if (head == nullptr || head->next == nullptr) 
        return;

    // Step 1: Copy all node data into a vector
    std::vector<int> values;
    Node* temp = head;
    while (temp != nullptr) {
        values.push_back(temp->data);
        temp = temp->next;
    }

    // Step 2: Sort the vector
    std::sort(values.begin(), values.end());

    // Step 3: Copy sorted values back to the linked list
    temp = head;
    for (int val : values) {
        temp->data = val;
        temp = temp->next;
    }
}

int main() {
    Node* head = nullptr;

    // Creating a linked list
    insert(&head, 4);
    insert(&head, 2);
    insert(&head, 1);
    insert(&head, 5);
    insert(&head, 3);

    std::cout << "Original list: ";
    printList(head);

    // Sort the linked list
    sortLinkedList(head);

    std::cout << "Sorted list: ";
    printList(head);

    return 0;
}
