//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  void dfs(int r, int c, vector <vector <int>> &vis, vector<vector<int>>& grid, 
  vector<pair<int,int>> &v, int r0, int c0)
  {
       int n= grid.size();
        int m= grid[0].size();
      vis[r][c]=1;
      v.push_back({r-r0, c-c0});
      int dr[]={-1,0,1,0};
      int dc[]={0,-1,0,1};
      for(int i=0;i<4;i++)
      {
          int nr= r+dr[i];
          int nc=c+dc[i];
          if(nr>=0&&nr<n&&nc>=0&&nc<m && !vis[nr][nc]&&grid[nr][nc]==1) 
          dfs(nr,nc,vis,grid,v,r0,c0);
      }
  }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n= grid.size();
        int m= grid[0].size();
        vector <vector <int>> vis(n, vector <int>(m,0));
        set <vector <pair <int,int>>> s;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j]&&grid[i][j]==1)
                {
                    vector <pair<int,int>> v;
                    dfs(i,j,vis,grid,v,i,j);
                    s.insert(v);
                    
                }
            }
        }
        return s.size();
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
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends