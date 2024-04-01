//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(vector<int> adj[], vector<int>& path, vector<int>& vis, int n) {
    path[n] = 1;
    vis[n] = 1;
    for (int it : adj[n]) {
        if (!vis[it]) {
            if (dfs(adj, path, vis, it)) return true;
        } else if (path[it]) {
            return true;
        }
    }
    path[n] = 0;
    return false;
}
    bool isCyclic(int v, vector<int> adj[]) {
        // code here
    vector<int> vis(v, 0);
    vector<int> path(v, 0);
    for (int i = 0; i < v; ++i) {
        if (!vis[i] && dfs(adj, path, vis, i)) return true;
    }
    return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends