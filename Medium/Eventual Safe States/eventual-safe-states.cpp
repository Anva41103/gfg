//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int v, vector<int> adj[]) {
        // code here
        int inc[v]={0};
        vector <int> adji[v];
	    queue <int> q;
	    for(int i=0;i<v;i++)
	    {
	        for(auto it: adj[i])
	    {
	        adji[it].push_back(i);
	        inc[i]++;
	    }
	    }
	    for(int i=0;i<v;i++)
	    {
	        if(inc[i]==0) q.push(i);
	    }
	    vector<int> topo;
	    while(!q.empty())
	    {
	        int j= q.front();
	        q.pop();
	        topo.push_back(j);
	        for(auto it: adji[j])
	        {
	            inc[it]--;
	            if(inc[it]==0) q.push(it);
	        }
	    }
	    sort(topo.begin(), topo.end());
	    return topo;
	    //else return {};
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