//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int k=0,a=0,b=0;
        vector <int> v(arr.size(),0);
        for(int i=0;i<arr.size();i++)
        {
            v[arr[i]-1]++;
            if(v[arr[i]-1]==2) k=arr[i];
            a^=i+1;
            b^=arr[i];
        }
        int j=a^b^k;
        return {k,j};
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;
        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        auto ans = ob.findTwoElement(arr);
        cout << ans[0] << " " << ans[1] << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends