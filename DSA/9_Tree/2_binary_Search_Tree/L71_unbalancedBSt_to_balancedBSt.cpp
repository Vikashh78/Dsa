/*You have been given a binary search tree of integers with ‘N’ nodes. Your task is to convert it into a balanced BST with the minimum height possible.
A Balanced BST is defined as a BST, in which the height of two subtrees of every node differs no more than 1.*/

/*Algo-
1. obtain inorder in a vector of given tree
2. find mid of the vector
3. now make a function in which
    -create a root for mid value
    -do recursive call for left and right
*/


#include <iostream>
using namespace std;
#include <queue>
#include <vector>


class Node {
    public:
    int data;
    Node* left;
    Node* right;

    //constructor
    Node(int d) {
        this->data = d;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// function to build binary search tree
Node* buildBST(Node* root, int x) {
    //base case
    if(root == nullptr) {
        root = new Node(x);
        return root;
    }
    if(x < root->data) {
        root->left = buildBST(root->left, x);
    }
    else {
        root->right = buildBST(root->right, x);
    }

    return root;
}

void takeInput(Node* &root) {
    int x;
    cin>> x;

    while(x != -1) {
        root = buildBST(root, x);
        cin>> x;
    }
}





// inorder function
void inorder(Node* root, vector<int>& inorderVal) {

    if(root == nullptr) return;

    inorder(root->left, inorderVal);
    inorderVal.push_back(root->data);
    inorder(root->right, inorderVal);
}

// function to make tree balance
Node* balanceTree(vector<int> inorderVal, int start, int end) {

    // base case
    if(start > end) {
        return nullptr;
    }

    int mid = start + (end - start)/2;
    Node* root = new Node(inorderVal[mid]);  // new node is created for mid data

    //recursive calls
    root->left = balanceTree(inorderVal, start, mid-1);
    root->right = balanceTree(inorderVal, mid+1, end);

    return root;
}








// level order traversal function
void levelOrder(Node* root) {

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


int main() {

    Node* root = nullptr;

    // for unbalanced tree part
    takeInput(root);
    cout<<"printing unbalanced tree\n";
    levelOrder(root);


    // for balanced tree part
    vector<int> inorderVal;
    inorder(root, inorderVal); // got the inorder val

    int start = 0, end = inorderVal.size()-1;

    root = balanceTree(inorderVal, start, end);
    cout<<"\n\nprinting balance tree\n";
    levelOrder(root);

    return 0;
}