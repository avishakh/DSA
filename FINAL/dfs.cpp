#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Function to add an edge to the graph
void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);            // Directed edge
    // adj[v].push_back(u);         // Uncomment this for undirected graph
}

// Recursive DFS function
void dfsUtil(int u, const vector<vector<int>>& adj, vector<bool>& visited, vector<int>& parent) {
    visited[u] = true;
    cout << u << " ";

    for (int v : adj[u]) {
        if (!visited[v]) {
            parent[v] = u;  // Set parent to trace the path
            dfsUtil(v, adj, visited, parent);
        }
    }
}

// DFS wrapper
void dfs(int startNode, const vector<vector<int>>& adj, vector<int>& parent) {
    int numNodes = adj.size();
    vector<bool> visited(numNodes, false);
    parent[startNode] = -1;

    cout << "DFS Traversal starting from node " << startNode << ": ";
    dfsUtil(startNode, adj, visited, parent);
    cout << endl;
}

// Print path from start to destination using parent array
void printPath(const vector<int>& parent, int destinationNode, int startNode) {
    if (destinationNode == startNode) {
        cout << startNode;
        return;
    }
    if (parent[destinationNode] == -1) {
        cout << "No path exists from " << startNode << " to " << destinationNode << endl;
        return;
    }
    printPath(parent, parent[destinationNode], startNode);
    cout << " -> " << destinationNode;
}

int main() {
    int numNodes, numEdges;

    // Input number of nodes and edges
    cout << "Enter the number of nodes in the graph: ";
    cin >> numNodes;
    if (numNodes <= 0) {
        cout << "Number of nodes must be positive." << endl;
        return 1;
    }

    cout << "Enter the number of edges in the graph: ";
    cin >> numEdges;
    if (numEdges < 0) {
        cout << "Number of edges cannot be negative." << endl;
        return 1;
    }

    // Create adjacency list
    vector<vector<int>> adj(numNodes);

    // Input edges
    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < numEdges; ++i) {
        int u, v;
        cin >> u >> v;
        if (u < 0 || u >= numNodes || v < 0 || v >= numNodes) {
            cout << "Invalid edge (" << u << ", " << v << "). Nodes must be in range 0 to " << numNodes - 1 << "." << endl;
            return 1;
        }
        addEdge(adj, u, v);
    }

    // Input starting node
    int startNode;
    cout << "Enter the starting node for DFS (0 to " << numNodes - 1 << "): ";
    cin >> startNode;
    if (startNode < 0 || startNode >= numNodes) {
        cout << "Invalid starting node." << endl;
        return 1;
    }

    // Store parents to print paths
    vector<int> parent(numNodes, -1);

    // Perform DFS
    dfs(startNode, adj, parent);

    // Path queries
    int destinationNode;
    while (true) {
        cout << "Enter a destination node to find the path from " << startNode << " (or -1 to exit): ";
        cin >> destinationNode;
        if (destinationNode == -1) break;

        if (destinationNode < 0 || destinationNode >= numNodes) {
            cout << "Invalid node. Please enter a value between 0 and " << numNodes - 1 << "." << endl;
            continue;
        }

        cout << "Path from " << startNode << " to " << destinationNode << ": ";
        printPath(parent, destinationNode, startNode);
        cout << endl;
    }

    return 0;
}
