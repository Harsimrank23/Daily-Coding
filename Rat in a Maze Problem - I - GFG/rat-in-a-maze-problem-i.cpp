// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string>ans;
    int di[4]={1,0,0,-1};
    int dj[4]={0,-1,1,0};
    
    void solve(int i,int j,vector<vector<int>> &m, int n,string s,vector<vector<int>>&vis)
    {
        if(i==n-1 && j==n-1)
        {
            ans.push_back(s);
            return;
        }
        
        string dir="DLRU";
        
        for(int ind=0;ind<4;ind++)
        {
            int nexti=i+di[ind];
            int nextj=j+dj[ind];
            
            if(nexti>=0 && nextj>=0 && nexti<n && nextj<n && !vis[nexti][nextj] && m[nexti][nextj]==1)
            {
                vis[i][j]=1;
                solve(nexti,nextj,m,n,s+dir[ind],vis);
                vis[i][j]=0;
            }
        }
        
        // if(i+1<n && !vis[i+1][j] && m[i+1][j]==1)
        // {
        //     vis[i][j]=1;
        //     solve(i+1,j,m,n,s+'D',vis);
        //     vis[i][j]=0;
        // }
        // if(j-1>=0 && !vis[i][j-1] && m[i][j-1]==1)
        // {
        //     vis[i][j]=1;
        //     solve(i,j-1,m,n,s+'L',vis);
        //     vis[i][j]=0;
        // }
        // if(j+1<n && !vis[i][j+1] && m[i][j+1]==1)
        // {
        //     vis[i][j]=1;
        //     solve(i,j+1,m,n,s+'R',vis);
        //     vis[i][j]=0;
        // }
        // if(i-1>=0 && !vis[i-1][j] && m[i-1][j]==1)
        // {
        //     vis[i][j]=1;
        //     solve(i-1,j,m,n,s+'U',vis);
        //     vis[i][j]=0;
        // }
    }   
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<vector<int>>vis(n,vector<int>(n,0));
        if(m[0][0]==1)
            solve(0,0,m,n,"",vis);
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends