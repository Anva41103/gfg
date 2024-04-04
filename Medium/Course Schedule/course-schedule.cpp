//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        //code here
         vector <int> adj[n];
	    for(auto it: prerequisites)
	    {
	        adj[it[0]].push_back(it[1]);
	    }
	    int inc[n]={0};
	    for(int i=0;i<n;i++)
	    {
	        for(auto it: adj[i])
	        {
	            inc[it]++;
	        }
	    }
	    queue <int> q;
	    for(int i=0;i<n;i++)
	    {
	        if(inc[i]==0) q.push(i);
	    }
	    int h=0;
	    vector <int> topo;
	    while(!q.empty())
	    {
	        int j= q.front();
	        h++;
	        topo.push_back(j);
	        q.pop();
	        for(auto it: adj[j])
	        {
	            inc[it]--;
	            if(inc[it]==0) q.push(it);
	        }
	    }
	     if(h!=n) return {};
        reverse(topo.begin(),topo.end());
	    return topo;
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends