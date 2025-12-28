#include <iostream>
using namespace std;
#include <map>

class Node {
    public:
    int data;
    Node* next;

    Node(int data) { // constructor
        this-> data = data;
        this-> next = NULL;
    }

};

void insertAtHead(Node* &head, Node* &tail,  int data){

    Node* node1 = new Node(data);

    if(head == NULL){
        head = node1;
        tail = node1;
    }
    else{
        node1 -> next = head;
        head = node1;
    }

}







// 1-> Function to detect loop in the linked list using MAP-
bool detectCycle(Node* &head){

    if(head == NULL){
        return false;
    }

    map< Node*, bool > visited;  //key is node and value is bool
    Node* temp = head;

    while(temp != NULL){

        if(visited[temp] == true){
            return true;
        }

        //if not visited already
        visited[temp] = true;

        temp = temp-> next;
    }

    return false;
}

// //floyd's loop detection cycle using SLOW FAST Pointers
// bool floydCycleDetection(Node* &head){

//      if(head == NULL){
//         return false;
//     }

//     Node* slow = head;
//     Node* fast = head;

//         while(slow != NULL && fast != NULL){
            
//             fast = fast-> next;
//             if(fast != NULL){
//                 fast = fast-> next;
//             }

//             slow = slow-> next;

//             if(slow == fast){ 
//                 return true;
//             }
//         }

//     return false;
// }

//floyd's loop detection cycle 
Node* floydCycleDetection(Node* &head){

     if(head == NULL){
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

        while(slow != NULL && fast != NULL){
            
            fast = fast-> next;
            if(fast != NULL){
                fast = fast-> next;
            }

            slow = slow-> next;

            if(slow == fast){ 
                return slow;
            }
        }

    return NULL;
}



// 2-> function to find starting node of the loop 
Node* getStartingNode(Node* &head) {

    if(head == NULL) return head;

    //call for getting intersection node
    Node* intersection = floydCycleDetection(head);
    Node* slow = head;

    while(slow != intersection){

        slow = slow-> next;
        intersection = intersection-> next;

    }
    return slow; // returning the starting node of the loop here
}


// 3-> Function to remove loop from linked List
void removeLoop(Node* &head) {

    if(head == NULL) return;

    Node* startOfLoop = getStartingNode(head);
    Node* temp = startOfLoop;
    
    while(temp-> next != startOfLoop){
        temp = temp-> next;
    }

    temp-> next = NULL;
}




void print(Node* &head){

    if(head == nullptr){
        cout<<"List is empty"<<endl;
    }

    //creating a temporary node equal to head
    Node* temp = head;
    while(temp != NULL){
        cout<< temp-> data <<" ";
        temp = temp-> next;
    }
    cout<<endl;
}



int main() {

    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head, tail, 3);
    insertAtHead(head, tail, 6);
    insertAtHead(head, tail, 5);
    insertAtHead(head, tail, 4);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;

    //making ths list cycle
    tail-> next = head-> next;
    //print(head);

    if(floydCycleDetection(head)){
        cout<<"Cycle is presrent"<<endl;
    }
    else{
        cout<<"Cycle is not present"<<endl;
    }

    Node* result = getStartingNode(head);
    cout<<"Loop begins at the node " << result-> data <<endl;

    removeLoop(head);
    cout<<"Loop is removed from the Linked List"<<endl;

    //printing the list again
    print(head);


    return 0;
}