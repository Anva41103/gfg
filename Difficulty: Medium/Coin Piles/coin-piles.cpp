//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minSteps(int A[], int N, int K) {
        // code here
        sort(A, A+N);
        vector<int>pref(N, 0);
        pref[0]=A[0];
        for(int i=1;i<N;i++){
            pref[i]=pref[i-1]+A[i];
        }
        int ans=INT_MAX;
        int start=0;
        
        for(int i=0;i<N;i++){
            int ind=upper_bound(A, A+N, A[i]+K)-A;
            
            if(i>0 && A[i]!=A[i-1]){
                start=pref[i-1]; //for handling duplicates
            }
            
            ans=min(ans, start+pref[N-1]-pref[ind-1]-(N-ind)*(A[i]+K));
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin>>N>>K;
        
        int A[N];
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.minSteps(A,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends