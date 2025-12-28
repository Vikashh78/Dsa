/*Given a binary tree and a node data called target. Find the minimum time required to burn the complete binary tree if the target is 
set on fire. It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.
Note: The tree contains unique values.*/

#include <iostream>
using namespace std;
#include <map>
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





// function to create mapping of current node to its parent
Node* createParentMapping(Node* root, int& target, map<Node*, Node*>& nodeToParent) {

    Node* result = nullptr;   

    queue<Node*> q;
    q.push(root);
    nodeToParent[root] = nullptr;     // parent of root is set to nullptr

    while(! q.empty()) {

        Node* frontNode = q.front();
        q.pop();

        if(frontNode->data == target){
            result = frontNode;
        }

        // mapping part
        if(frontNode->left) {
            nodeToParent[frontNode->left] = frontNode; 
            q.push(frontNode->left);
        }

        if(frontNode->right) {
            nodeToParent[frontNode->right] = frontNode;
            q.push(frontNode->right);
        }
    }
    return result;
}


// function to burn the tree
int burnTree(Node* root, map<Node*, Node*>& nodeToParent) {

    // required two dataset here
    map<Node*, bool> visited;
    queue<Node*> q;

    q.push(root);
    visited[root] = true; 

    int time = 0;

    while(! q.empty()) {

        bool flag = false;
        int size = q.size();

        for(int i=0; i<size; i++) {
            // processing the neighbour data
            Node* front = q.front();
            q.pop();

            if(front->left && !visited[front->left]) {
                flag = true; 
                q.push(front->left);
                visited[front->left] = true;
            }

            if(front->right && !visited[front->right]) {
                flag = true;
                q.push(front->right);
                visited[front->right] = true;
            }

            // ye check krta hai ki kya currnet node ka koi parenet unvisited node hai to use q me daal do
            if(nodeToParent[front] && !visited[nodeToParent[front]]) {
                flag = true;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = true;
            }
        }
        if(flag == true) 
        time++;
    }
    return time;
}




// 1 2 4 -1 -1 5 7 -1 -1 8 -1 -1 3 -1 6 -1 9 -1 10 -1 -1


int main() {

    Node* root = nullptr;
    root = buildTree(root);

    int target = 8;
    map<Node*, Node*> nodeToParent;
    
    Node* targetNode = createParentMapping(root, target, nodeToParent);

    int ans = burnTree(targetNode, nodeToParent);
    cout<<"time taken to burn entire tree is : "<< ans <<" sec" <<endl;

    return 0;
}