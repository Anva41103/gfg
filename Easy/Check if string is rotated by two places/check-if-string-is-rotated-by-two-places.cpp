//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        // Your code here
         if (str1.length() != str2.length()) {
        return false;
    }

    int len = str1.length();
    if (len < 2) {
        // If the string length is less than 2, rotation by 2 places doesn't make sense
        return str1 == str2;
    }

    // Rotate left by 2 places
    string leftRot = str1.substr(2) + str1.substr(0, 2);

    // Rotate right by 2 places
    string rightRot = str1.substr(len - 2) + str1.substr(0, len - 2);

    // Check if str2 matches either of the rotations
    return (str2 == leftRot || str2 == rightRot);
    }

};


//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}

// } Driver Code Ends