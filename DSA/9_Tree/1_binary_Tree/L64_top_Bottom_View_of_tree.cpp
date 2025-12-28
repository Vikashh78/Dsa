#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <map>

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


// function for top view
vector<int> topViewOfTree(Node* &root) {
    vector<int> result;

    if(root == nullptr) {
        return result;
    }
    map <int, int> topNode; // we have to insert all the node->data in this map(a ordered map)
    queue<pair <Node*, int> > q;  // q me first element node insert hua hai, second element horizontal dist. insert hua hai
    q.push(make_pair(root, 0));  // root element is pushed with horizontal distance[hd] -> 0

    while(! q.empty()) {
        pair<Node*, int> temp = q.front();  // temp ke two parts hai 1. node, 2.int
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        //[==] means key->value map me present nhi hai, nd [ != ]:key->value is present in the map
        if(topNode.find(hd) == topNode.end()) {   
            topNode[hd] = frontNode->data;        // topNode.end() is the iterator pointing past the last element in the map.
        }                                         // If hd is not found in the map, find(hd) returns topNode.end().

        if(frontNode->left) {
            q.push(make_pair(frontNode->left, hd-1));
        }
        if(frontNode->right) {
            q.push(make_pair(frontNode->right, hd+1));
        }
    }

    for(auto i : topNode) {
        result.push_back(i.second);
    }
    return result;
}



// function for bottom view 
vector<int> bottomViewOfTree(Node* &root) {
    vector<int> result;

    if(root == nullptr) {
        return result;
    }
    map <int, int> topNode; // we have to insert all the node->data in this map(a ordered map)
    queue<pair <Node*, int> > q;  // q me first element node insert hua hai, second element horizontal dist. insert hua hai

    q.push(make_pair(root, 0));  // root element is pushed with horizontal distance[hd] -> 0
    while(! q.empty()) {
        pair<Node*, int> temp = q.front();  // temp ke two parts hai 1. node, 2.int
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        //only one change is there i.e. no condition will be checked, jo bhi data aa rha map me directly insert kar do  
        //If any lower-level node is later found with the same HD = 0,
        //it will replace the previous entry (because this is bottom view, not top view). 
        topNode[hd] = frontNode->data;   // store/overwrite node value                                

        if(frontNode->left) {
            q.push(make_pair(frontNode->left, hd-1));
        }
        if(frontNode->right) {
            q.push(make_pair(frontNode->right, hd+1));
        }
    }
    for(auto i : topNode) {
        result.push_back(i.second);
    }
    return result;
}


int main() {

    Node* root = nullptr;
    root = buildTree(root);

    // vector<int> ans = topViewOfTree(root);
    // cout<<"Top view of tree is : ";
    // for(int i=0; i<ans.size(); i++) {
    //     cout<<ans[i]<<" ";
    // }cout<<endl;


    vector<int> ans = bottomViewOfTree(root);
    cout<<"bottom view of tree is : ";
    for(int i=0; i<ans.size(); i++) {
        cout<<ans[i]<<" ";

    } cout<<endl;

    return 0;
}