//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int dfs(int n, int m, int i, int j, int l, vector <vector <int>> &vis,vector<vector<int>>& mat, vector <vector<int>> &dp)
  {
     if (i < 0 || i >= n || j < 0 || j >= m) return 0; 
      if(dp[i][j]!=-1) return dp[i][j];
      int r[5]={0,1,0,-1,0};
      vis[i][j]=1;
      int y=l;
      for(int k=0;k<4;k++)
      {
          int nx=i+r[k];
          int ny=j+r[k+1];
          if(nx>=0&&nx<n&&ny>=0&&ny<m&&!vis[nx][ny]&&mat[nx][ny]>mat[i][j])
          {
              y= max(y,1+dfs(n,m,nx,ny,l,vis, mat,dp));
          }
      }
      vis[i][j]=0;
      return dp[i][j]=y;
  }
    int longestIncreasingPath(vector<vector<int>>& mat, int n, int m) {

        // Code here
        vector <vector <int>> vis(n, vector <int>(m,0));
        int forall=0;
        vector <vector <int>> dp(n, vector <int>(m,-1));
         for (int i = 0; i < n; i++) {  // Changed: Loop over all rows.
        for (int j = 0; j < m; j++) {  // Changed: Loop over all columns.
            forall = max(forall, dfs(n, m, i, j, 1, vis, mat,dp));  // Changed: Start DFS from each cell.
        }
    }
        return forall;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        cout << obj.longestIncreasingPath(matrix, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends