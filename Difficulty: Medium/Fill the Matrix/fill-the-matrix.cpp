//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minIteration(int N, int M, int x, int y){    
        // code here
        queue <pair< int,int>> q;
        x--, y--;
        q.push({x,y});
        int r[4]={0,0,-1,1};
        int c[4]={1,-1,0,0};
        vector <vector <int>> mat(N, vector <int>(M,0));
        mat[x][y]=1;
        int ans=0;
        while(!q.empty())
        {
            ans++;
            int s= q.size();
            for(int l=0;l<s;l++)
            {
                int a= q.front().first;
                int b= q.front().second;
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int nx= a+r[i];
                    int ny= b+c[i];
                    if(nx>=0&&nx<N&&ny>=0&&ny<M&&!mat[nx][ny])
                    {
                        mat[nx][ny]=1;
                        q.push({nx,ny});
                    }
                }
                
            }
            
        }
        return ans-1;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends