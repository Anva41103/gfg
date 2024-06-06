//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  void countPrimes(int n,vector <int> &v,vector <int> &s) {
        int c=0;
        for(int i=2;i*i<=n;i++)
        {
            if(v[i]==1)
            {
                for(int j=i*i;j<=n;j+=i)
            {
                v[j]=0;
            }
            }
        }
        for(int i=2;i<v.size();i++) if(v[i]==1) s.push_back(i);
    }
    void sieve() 
    {
        
    }

    vector<int> findPrimeFactors(int n) {

        // Write your code here
        vector <int> v(n+1,1);
        vector <int> s;
        countPrimes(n,v,s);
        vector <int> ans;
        for(int i=0;i<s.size();i++)
        {
            if(n==1) break;
            while(n%s[i]==0)
            {
                ans.push_back(s[i]);
                n/=s[i];
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n;
        cin >> n;

        Solution obj;
        obj.sieve();
        vector<int> vec = obj.findPrimeFactors(n);
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i] << " ";
        }
        cout << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends