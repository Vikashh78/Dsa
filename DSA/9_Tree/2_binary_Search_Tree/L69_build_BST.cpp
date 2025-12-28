#include <iostream>
using namespace std;
#include <queue>

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* build_bst(Node* root, int d) {
    // base case
    if(root == nullptr) {
        root = new Node(d);    // Create a new node when reaching a null branch
        return root;
    }

    /*Left child is nullptr, so build_bst(root->left, 5) becomes build_bst(nullptr, 5).
    A new node with value 5 is created and assigned to root->left.*/
    if(d < root->data) {
        root->left = build_bst(root->left, d);
    }

    else {
        root->right = build_bst(root->right, d);
    }

    // Always returns the current root so it can be connected correctly in recursive calls.
    return root;
}

//function to take input data
void takeInput(Node* &root) {

    int d;
    cin>> d;

    while(d != -1) {
        root = build_bst(root, d);
        cin>> d;
    }
}


// function to print tree
void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) { 
            //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) { 
                //queue still has some child ndoes
                q.push(NULL);
            }  
        }
        else{
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }
}


int main() {

    Node* root = NULL;
    takeInput(root);

    levelOrderTraversal(root);

    return 0;
}