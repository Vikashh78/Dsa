#include <iostream>
using namespace std;
#include <vector>


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






/*  1.Create an array arr of size n, where n is the number of nodes in the given BST.
    2.Perform the inorder traversal of the BST and copy the node values in the arr[] in sorted order.
    3.Now perform the preorder traversal of the tree.
    4.While traversing the root during the preorder traversal, one by one copy the values from the array arr[] to the nodes of the BST.
*/
// step.2
void inorderTraversal(Node* root, vector<int>& inorderArr) {

    if(root == nullptr) return;

    inorderTraversal(root->left, inorderArr);
    inorderArr.push_back(root->data);
    inorderTraversal(root->right, inorderArr);
}


// step 3 & 4
void preorderFill(Node* &root, vector<int> inorderArr, int& index) {
    // base case
    if(root == nullptr) return;

    int temp = inorderArr[index++];
    root->data = temp;

    preorderFill(root->left, inorderArr, index);
    
    preorderFill(root->right, inorderArr, index);
}







//printing minHeap (preorder)
void preOrderPrint(Node* root) {

    if(root == nullptr) return;
    
    cout<<root->data<<" ";
    preOrderPrint(root->left);
    preOrderPrint(root->right);
}
 


int main() {

  /*  Constructing the Binary Search Tree (BST)
              4
            /   \
           2     6
          / \   / \
         1   3 5   7   */

    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);


    // step.1
    vector<int> inorderArr;

    // Step 3: Perform inorder traversal 
    inorderTraversal(root, inorderArr);

    int index = 0;
    // Step 3: Perform preorder traversal and 
    // fill nodes with inorder values
    preorderFill(root, inorderArr, index);



    // printing minHeap data
    cout<<"printing minHeap data : ";
    preOrderPrint(root);
    
    return 0;
}