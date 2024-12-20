//{ Driver Code Starts
#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        // Your code here
        // Return the string containing the name and an integer
        // representing the number of votes the winning candidate got
        vector <string> v;
        string k="";
        int m=0;
        map <string, int> mp;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
            if(mp[arr[i]]>m)
            {
                m=mp[arr[i]];
                k=arr[i];
            }
            else if(mp[arr[i]]==m&&arr[i]<k)
            {
                k=arr[i];
            }
        }
        v.push_back(k);
        v.push_back(to_string(m));
        return v;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        
        
        int n;
        cin>>n;
        
        string arr[n];
        
        for (int i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        vector<string> result = obj.winner(arr,n);
        
        cout<<result[0] << " " << result[1] << endl;
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends