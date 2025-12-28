/*You are given a list / array of strings which denotes the contacts that exist in your phone directory.The search query on a string
‘str’ which is a query string displays all the contacts which are present in the given directory with the prefix as ‘str’. */

#include <iostream>
using namespace std;
#include <vector>

/*
M = length of the query string
K = number of suggestions for a given prefix
L = average length of the suggestions returned,  Let’s assume total number of suggestions collected over all prefixes = T
TC : O(M*T*L) = SC 
*/

class TrieNode {                 

    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

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
            root->children[index] = child; 
        }

        // for rest, there is recursion
        insertUtil(child, word.substr(1));
    }
    void insertWord(string word) {
        insertUtil(root, word);
    }





    //print suggestion 
    void printSuggestions(TrieNode* curr, vector<string>& temp, string prefix) {
        // base case
        if(curr->isTerminal) {
            temp.push_back(prefix);
        }

        for(char ch = 'a'; ch < 'z'; ch++) {
            
            // create node next
            TrieNode* next = curr->children[ch - 'a'];

            if(next != nullptr) {
                prefix.push_back(ch);

                // recursive call
                printSuggestions(next, temp, prefix);

                // prefix.pop_back();
            }
        }
    }

    // get suggestion function
    vector<vector<string>> getSuggestion(string str) {

        TrieNode* prev = root;  //pointer
        vector<vector<string>> output;
        string prefix = "";

        for(int i=0; i<str.size(); i++) {
            char lastCh = str[i];

            prefix.push_back(lastCh);

            //check for last character
            TrieNode* curr = prev->children[lastCh - 'a'];    // curr pointer jo prev pointer ka next wala hai

            // agar absent hai
            if(curr == nullptr) {
                break;
            }

            // agar char present hai, to uske aage ke sare character print kar do
            vector<string> temp;

            printSuggestions(curr, temp, prefix);

            output.push_back(temp);
            temp.clear();
            prev = curr;
        }
        return output;
    }
};


int main() {

    Trie* t = new Trie('\0');

    vector<string>contactList = {"cod","coding","codding","code","coly"};
    string queryStr = "coding";


    // insert all the strings into the trie
    for(int i=0; i<contactList.size(); i++) {
        string str = contactList[i];
        t->insertWord(str);
    }

    vector<vector<string>> ans = t->getSuggestion(queryStr);
    //printing the ans
    for(int i=0; i<ans.size(); i++) {
        for(int j=0; j<ans[i].size(); j++) {
            cout<< ans[i][j] <<" ";
        }
        cout<<endl;
    }


    return 0;
}