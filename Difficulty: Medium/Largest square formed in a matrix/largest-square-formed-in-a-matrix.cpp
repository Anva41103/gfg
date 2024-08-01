//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxSquare(int n, int m, vector<vector<int>> mat) {
        // code here
        int maxlength = 0;

        // Iterate over the matrix to find the maximum square sub-matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Only process cells that are 1
                if (mat[i][j] == 1) {
                    // If we're not in the first row or column, calculate the size of the largest square ending at (i, j)
                    if (i > 0 && j > 0) {
                        mat[i][j] = min({mat[i-1][j], mat[i][j-1], mat[i-1][j-1]}) + 1;
                    }
                    // Update the maximum length
                    maxlength = max(maxlength, mat[i][j]);
                }
            }
        }
        
        // Return the size of the largest square sub-matrix
        return maxlength;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (int i = 0; i < n * m; i++)
            cin >> mat[i / m][i % m];

        Solution ob;
        cout << ob.maxSquare(n, m, mat) << "\n";
    }
    return 0;
}
// } Driver Code Ends