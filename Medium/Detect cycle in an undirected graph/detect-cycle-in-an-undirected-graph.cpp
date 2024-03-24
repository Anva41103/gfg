//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool det(int src, int vis[], vector <int> adj[])
    {
        vis[src]=1;
        queue <pair<int,int>> q;
        q.push({src,-1});
        while(!q.empty())
        {
            int parent= q.front().second;
            int n= q.front().first;
            q.pop();
            for(auto it: adj[n])
            {
                if(vis[it]==0)
                {
                    vis[it]=1;
                    q.push({it,n});
                }
                else
                {
                    if(it!=parent) return true;
                }
            }
            
        }
        return false;
    }
    bool dfs(int n,int p, int vis[], vector <int> adj[])
    {
         vis[n]=1;
            for(auto it: adj[n])
            {
                if(vis[it]==0)
                {
                    if(dfs(it,n,vis,adj)) return true;
                }
                else
                {
                    if(it!=p) return true;
                }
            }
            
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int vis[V]={0};
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {if(dfs(i,-1,vis, adj)) return true;}
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends