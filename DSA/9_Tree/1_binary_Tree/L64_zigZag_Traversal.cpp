#include <iostream>
using namespace std;
#include<vector>
#include <queue>

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


vector<int> zigZagTrav(Node* root) {  

    vector<int> result;

    // null condition
    if(root == nullptr) {
        return result;
    }

    bool leftToRight = true;
    queue<Node*> q; // Queue for level order traversal

    q.push(root);

    while (!q.empty()) {
        
        int size = q.size(); // Store the current level size
        vector<int> temp(size);

        // level process
        for (int i = 0; i < size; i++) {

            Node* frontNode = q.front();
            q.pop();

            int index = leftToRight ? i : size - i - 1; // Corrected index calculation
            
            temp[index] = frontNode->data;

            if (frontNode->left) {
                q.push(frontNode->left);
            }
            if (frontNode->right) {
                q.push(frontNode->right);
            }
        }

        leftToRight = !leftToRight; // Toggle direction

        for(auto i : temp) {
            result.push_back(i);
        }
    }

    return result;
}


int main() {

    Node* root = nullptr;

    root = buildTree(root);

    cout<<"zigZag traversal of the tree is : ";
    vector<int> result = zigZagTrav(root);
    for(int i=0; i<result.size(); i++) {
        cout<<result[i]<<" ";
    }
    cout<<endl;


    return 0;
}