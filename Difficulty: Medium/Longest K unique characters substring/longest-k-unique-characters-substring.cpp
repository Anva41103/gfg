//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
     unordered_map <char, int> mp;
     int f=0;
        int l=0, r=0, m=0;
        while(r<s.length())
        {
            mp[s[r]]++;
            if(mp.size()>k)
            {
                mp[s[l]]--;
                if(mp[s[l]]==0) mp.erase(s[l]);
                l++;
            }
            if(mp.size()==k) { f=1; m= max(m,r-l+1);}
            r++;
        }
        if(!f) return -1;
        return m;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends