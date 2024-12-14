//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  bool helper(vector <int>& nums,vector <vector <int>> &dp, int t, int ind)
  {
      if(ind<0) return false;
      if(t==0) return true;
      if(ind==0) return nums[ind]==t;
      if(dp[ind][t]!=-1) return dp[ind][t];
      bool nottaken= helper(nums,dp,t,ind-1);
      bool taken=false;
      if(t>=nums[ind]) taken=helper(nums,dp,t-nums[ind],ind-1);
      return dp[ind][t]=taken||nottaken;
      
  }
    bool isSubsetSum(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        vector <vector <int>> dp(n,vector <int>(target+1,-1));
        return helper(arr,dp,target,n-1);
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends