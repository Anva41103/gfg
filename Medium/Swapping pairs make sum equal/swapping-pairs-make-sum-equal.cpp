//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
bool bs(int a[], int n, int s) {
        int b = 0, e = s - 1;
        while (b <= e) {
            int m = (b + e) / 2;
            if (a[m] == n) return true;
            if (a[m] > n) e = m - 1;
            else b = m + 1;
        }
        return false;
    }
  public:
    int findSwapValues(int a[], int n, int b[], int m) {
        // Your code goes here
        sort(b, b + m);
        int sumA = accumulate(a, a + n, 0);
        int sumB = accumulate(b, b + m, 0);
        int diff = sumA - sumB;
        if (diff % 2 != 0) return -1;
        diff /= 2; 
        for (int i = 0; i < n; ++i) {
            int target = a[i] - diff;
            if (bs(b, target, m)) return 1;
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
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends