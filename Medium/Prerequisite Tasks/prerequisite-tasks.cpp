//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int n,int p, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector <int> adj[n];
	    for(auto it: prerequisites)
	    {
	        adj[it.first].push_back(it.second);
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
	    while(!q.empty())
	    {
	        int j= q.front();
	        h++;
	        q.pop();
	        for(auto it: adj[j])
	        {
	            inc[it]--;
	            if(inc[it]==0) q.push(it);
	        }
	    }
	    if(h==n) return true;
	    else return false;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends