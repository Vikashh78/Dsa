//approach.1- sort the given preorder data to get inorder[sorted] data now, make tree from inorder data. : TC O(nlogn)

#include <iostream>
using namespace std;
#include <vector>
#include <limits.h>

//approch.2- optimal approach TC-O(n)

class node {
    public:
    int data;
    node* left;
    node* right;

    node(int d) {
        this->data = d;
        this->left = nullptr;
        this->right = nullptr;
    }
};






// function to build tree
node* buildTree(vector<int> preorder, int &i, int mini, int maxi) {

    // base cases
    if(i >= preorder.size()) {
        return nullptr;
    }
    if(preorder[i] < mini || preorder[i] > maxi) {
        return nullptr;
    }

    // creating a new node to store the data
    node* root = new node(preorder[i++]); 

    root->left = buildTree(preorder, i, mini, root->data);

    root->right = buildTree(preorder, i, root->data, maxi);

    return root;
}






// function to print the inorder data of the tree
void inOrder(node* root) {
    // base case
    if(root == nullptr) return;

    // recursive call
    inOrder(root->left);
    cout<<root->data <<" ";
    inOrder(root->right);
}


int main() {

    // input preorder
    vector<int> preorder = {14,8,6,12,17,20};
    int i = 0;
    int mini = INT_MIN;   // will play the key role
    int maxi = INT_MAX;

    node* ans = buildTree(preorder, i, mini, maxi);

    cout<<"printing inorder of binary search tree : ";
    inOrder(ans);


    return 0;
}