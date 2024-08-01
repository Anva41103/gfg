//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int shortestDistance(vector<string> &s, string word1, string word2)
	{
		// Your code goes here
		int f=0, k=-1;
		vector <int> a, b;
		for(int i=0;i<s.size();i++)
		{
		    string it=s[i];
		    if(it==word1)
		    {
		        a.push_back(i);
		        
		    }
		    if(it==word2)
		    {
		        b.push_back(i);
		        
		    }
		}
		k= s.size();
		for(int i=0;i<a.size();i++)
		{
		    for(int j=0;j<b.size();j++)
		    {
		        k= min(k, abs(a[i]-b[j]));
		    }
		}
		return k;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;

   		vector<string> s(n);
   		for(int i = 0; i < n; i++)
   			cin >> s[i];

   		string word1, word2;

   		cin >> word1 >> word2;
   		
   		Solution ob;

   		cout << ob.shortestDistance(s, word1, word2) << "\n";
   	}

    return 0;
}
// } Driver Code Ends