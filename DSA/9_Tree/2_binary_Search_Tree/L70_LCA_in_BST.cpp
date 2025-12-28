#include <iostream>
using namespace std;

class node {
    public:    // as the properties are going to used outside the class
    int data;
    node* left;
    node* right;

    node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }    
};

node* buildBST(node* root, int x) {
    
    // base case
    if(root == nullptr) {
        root = new node(x);
        return root;
    }

    if(root->data > x) {
        root->left = buildBST(root->left, x);
    }

    else {
        root->right = buildBST(root->right, x);
    }

    return root;
}

void takeInput(node* &root) {
    int x;
    cin>> x;
    while(x != -1) {
        root = buildBST(root, x);
        cin>> x;
    }
}





// function to find lowest common ancestor LCA
node* lca(node* root, int x, int y) {
    
    //iterative solution
    node* temp = root;

    while(temp != nullptr) {

        if(temp->data < x && temp->data < y) {
            //move to right part of tree
            temp = temp->right;
        }

        else if(temp->data > x && temp->data > y) {
            // move towards left sub tree
            temp = temp->left;
        }

        else {  // you are at root

            return temp;
        }
    }

    return nullptr;
}




int main() {

    node* root = nullptr;

    takeInput(root);

    node* ans = lca(root, 9, 10);
    cout<<"LCA of 6 and 10 is : " << ans->data <<endl;

    return 0;
}