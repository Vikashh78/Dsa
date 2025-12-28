// Trie is a tree-like data structure that is used to efficiently store and retrieve strings

#include <iostream>
using namespace std;




class TrieNode {

    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    // constructor
    TrieNode(char ch) {
        data = ch;
        for(int i=0; i<26; i++) {
            children[i] = nullptr;
        }
        isTerminal = false;
    }
};


class Trie {
    public:
    TrieNode* root;

    //constructor
    Trie(){
        root = new TrieNode('\0');   //root of the trie is always have null character
    }


    //insertion
    void insertUtil(TrieNode* root, string word) {
        // base case
        if(word.size() == 0) {
            root->isTerminal = true;
            return;
        }

        // assumption, word will be in CAPS
        int index = word[0] - 'A';         // find which character
        TrieNode* child;

        // character is present 
        if(root->children[index] != nullptr) {
            child = root->children[index];
        }
        // absent
        else {
            child = new TrieNode(word[0]);
            root->children[index] = child; 
        }

        // for rest, there is recursion
        insertUtil(child, word.substr(1));
    }
    void insertWord(string word) {
        insertUtil(root, word);
    }




    //searching
    bool searchUtil(TrieNode* root, string word) {
        //base case
        if(word.size() == 0) {
            return root->isTerminal;
        }

        int index = word[0]- 'A';
        TrieNode* child;

        // present
        if(root->children[index] != nullptr) {
            child = root->children[index];
        }
        else {
            //absent
            return false;
        }

        // rest recursion will handle
        return searchUtil(child, word.substr(1));
    }
    
    bool searchWord(string word) {
        return searchUtil(root, word);
    }




    // try to write the code for removal

};






int main() {

    Trie* t = new Trie();

    t->insertWord("ABCD");

    cout<<"present or not : " <<t->searchWord("ABCE") <<endl;

    return 0;
}