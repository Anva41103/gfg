//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template in C++

class Solution {
  public:
    // Function to find minimum number of pages.
    bool isposs(int arr[], int p, int m, int n)
{
    long long s=1;
    long long pages=0;
    for(long long i=0;i<n;i++)
    {
        int it=arr[i];
        if(pages+it<=p) pages+=it;
        else {
            s++;
            pages=it;
        }
    }
    return s>m;
}
    long long findPages(int n, int arr[], int m) {
        // code here
        if(m>n) return -1;
    long long l=*max_element(arr,arr+n);
    long long h= accumulate(arr,arr+n,0);
    while(l<=h)
    {
        long long mid=(l+h)/2;
        if(isposs(arr,mid,m,n)) l=mid+1;
        else h=mid-1;
    }
    return l;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(n, A, m) << endl;
    }
    return 0;
}

// } Driver Code Ends