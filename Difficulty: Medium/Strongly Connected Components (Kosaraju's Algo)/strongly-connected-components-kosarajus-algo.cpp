//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	void dfs(int node, vector <vector <int>> &adj,vector <int> &vis, stack <int>& st)
	{
	    vis[node]=1;
	    for(auto it:adj[node])
	    {
	        if(!vis[it]) dfs(it, adj,vis,st);
	    }
	    st.push(node);
	}
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        stack <int> st;
        vector <int> vis(V,0);
         for (int i = 0; i < V; ++i) {
            if (!vis[i]) {
                dfs(i, adj, vis, st);
            }
        }
        vector <vector <int>> adj2(V);
        for (int u = 0; u < V; ++u) {
    for (int v : adj[u]) {
        adj2[v].push_back(u); // Reverse the direction of each edge
    }
}
int ans=0;
        vector <int>v(V,0);
        stack <int> s;
        while(!st.empty())
        {
            if(!v[st.top()]) {ans++; dfs(st.top(),adj2,v,s);}
            st.pop();
        }
        return ans;
        
        
        
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends