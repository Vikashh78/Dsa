#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>
#include<set>

void createAdj(vector<vector<int>> &adjVector, unordered_map<int, set<int>> &adj) {
    
    for(int i=0; i<adjVector.size(); i++) {
        int u = adjVector[i][0];
        int v = adjVector[i][1];

        adj[u].insert(v);
        adj[v].insert(u);
    }
}


void dfs(int node, unordered_map<int, bool> &visited, unordered_map<int, set<int>> &adj, vector<int> &ans) {

    ans.push_back(node);
    visited[node] = true;

    //har connected node k liye recursive call
    for(auto i : adj[node]) { //adj[node] returns a set<int> of all neighbors
        if(!visited[i]) {
            dfs(i, visited, adj, ans);
        }
    }
}


int main () {

    int n = 5;
    
    vector<vector<int>> adjVector = {
        {4,5},
        {4,7},
        {5,8},
        {7,9},
        {8,9}
    };

    unordered_map<int, set<int> > adj;
    unordered_map<int, bool> visited;
    vector<vector<int>> result;

    createAdj(adjVector, adj);

    for(auto &pair : adj) {
        int node = pair.first;
        if(!visited[node]) {
            vector<int> ans;
            dfs(node, visited, adj, ans);
            result.push_back(ans);
        }
    }

    for(int i=0; i<result.size(); i++) {
        for(int j=0; j<result[i].size(); j++) {
            cout<<result[i][j] <<" ";
        }
    } cout <<endl;

    return 0;
}