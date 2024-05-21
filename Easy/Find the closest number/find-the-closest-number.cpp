//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int findClosest( int n, int target,int A[]) 
    { 
        // Complete the function
         int start = 0;
        int end = n - 1;
        
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (A[mid] <= target) {
                start = mid;
            } else {
                end = mid;
            }
        }
        
        // Now check which of A[start] or A[end] is closer to target
        int leftDiff = abs(A[start] - target);
        int rightDiff = abs(A[end] - target);
        
        if (leftDiff < rightDiff) {
            return A[start];
        } else {
            return A[end];
        }
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(n,k,arr)<<endl;
    }
}

// } Driver Code Ends