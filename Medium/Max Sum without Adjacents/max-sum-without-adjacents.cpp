//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int fun(vector <int>&dp, int *a, int n)
	{
	    if(n==0) return a[n];
	    if(n<0) return 0;
	    if(dp[n]!=-1) return dp[n];
	    int pick= a[n]+fun(dp,a,n-2);
	    int notpick= 0+fun(dp,a,n-1);
	    return dp[n]= max(pick,notpick);
	}
	int findMaxSum(int *arr, int n) {
	    // code here
	    vector <int> v(n,-1);
	    return fun(v,arr,n-1);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends