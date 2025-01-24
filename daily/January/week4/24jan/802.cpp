#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Helper function to detect a cycle using DFS
    bool isCycleDFS(vector<vector<int>>& adj, int u, vector<bool>& visited, vector<bool>& inRecursion) {
        visited[u] = true;
        inRecursion[u] = true; // Mark the node as part of the current recursion stack
        
        for (int &v : adj[u]) {
            // If the node is not visited, check for a cycle through DFS
            if (!visited[v] && isCycleDFS(adj, v, visited, inRecursion))
                return true;
            // If the node is already in the recursion stack, a cycle is detected
            else if (inRecursion[v])
                return true;
        }
        
        inRecursion[u] = false; // Backtrack and remove the node from the recursion stack
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<bool> visited(V, false); // Track visited nodes
        vector<bool> inRecursion(V, false); // Track nodes in the current recursion stack
        
        // Perform DFS for each node
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                isCycleDFS(graph, i, visited, inRecursion);
            }
        }
        
        // Collect all nodes that are not part of any cycle (safe nodes)
        vector<int> safeNodes;
        for (int i = 0; i < V; i++) {
            if (!inRecursion[i]) {
                safeNodes.push_back(i);
            }
        }
        
        return safeNodes;
    }
};

int main() {
    Solution sol;

    // Example input graph (adjacency list)
    vector<vector<int>> graph = {
        {1, 2},
        {2, 3},
        {5},
        {0},
        {5},
        {},
        {4}
    };

    // Get the safe nodes
    vector<int> safeNodes = sol.eventualSafeNodes(graph);

    // Print the result
    cout << "Safe nodes: ";
    for (int node : safeNodes) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
