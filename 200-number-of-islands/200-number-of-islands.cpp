class Solution {
public:
    void helper(int i,int j,int m,int n,vector<vector<char>>& grid)
    {
        grid[i][j]='0';
        
        if(i-1>=0 && grid[i-1][j]=='1')
            helper(i-1,j,m,n,grid);
        
        if(i+1<m && grid[i+1][j]=='1')
            helper(i+1,j,m,n,grid);
        
        if(j-1>=0 && grid[i][j-1]=='1')
            helper(i,j-1,m,n,grid);
        
        if(j+1<n && grid[i][j+1]=='1')
            helper(i,j+1,m,n,grid);    
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    helper(i,j,grid.size(),grid[0].size(),grid);
                    ans++;
                }
            }
        }
        
        return ans;
    }
    
};