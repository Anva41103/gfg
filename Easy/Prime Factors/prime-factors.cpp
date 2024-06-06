//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
	public:
 void countPrimes(int n,vector <int> &v) {
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
        //for(int i=2;i<v.size();i++) if(v[i]==1) s.push_back(i);
    }
	vector<int>AllPrimeFactors(int n) {
	    // Code here
	    vector <int> v(n+1,1);
	    vector <int> ans;
	    countPrimes(n,v);
	    for(int i=2;i<=n;i++)
	    {
	        if(v[i]==1&&n%i==0) { ans.push_back(i); while(n%i==0) n/=i;}
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int N;
		cin >> N;
		Solution ob;
		vector<int>ans = ob.AllPrimeFactors(N);
		for(auto i: ans)
			cout << i <<" ";
		cout <<"\n";
	}  
	return 0;
}
// } Driver Code Ends