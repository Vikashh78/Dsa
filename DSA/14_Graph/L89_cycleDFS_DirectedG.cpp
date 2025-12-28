#include<iostream>
using namespace std;
#include<unordered_map>
#include<set>
#include<vector>

void createAdj(vector<vector<int>> &edges, unordered_map<int, set<int>> &adjList) {
    for(int i=0; i<edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        //for directed graph
        adjList[u].insert(v);
    }
}


bool isDirectedCycleDFS(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited, unordered_map<int, set<int>> &adjList) {

    visited[node] = true;
    dfsVisited[node] = true;

    for(auto &neighbour : adjList[node]) {
        if(!visited[neighbour]) {
            if(isDirectedCycleDFS(neighbour, visited, dfsVisited, adjList)) {
                return true;
            }
        } //visited[neighbour] == true
        else if(dfsVisited[neighbour]) {
            return true;
        }
    }

    //while returning from recursive calls
    dfsVisited[node] = false; 
    return false;
}



int main() {

    vector<vector<int>> edges = {
        {1,2},
        {1,4},
        {4,2},
        {1,3},
        {3,5},
        {5,6},
        {6,3}
    };

    unordered_map<int, set<int>> adjList;
    createAdj(edges, adjList);

    unordered_map<int, bool> visited;

    //this map is extra in directed graph*
    unordered_map<int, bool> dfsVisited;

    bool cycle = 0;
    for(auto &pair : adjList) {
        int node = pair.first;
        if(!visited[node]) {
            if(isDirectedCycleDFS(node, visited, dfsVisited, adjList)) {
                cycle = true;
                break;
            }
        }
    }

    if(cycle) cout<<"cycle present in directed graph" <<endl;
    else cout<<"cycle not present" <<endl;

    return 0;
}