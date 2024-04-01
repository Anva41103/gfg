//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   bool dfs(vector<int> adj[], vector<int>& path, vector<int>& vis, int n, int check[]) {
    path[n] = 1;
    vis[n] = 1;
    check[n]=0;
    for (int it : adj[n]) {
        if (!vis[it]) {
            if (dfs(adj, path, vis, it,check)) return true;
        } else if (path[it]) {
            return true;
        }
    }
    check[n]=1;
    path[n] = 0;
    return false;
}
    vector<int> eventualSafeNodes(int v, vector<int> adj[]) {
        // code here
        vector<int> vis(v, 0);
    vector<int> path(v, 0);
    int check[v]={0};
    vector <int> ans;
    for (int i = 0; i < v; ++i) {
        if(!vis[i]) dfs(adj, path, vis, i,check);
    }
    for(int i=0;i<v;i++)
    {
        if(check[i]) ans.push_back(i);
    }
    //reverse(ans.begin(),ans.end());
        return ans;
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends