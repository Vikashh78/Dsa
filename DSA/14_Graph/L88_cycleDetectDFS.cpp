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


bool isCycleDFS(int node, int parent, unordered_map<int, bool> &visited, unordered_map<int, set<int>> &adj) {

    visited[node] = true;

    //har connected node k liye recursive call
    for(auto neighbour : adj[node]) { //adj[node] returns a set<int> of all neighbors
        if(!visited[neighbour]) {
            bool cycleDetected = isCycleDFS(neighbour, node, visited, adj);
            // If a cycle is found in deeper DFS, return true
            if(cycleDetected) return true;
        }
        // If neighbor is visited and not the parent, it's a cycle
        else if (neighbour != parent) {
            return true;
        }  
    }
    return false;
}


int main () {

    // int n = 6;
    
    vector<vector<int>> adjVector = {
        {1,2},
        {2,4},
        {4,5},
        {5,6},
        {5,3},
        {3,2}
    };

    unordered_map<int, set<int> > adj;
    unordered_map<int, bool> visited;
    vector<vector<int>> result;

    createAdj(adjVector, adj);

    bool cycleFound = false;

    for(auto &pair : adj) {
        int node = pair.first;
        if(!visited[node]) {
            // parent is -1 for first node
            if(isCycleDFS(node, -1, visited, adj)) {
                cycleFound = true;
                break;
            } 
        }
    }

    if(cycleFound) cout << "Cycle is present" << endl;
    else cout << "Cycle is not present" << endl;

    return 0;
}