#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

//catch ** extract parent, curr ko destn ke equal karo and loop chalo jab tak curr source ke equal na ho jaye and then the values in ans and reveses the ans

//T: O(N+E)
//S: O(N+E)

int main() {

    int n = 8;
    vector<vector<int>> edges = {
        {1,2}, {2,3}, {3,8},
        {1,4}, {4,8}, {1,5},
        {5,6}, {6,7}, {7,8}
    };

    int s = 1, d = 8;

    // 1. Build adjacency list
    unordered_map<int, list<int>> adjList;
    for(auto &e : edges) {
        int u = e[0], v = e[1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // 2. BFS
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    queue<int> q;

    visited[s] = true;
    parent[s] = -1;
    q.push(s);

    while(!q.empty()) {
        int frontNode = q.front();
        q.pop();

        for(auto neighbour : adjList[frontNode]) {
            if(!visited[neighbour]) {
                visited[neighbour] = true;
                parent[neighbour] = frontNode;
                q.push(neighbour);
            }
        }
    }

    // 3. Reconstruct path if destination is reachable
    vector<int> ans;
    if(!visited[d]) {
        cout << "No path found from " << s << " to " << d << endl;
        return 0;
    }

    int curr = d;
    while(curr != -1) {
        ans.push_back(curr);
        curr = parent[curr];
    }

    reverse(ans.begin(), ans.end());

    // 4. Print path
    cout << "Shortest path from " << s << " to " << d << " is: ";
    for(int node : ans) cout << node << "-> ";
    cout << endl;

    return 0;
}
