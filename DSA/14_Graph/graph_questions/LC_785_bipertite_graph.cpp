#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;

//A bipartite graph can be colored with two colors such that no two adjacent vertices share the same color.

class Solution {
private:
    bool dfs(unordered_map<int, list<int>>& adjList, vector<int>& colorArr, int color, int node) {

        colorArr[node] = color;

        for(auto neighbour : adjList[node]) {
            if(colorArr[neighbour] == -1) {
                if(dfs(adjList, colorArr, !color, neighbour) == 0) 
                    return false;
            }
            else if(colorArr[neighbour] == color) 
                return false;
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        unordered_map<int, list<int>> adjList;
        //preparing adj list
        for(int i=0; i<graph.size(); i++) {
            for(auto j : graph[i]) {
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }

        vector<int> colorArr(graph.size(), -1);

        for(int i=0; i<graph.size(); i++) {
            if(colorArr[i] == -1) {
                if(!dfs(adjList, colorArr, 0, i))
                    return false;
            }
        }
        return true;
    }
};

int main() {
    vector<vector<int>> graph = {{1,3},{0,2},{1,3},{0,2}};
    Solution s;
    bool ans = s.isBipartite(graph);
    if(ans) cout<<"Graph is bipertite"<<endl;
    else cout<<"Not a bipertite graph"<<endl;

    return 0;
}