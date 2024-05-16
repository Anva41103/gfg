//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long mincoin(vector<vector<long long int>> &dp, int coins[], int am, int ind) {
    if (am == 0) return 1;  // There is one way to make amount 0: using no coins
    if (ind < 0) return 0;  // No way to make a positive amount with no coins
    if (dp[ind][am] != -1) return dp[ind][am];
    
    // Exclude the current coin
    long long int nt = mincoin(dp, coins, am, ind - 1);
    
    // Include the current coin, if it can be part of the solution
    long long int t = 0;
    if (am >= coins[ind]) t = mincoin(dp, coins, am - coins[ind], ind);
    
    return dp[ind][am] = t + nt;
}
    long long int count(int coins[], int N, int sum) {

        // code here.
        vector <vector <long long int>> dp(N, vector <long long int> (sum+1,-1));
        long long r=mincoin(dp,coins,sum,N-1);
        return r;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends