//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void bfsr(int r, int c, vector <vector <int>> &vis,vector<vector<char>>& grid,int n, int m )
    {
     vis[r][c]=1;
     queue <pair<int,int>> q;
     q.push({r,c});
     while(!q.empty())
     {
         int row= q.front().first;
         int col=q.front().second;
         q.pop();
         for(int i=-1;i<=1;i++)
     {
         for(int j=-1;j<=1;j++)
         {
             int a=row+i;
             int b=col+j;
             if(a>=0&&a<n&&b>=0&&b<m&&vis[a][b]!=1&&grid[a][b]=='1')
             {
                 vis[a][b]=1;
                 q.push({a,b});
             }
         }
     }
     }
     
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n= grid.size();
        int m= grid[0].size();
        vector <vector<int>> vis(n, vector <int>(m,0));
        int c=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j]&&grid[i][j]=='1')
                {
                    c++;
                    bfsr(i,j,vis, grid,n,m);
                }
            }
        }
        return c;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends