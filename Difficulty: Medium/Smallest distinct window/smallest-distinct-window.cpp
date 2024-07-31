//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here   
        unordered_set <char> s;
        for(auto it:str)
        {
            s.insert(it);
        }
        int k= s.size();
        int l=0, r=0, le=str.length();
        unordered_map <char, int> mp;
        while(r<str.size())
        {
            mp[str[r]]++;
            while(mp.size()==k)
            {
                le= min(le,r-l+1);
                mp[str[l]]--;
                if(mp[str[l]]==0) mp.erase(str[l]);
                l++;
            }
            r++;
        }
        return le;
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends