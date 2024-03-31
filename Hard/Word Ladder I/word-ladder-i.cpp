//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Code here
        queue <pair<string, int> > q;
        unordered_set <string> s(wordList.begin(),wordList.end());
        q.push({beginWord,1});
        s.erase(beginWord);
        while(!q.empty())
        {
            string w= q.front().first;
            int st=q.front().second;
            if(w==endWord) return st;
            q.pop();
            for(int i=0;i<w.size();i++)
            {
                string o=w;
                for(char j='a';j<='z';j++)
                {
                    w[i]=j;
                    if(s.find(w)!=s.end())
                    {
                        s.erase(w);
                        q.push({w,st+1});
                    }
                }
                w=o;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends