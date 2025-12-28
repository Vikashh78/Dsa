#include <iostream>
using namespace std;
#include <vector>



class TrieNode {                   // TC: O(m*n) and SC: O(m*n)

    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    int childCount;

    TrieNode(char ch) {
        data = ch;
        for(int i=0; i<26; i++) {
            children[i] = nullptr;
        }
        isTerminal = false;
        childCount = 0;
    }
};


class Trie {
    public:
    TrieNode* root;

    Trie(char ch) {
        root = new TrieNode(ch);
    }

     //insertion
     void insertUtil(TrieNode* root, string word) {
        // base case
        if(word.size() == 0) {
            root->isTerminal = true;
            return;
        }

        // assumption, word will be in CAPS
        int index = word[0] - 'a';         // find which character
        TrieNode* child;

        // character is present 
        if(root->children[index] != nullptr) {
            child = root->children[index];
        }
        // absent
        else {
            child = new TrieNode(word[0]);   
            root->childCount++;
            root->children[index] = child; 
        }

        // for rest, there is recursion
        insertUtil(child, word.substr(1));
    }
    void insertWord(string word) {
        insertUtil(root, word);
    }


    
    // lcp function
    void lcpString(string str, string& ans) {

        for(int i=0; i<str.length(); i++) {
            char ch = str[i];

            if(root->childCount == 1) {
                ans.push_back(ch);

                // move down
                int index = ch - 'a';
                root = root->children[index];
            }

            else { //child count is not equals to 1
                break;
            }

            if(root->isTerminal)
            break;
        }
    }
};




int main() {

    vector<string> arr = {"ramol", "ramu", "rami", "ramcl"};
    int size = arr.size();

    //empty case
    for(string s : arr) {
        if(s.empty()) {
            return 0;
        }
    }

    Trie* t = new Trie('\0');

    // insert all strings into trie
    for(int i=0; i<size; i++) {
        t->insertWord(arr[i]);
    }


    string first = arr[0];  //sirf first string hi bhej rhe hai bcoz trie me ye string common hogi
    string ans = "";

    t->lcpString(first, ans);

    cout<<"lcp of array is : ";
    for(int i=0; i<ans.size() ; i++) {
        cout<<ans[i];
    }cout<<endl;


    return 0;
}