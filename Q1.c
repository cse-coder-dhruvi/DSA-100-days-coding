#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> kahnTopoSort(int V, vector<pair<int, int>> edges) {
    // Step 1: Adjacency list
    vector<vector<int>> adj(V);

    // Step 2: In-degree array
    vector<int> indegree(V, 0);

    // Build graph
    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v);
        indegree[v]++;
    }

    // Step 3: Queue for nodes with 0 in-degree
    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topo;

    // Step 4: Process queue
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for (int neighbor : adj[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // Step 5: Check cycle
    if (topo.size() != V) {
        cout << "Cycle exists, Topological Sort not possible\n";
        return {};
    }

    return topo;
}

int main() {
    int V = 6;
    vector<pair<int, int>> edges = {
        {5, 2}, {5, 0}, {4, 0}, {4, 1}, {2, 3}, {3, 1}
    };

    vector<int> result = kahnTopoSort(V, edges);

    cout << "Topological Order: ";
    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}
