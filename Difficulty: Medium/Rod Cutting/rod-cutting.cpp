//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   int helper(vector <vector <int>> &dp,vector <int> &prices, int target, int ind)
    {
        if(ind==0){if(target%(ind+1)==0) {int k=target/(ind+1); return k*prices[ind];}
        else return -1e9;}
        if(dp[ind][target]!=-1) return dp[ind][target];
        int t=helper(dp,prices,target,ind-1);
        int nt=INT_MIN;
        if(target>=ind+1)
        {
           nt=prices[ind]+helper(dp,prices,target-ind-1,ind);
        }
         return dp[ind][target]=max(t,nt);
    }
    int cutRod(vector<int> &prices) {
        // code here
         int n=prices.size();
        vector <vector <int>> dp(n,vector <int>(n+1,-1));
        return helper(dp,prices,n,n-1);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;

        cout << ob.cutRod(a) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends