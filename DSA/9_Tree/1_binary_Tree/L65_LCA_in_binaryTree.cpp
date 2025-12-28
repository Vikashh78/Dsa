// Given a Binary Tree with all unique values and two nodes value, n1 and n2. The task is to find the lowest common ancestor 
// of the given two nodes. We may assume that either both n1 and n2 are present in the tree or none of them are present.

// LCA: It is the first common ancestor of both the nodes n1 and n2 from bottom of tree.

#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

    Node(int d) {
        this-> data = d;
        this-> left = NULL;
        this-> right = NULL;
    }
};
Node* buildTree(Node* root) {

    int data;
    cin >> data;
    root = new Node(data);    

    // base case
    if(data == -1) {
        return NULL;
    }

    root->left = buildTree(root->left);

    root->right = buildTree(root->right);

    return root;
}






// Function to return the lowest common ancestor in a Binary Tree.
Node* lca(Node* root, int n1, int n2) {

    // base case
    if(root == nullptr) {
        return nullptr;
    }
    if(root->data == n1 || root->data == n2) {
        return root;
    }
    

    Node* leftAns = lca(root->left, n1, n2);  //left call

    Node* rightAns = lca(root->right, n1, n2); //right call
    
    //at time of return 
    if(leftAns == nullptr && rightAns != nullptr) {
        return rightAns;
    }
    else if(leftAns != nullptr && rightAns == nullptr) {
        return leftAns;
    }
    else if(leftAns != nullptr && rightAns != nullptr) { // means you are at LCA
        return root;
    }
    else {  // not any LCA is found
        return nullptr;
    }
}




int main() {

    Node* root = nullptr;
    root = buildTree(root);

    int n1 = 9, n2 = 5;
    Node* ans = lca(root, n1, n2);

    cout<<"LCA of "<<n1 <<" and "<<n2 <<" is : " <<ans->data <<endl;


    return 0;
}