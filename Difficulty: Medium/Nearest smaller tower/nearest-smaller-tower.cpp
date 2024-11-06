//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<int> nearestSmallerTower(vector<int> arr)
    {
        // code here
        int n=arr.size();
        stack <int> st1,st2;
        vector <int> res(n,-1);
        for(int i=0;i<n;i++)
        {
            while(!st1.empty()&&arr[st1.top()]>=arr[i]) st1.pop();
            if(!st1.empty()) res[i]=st1.top();
            st1.push(i);
        }
        for(int i=n-1;i>=0;i--)
        {
            while(!st2.empty()&&arr[st2.top()]>=arr[i]) st2.pop();
            if(!st2.empty())
            {
                if(res[i]!=-1)
            {
                if(abs(res[i]-i)==abs(st2.top()-i))
                {
                    if(arr[res[i]]>arr[st2.top()])
                    {
                        res[i]=st2.top();
                    }
                }
                else if(abs(res[i]-i)>abs(st2.top()-i)) res[i]=st2.top();
            }
            else res[i]=st2.top();
            }
            st2.push(i);
        }
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution ob;
        vector<int> ans = ob.nearestSmallerTower(v);
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends