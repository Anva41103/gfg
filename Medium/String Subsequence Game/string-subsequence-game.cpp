//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  bool isv(char x)
  {
      if(x=='a'||x=='e'||x=='i'||x=='u'||x=='o') return true;
      else return false;
  }
  void lol(set <string> &ans, string s, int i, string &k)
  {
      if(i>=s.length()) {if(isv(k[0])&&!isv(k[k.size()-1])) ans.insert(k); return;}
      lol(ans,s,i+1,k);
      k+=s[i];
      lol(ans,s,i+1,k);
      k.pop_back();
  }
    set<string> allPossibleSubsequences(string S) {
        // code here
        set <string> ans;
        string k="";
        lol(ans,S,0,k);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        set<string> ans = ob.allPossibleSubsequences(S);
        if (ans.size() == 0)
            cout << -1 << endl;
        else {
            for (auto i : ans) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends