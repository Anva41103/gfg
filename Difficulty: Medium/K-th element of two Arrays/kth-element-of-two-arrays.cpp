//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(int k, vector<int>& a, vector<int>& b) {
        // code here
        int n1=a.size();
        int n2=b.size();
        if(n1>n2) return kthElement(k,b,a);
        int l=max(k-n2,0),h=min(k,n1);
        int left=k;
        int n=n1+n2;
        while(l<=h)
        {
            int m1=(l+h)>>1;
            int m2=left-m1;
            int l1=INT_MIN,l2=INT_MIN;
            int r1=INT_MAX, r2= INT_MAX;
            if(m1<n1) r1=a[m1];
            if(m2<n2) r2=b[m2];
            if(m1-1>=0)l1=a[m1-1];
            if(m2-1>=0) l2=b[m2-1];
            if(l1<=r2&&l2<=r1)
            {
                 return max(l1,l2);

            }
            else if(l1>r2) h=m1-1;
            else l=m1+1;
        }
        return 0;
 
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> arr1, arr2;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr1.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            arr2.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(k, arr1, arr2) << endl;
    }
    return 0;
}
// } Driver Code Ends