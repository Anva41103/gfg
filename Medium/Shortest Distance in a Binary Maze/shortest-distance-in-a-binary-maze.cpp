//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        queue <pair<int, pair<int,int>>> q;
        int r[]={0,1,-1,0};
        int c[]={1,0,0,-1};
        int n= grid.size();
        int m= grid[0].size();
        vector <vector<int>> dist(n,vector <int>(m,1e9));
        dist[source.first][source.second]=0;
        q.push({0,source});
        if(source==destination) return 0;
        while(!q.empty())
        {
            int d=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int ro=x+r[i];
                int co=y+c[i];
                if(ro>=0&&ro<n&&co>=0&&co<m&grid[ro][co]==1&&d+1<dist[ro][co])
                {
                    if(ro==destination.first&&co==destination.second) return d+1;
                    dist[ro][co]=d+1;
                    q.push({d+1,{ro,co}});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends