//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int v, vector<int> adj[]) {
        // code here
        int inc[v]={0};
	    queue <int> q;
	    for(int i=0;i<v;i++)
	    {
	        for(auto it: adj[i])
	    {
	        inc[it]++;
	    }
	    }
	    for(int i=0;i<v;i++)
	    {
	        if(inc[i]==0) q.push(i);
	    }
	    int topo=0;
	    while(!q.empty())
	    {
	        int j= q.front();
	        q.pop();
	        topo++;
	        for(auto it: adj[j])
	        {
	            inc[it]--;
	            if(inc[it]==0) q.push(it);
	        }
	    }
	    if(topo==v) return false;
	    else return true;
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