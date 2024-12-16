//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int helper(vector <int> &arr, vector <vector <int>> &dp, int t,int ind)
  {
      if(ind==0)
      {
          if(t==0&&arr[ind]==0) return 2;
          else if(t==0||t==arr[ind]) return 1;
          else return 0;
      }
      if(dp[ind][t]!=-1) return dp[ind][t];
      int nottaken=helper(arr,dp,t,ind-1);
      int taken=0;
      if(arr[ind]<=t) taken=helper(arr,dp,t-arr[ind],ind-1);
      return dp[ind][t]=taken+nottaken;
  }
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        int s= accumulate(arr.begin(),arr.end(),0);
        int t=(s-d)/2;
        if((s-d)%2==1||s-d<0) return 0;
        vector <vector <int>> dp(arr.size(), vector<int>(t+1,-1));
        return helper(arr,dp,t,arr.size()-1);
    }
    // int helper(vector<int>& arr, vector<vector<int>>& dp, int t, int ind) {
    //     if (ind == 0) {
    //         if (t == 0 && arr[ind] == 0) return 2;
    //         if (t == 0 || t == arr[ind]) return 1;
    //         return 0;
    //     }
    //     if (dp[ind][t] != -1) return dp[ind][t];
    //     int notTaken = helper(arr, dp, t, ind - 1);
    //     int taken = 0;
    //     if (arr[ind] <= t) taken = helper(arr, dp, t - arr[ind], ind - 1);
    //     return dp[ind][t] = taken + notTaken;
    // }

    // int countPartitions(vector<int>& arr, int d) {
    //     int s = accumulate(arr.begin(), arr.end(), 0);
    //     if ((s - d) % 2 != 0 || (s - d) < 0) return 0;
    //     int t = (s - d) / 2;
    //     int n = arr.size();
    //     vector<vector<int>> dp(n, vector<int>(t + 1, -1));
    //     return helper(arr, dp, t, n - 1);
    // }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countPartitions(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends