//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        int mod=100000;
        vector<int> mult(100000,1e9);
        mult[start]=0;
        queue <pair<int,int>> q;
        q.push({start,0});
        while(!q.empty())
        {
            int n=q.front().first;
            int d=q.front().second;
            q.pop();
            for(auto it:arr)
            {
                int num=(it*n)%mod;
                if(d+1<mult[num])
                {
                    mult[num]=d+1;
                    if(num==end) return mult[num];
                    q.push({num,d+1});
                }
            }
        }
        if(start==end) return 0;
        return -1;
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends