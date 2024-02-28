//{ Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int transform (string A, string B)
    {
        //code here.
        string h=A;
        string g=B;
        sort(h.begin(),h.end());
        sort(g.begin(),g.end());
        if(g!=h) return -1;
        int i=A.length()-1, j=B.length()-1,k=0;
        while(i>=0&&j>=0)
        {
            if(B[j]==A[i]) 
            {
                j--;
                i--;
            }
            else
            {
                while(i>=0&&B[j]!=A[i])
                {
                    i--;
                }
                k=j-i;
            }
        }
        return k;
    }
};


//{ Driver Code Starts.

int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}
// } Driver Code Ends