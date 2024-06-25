//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++
 
/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  int burntime(unordered_map <Node*,Node*> mp, Node* t)
  {
      int k=0;
      unordered_map <Node*, int> vis;
      queue <Node*> q;
      q.push(t);
      vis[t]=1;
      while(!q.empty())
      {
          int s= q.size();
          int f=0;
          for(int i=0;i<s;i++)
          {
               Node* n= q.front();
               q.pop();
               if(n->left&&!vis[n->left])
               {
                   f=1;
                   vis[n->left]=1;
                   q.push(n->left);
               }
               if(n->right&&!vis[n->right])
               {
                   f=1;
                   vis[n->right]=1;
                   q.push(n->right);
               }
               if(mp[n]&&!vis[mp[n]])
               {
                   f=1;
                   vis[mp[n]]=1;
                   q.push(mp[n]);
               }
          }
          if(f) k++;
      }
      return k;
      
  }
  Node* fp(unordered_map <Node*,Node*>& mp, Node* root, int t)
  {
      queue <Node*> q;
      q.push(root);
      Node* tar=NULL;
      while(!q.empty())
      {
          Node* x= q.front();
          q.pop();
          if(x->data==t) tar=x;
          
          if(x->left)
          {
              mp[x->left]=x;
              q.push(x->left);
          }
          if(x->right)
          {
              mp[x->right]=x;
              q.push(x->right);
          }
      
      }
      return tar;
  }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        unordered_map <Node*,Node*> mp;
        Node* t= fp(mp,root, target);
        return burntime(mp,t);
        
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends