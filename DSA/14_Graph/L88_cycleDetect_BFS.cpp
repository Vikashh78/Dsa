#include<iostream>
using namespace std;
#include<unordered_map>
#include<vector>
#include<set>
#include <queue>

bool isCycleBFS(int src, unordered_map<int, bool> &visited, unordered_map<int, set<int> > &adj) {

    //creating a parent
    unordered_map<int, int> parent;

    parent[src] = -1;
    visited[src] = 1;
    queue<int> q;
    q.push(src);

    while(!q.empty()) {
        int frontNode = q.front();
        q.pop();

        for(auto neighbour : adj[frontNode]) {
            if(visited[neighbour] == true && neighbour != parent[frontNode]) {
                return true;
            }
            else if(!visited[neighbour]) {
                q.push(neighbour);
                visited[neighbour] = true;
                parent[neighbour] = frontNode;
            }
        }
    }
    return false;
}


int main() {

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

    //creating adj List
    for(int i=0; i<adjVector.size(); i++) {
        int u = adjVector[i][0];
        int v = adjVector[i][1];

        adj[u].insert(v);
        adj[v].insert(u);
    }

    
    bool cycleDetected = false;
    for(auto &pair : adj) {
        int node = pair.first;
        if(!visited[node]) { 
            if(isCycleBFS(node, visited, adj)) {
                cycleDetected = true;
                break;
            }
        }
    }

    if(cycleDetected) cout<<"Cycle is present" <<endl;
    else cout<<"cycle is not present" <<endl;
    
    return 0;
}