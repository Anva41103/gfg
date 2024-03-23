//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
void dfsr(int sr, int sc,vector<vector<int>>& image,vector<vector<int>>& ans, int nc, int ic, int n, int m, int dc[], int dr[])
{
    ans[sr][sc]=nc;
    for(int i=0;i<4;i++)
    {
            int r= sr+dr[i];
            int c= sc+dc[i];
            if(r>=0&&r<n&&c>=0&&c<m&&image[r][c]==ic&&ans[r][c]!=nc)
            {
                dfsr(r,c,image, ans, nc,ic, n,m,dc,dr);
            }
    }
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int n= image.size();
        int m= image[0].size();
        vector <vector <int>> ans=image;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        dfsr(sr,sc,image, ans, newColor,image[sr][sc],n,m,dc,dr);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends