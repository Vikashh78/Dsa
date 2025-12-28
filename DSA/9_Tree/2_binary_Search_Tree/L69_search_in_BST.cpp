#include <iostream>
using namespace std;

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





// searching in BST recursive method-     this method occupy extra space 
bool search_bst(Node* root, int target) {
    // base case
    if(root == nullptr) {
        return false;
    }
    if(root->data == target) {
        return true;
    }

    // recursive calls
    if(target < root->data) {
        bool left = search_bst(root->left, target);
    }
    else {
        bool right = search_bst(root->right, target);
    }
}


// iterative method searching
bool bst_search(Node* root, int target) {

    Node* temp = root;
    
    while(temp != nullptr) {

        if(temp->data == target) {
            return true;
        }
        if(target < temp->data) {
            temp = temp->left;
        }
        else {
            temp = temp->right;
        }
    }

    return false;
}





// function to get maimum value in BST
int maxVal(Node* root) {
    Node* temp = root;
    while(temp->right != nullptr) {
        temp = temp->right;
    }
    return temp->data;
}

// minimum value function
int minVal(Node* root) {
    Node* temp = root;
    while(temp->left != nullptr) {
        temp = temp->left;
    }
    return temp->data;
}





//function to print
void preorder(Node* root) {
    if(root == nullptr) {
        return;
    }

    cout<<root->data <<" ";
    preorder(root->left);
    preorder(root->right);
}

int main() {

    Node* root = nullptr;

    takeInput(root);

    cout<<"preorder traversal is : ";
    preorder(root);



    if(bst_search(root, 4)) {
        cout<<"\ntarget present in tree"<<endl;
    }
    else {
        cout<<"target is not present"<<endl;
    }



    cout<<"minimum element in tree is : " << minVal(root) <<endl;
    cout<<"maximum element in tree is : " << maxVal(root) <<endl;

    

    return 0;
}