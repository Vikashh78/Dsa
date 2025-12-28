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
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node* build_bst(Node* root, int d) {
    // base case
    if(root == nullptr) {
        root = new Node(d);    // Create a new node when reaching a null branch
        return root;
    }

    if(d < root->data) {
        root->left = build_bst(root->left, d);
    }

    else {
        root->right = build_bst(root->right, d);
    }

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









//min value function
int minVal(Node* root) {
    Node* temp = root;
    while(temp->left != nullptr) {
        temp = temp->left;
    }
    return temp->data;
}


// deletion in bst
Node* deleteFromBST(Node* root, int target) {

    //base cases
    if(root == nullptr) {
        return nullptr;
    }

    if(root->data == target) {
        //case 1: if root is leaf node
        if(root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }

        //case 2: if root have one child/subtree
            // left part-
            if(root->left != nullptr && root->right == nullptr) {
                Node* tempLeft = root->left;
                delete root;
                return tempLeft;
            }
            // right part-
            if(root->left == nullptr && root->right != nullptr) {
                Node * tempRight = root->right;
                delete root;
                return tempRight;
            }

        //case 3: if root have boot child/subtree
            if(root->left != NULL && root->right != nullptr) {
                int mini = minVal(root->right);  // ✅ get inorder successor
                root->data = mini;
                root->right = deleteFromBST(root->right, mini);   
                return root;             
            }
        }
    
        else if(root->data > target) {
            root->left = deleteFromBST(root->left, target);
        }

        else {
            root->right = deleteFromBST(root->right, target);
        }

    return root;
}







// level order traversal function
void levelOrderTraversal(Node* root) {

    queue<Node*> q;
    q.push(root);
    q.push(nullptr);

    while(! q.empty()) {
        Node* front = q.front();
        q.pop();

        if(front == nullptr) {
            cout<<endl; 

            if(! q.empty()) {
                q.push(nullptr);
            }
        }
        else {
            cout<<front->data <<" ";
            if(front->left) {
                q.push(front->left);
            }
            if(front->right) {
                q.push(front->right);
            }
        }
    }
}





// main function
int main() {

    Node* root = nullptr;

    cout<<"enter data to create bst(-1 to stop) : ";
    takeInput(root);

    cout<<"level order treversal of bst is-\n";
    levelOrderTraversal(root);


    // deletion function call
    root = deleteFromBST(root, 8);
    cout<<"after deletion tree is-\n";
    levelOrderTraversal(root);


    return 0;
}