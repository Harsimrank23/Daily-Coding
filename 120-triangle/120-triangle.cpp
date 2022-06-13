class Solution {
public:
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int n=triangle.size();
//         vector<int>dp(n,0);
        
//         for(int i=0;i<n;i++)
//         {
//             dp[i]=triangle[n-1][i];
//         }
        
//         for(int i=n-2;i>=0;i--)
//         {
//             for(int j=0;j<triangle[i].size();j++)
//             {
//                 dp[i]=min(dp[j]+triangle[i][j],dp[j+1]+triangle[i][j]);
//             }
//         }
        
//         return dp[0];
//     }
     int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size(); // n is the len of the last row
        
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        // mark the last row
        for(int i=0;i<n;i++)
            dp[n-1][i]=triangle[n-1][i];
        
        // now start from 2nd last row, n-2 marking for dp[i][j] = triangle[i][j]+min(dp[i+1][j],dp[i+1][j+1]
        
        for(int i=n-2;i>=0;i--)
        {
            // for dp[i+1][j+1], max  it can become i+1 but for next row, i+1 would be valid such as when i=n-2. 
            // n-1 is valid for last row
            for(int j=0;j<triangle[i].size();j++)
            {
                int first = triangle[i][j] + dp[i+1][j];
                int second = triangle[i][j] + dp[i+1][j+1];
                dp[i][j]=min(first,second);
            }
        }
        return dp[0][0];
    }
};