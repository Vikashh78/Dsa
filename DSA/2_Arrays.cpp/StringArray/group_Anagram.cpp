/*Given an array of strings strs, group the anagrams together. You can return the answer in any order.

LeetCode - 49 

Example 1:
Input: strs = ["eat","tea","tan","ate","nat","bat"]

Output: [["bat"],["nat","tan"],["ate","eat","tea"]] */

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int main() {
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    unordered_map<string, vector<string>> mp;

    // Group words by sorted key
    for(auto x: strs){
        string word = x;
        sort(word.begin(), word.end());
        mp[word].push_back(x);
    }

    vector<vector<string>> ans;
    for(auto x: mp){
        ans.push_back(x.second);
    }

    // Print the grouped anagrams
    for(int i=0; i<ans.size(); i++) {
        for(int j=0; j<ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}