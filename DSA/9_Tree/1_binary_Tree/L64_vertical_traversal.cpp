#include <iostream>
using namespace std;
#include <vector>

class node {
    public:
    int data;
    node* left;
    node* right;

    //constructor
    node(int d) {
        this->data = d;
        this->left = nullptr;
        this->right = nullptr;
    }
};

node* buildBinaryTree(node* root) {

    int x;
    cin>> x;
    root = new node(x);

    //base case
    if(x == -1) {
        return;
    }

    root->left = buildBinaryTree(root->left);

    root->right = buildBinaryTree(root->right);
}



// vertical traversal
void verticaltraversal(node* &root, vector<int> ans) {

}


int main() {

    node* root = nullptr;
    root = buildBinaryTree(root);

    return 0;
}