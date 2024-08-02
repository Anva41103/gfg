//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++


class Solution{
    
    public:
    long long ValidPair(int a[], int n) 
    { 
    	// Your code goes here 
    	sort(a,a+n);
    	if(a[n-1]<=0) return 0;
    	int l=0, r= n-1;
    	long long ans=0;
    	 while (l < r) {
        if (a[l] + a[r] > 0) {
            // If a[l] + a[r] is positive, then all pairs (l, r), (l+1, r), ..., (r-1, r) are valid
            ans += (r - l);
            r--; // Move right pointer leftward to check the next pair
        } else {
            l++; // Move left pointer rightward to increase the sum
        }
    }
    
    return ans;
    }   
};

//{ Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int array[n];
		for (int i = 0; i < n; ++i)
			cin>>array[i];
	    Solution obj;
		cout << obj.ValidPair(array, n) <<"\n";
	}
	return 0; 
} 


// } Driver Code Ends