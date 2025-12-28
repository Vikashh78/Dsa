#include <iostream>
using namespace std;
#include <list>
#include <unordered_map>
#include <vector>
#include <stack> // ***

// Topological Sort of a Directed Acyclic Graph (DAG) is a linear ordering of its vertices such that for every directed edge u → v, 
//vertex u comes before vertex v in the ordering.

// O(N+E)
// O(N)

void topologicalSortDAG(int node, unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited, stack<int> &st)
{

    visited[node] = true;

    for (auto neighbour : adjList[node]) {
        if (!visited[neighbour]) {
            topologicalSortDAG(neighbour, adjList, visited, st);
        }
    }

    // this is the catch* (on returning from recursive calls)
    st.push(node);
}



int main() {

    vector<vector<int>> edges = {
        {1, 2},
        {1, 3},
        {3, 4},
        {2, 4},
        {4, 5},
        {4, 6},
        {5, 6}};

    unordered_map<int, list<int>> adjList;
    // creating adjList
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v); // directed graph
    }

    unordered_map<int, bool> visited;
    stack<int> st;

    for (auto &pair : adjList)
    {
        int node = pair.first;
        if (!visited[node])
        {
            topologicalSortDAG(node, adjList, visited, st);
        }
    }

    cout << "Topological sort order for Directed acyclic graph is : ";
    while (!st.empty())
    {
        int temp = st.top();
        st.pop();
        cout << temp << " ";
    }
    cout << endl;

    return 0;
}