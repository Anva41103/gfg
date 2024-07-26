//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int helpaterp(vector<vector<int>> h)
    {
        //code here
        int n= h.size();
        int m= h[0].size();
        queue <pair <int,int>> q;
        int R[]={-1,1,0,0};
        int C[]={0,0,-1,1};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(h[i][j]==2)
                {
                    q.push({i,j});
                }
            }
        }
        int t=0;
        while(!q.empty())
        {
            int s= q.size();
            t+=1;
            for(int i=0;i<s;i++)
            {
                auto it=q.front();
                q.pop();
                int x=it.first;
                int y=it.second;
                for(int j=0;j<4;j++)
                {
                    int nr=x+R[j];
                    int nc=y+C[j];
                    if(nr>=0&&nr<n&&nc>=0&&nc<m&&h[nr][nc]==1)
                    {
                        h[nr][nc]=2;
                        q.push({nr,nc});
                    }
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(h[i][j]==1) return -1;
            }
        }
        return t-1;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R;int C;
        
        cin>>R>>C;
        vector<vector<int>> hospital;
        int i,j;
        for(i=0;i<R;i++)
         {   vector<int> temp;
             for(j=0;j<C;j++)
            {
                int k;
                cin>>k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
         }
        
        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends