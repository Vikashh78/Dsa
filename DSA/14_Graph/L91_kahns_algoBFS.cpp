#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<list>
#include<unordered_set>
using namespace std;

int main() {
    vector<vector<int>> edges = {
        {1, 2},
        {1, 3},
        {3, 5},
        {2, 5},
        {5, 4}
    };

    unordered_map<int, list<int>> adjList;
    for (auto &e : edges) {
        int u = e[0], v = e[1];
        adjList[u].push_back(v);
    }

    
    // Step 0: Collect all unique nodes
    unordered_set<int> nodes;
    int maxNode = 0;
    for (auto &e : edges) {
        nodes.insert(e[0]);
        nodes.insert(e[1]);
        maxNode = max(maxNode, max(e[0], e[1]));
    }

    // Step 1: indegree vector sized to maxNode
    vector<int> indegree(maxNode + 1, 0);
    for (auto i : adjList) {
        for (auto j : i.second) {
            indegree[j]++;
        }
    }

    // Step 2: push only real nodes with indegree 0
    queue<int> q;
    for (auto node : nodes) {
        if (indegree[node] == 0) {
            q.push(node);
        }
    }

    // Step 3: BFS logic
    vector<int> ans;
    while (!q.empty()) {
        int frontNode = q.front();
        q.pop();

        ans.push_back(frontNode);

        for (auto neighbour : adjList[frontNode]) {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0) {
                q.push(neighbour);
            }
        }
    }

    // printing ans
    cout << "Kahn's algo topological sort order: ";
    for (int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}
