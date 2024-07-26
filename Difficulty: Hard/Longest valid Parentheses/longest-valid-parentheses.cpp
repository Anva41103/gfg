//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxLength(string S){
        // code here
        stack <int> s;
        s.push(-1);
        int m=0;
        for(int i=0;i<S.length();i++)
        {
            if(S[i]=='(') s.push(i);
            else
            {
                if(!s.empty())
                {
                    s.pop();
                }
                if(!s.empty())
                {
                    m= max(m, i-s.top());
                }
                else s.push(i);
            }
        }
        return m;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.maxLength(S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends