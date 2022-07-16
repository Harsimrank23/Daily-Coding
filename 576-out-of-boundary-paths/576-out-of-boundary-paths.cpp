class Solution {
public:
   
//     int findPaths(int m, int n, int maxMove, int i, int j) {
        
//         if(i<0 || i>=m || j<0 || j>=n)
//             return 1;
    
//         if(maxMove==0)
//             return 0;
//         return findPaths(m,n,maxMove-1,i-1,j)
//             +findPaths(m,n,maxMove-1,i+1,j)
//             +findPaths(m,n,maxMove-1,i,j-1)
//             +findPaths(m,n,maxMove-1,i,j+1);
        
//     }
    
    int solve(int m, int n, int maxMove, int str, int stc, vector<vector<vector<int>>> &arr) {
        if(str>=m || str<0 || stc>=n || stc<0) {
            return 1;
        }
        
        if(maxMove <= 0) {
            return 0;
        }
        
        if(arr[str][stc][maxMove] != -1) {
            return arr[str][stc][maxMove];
        }
        
        long long ans = 0;
        ans += solve(m, n, maxMove-1, str+1, stc, arr);
        ans += solve(m, n, maxMove-1, str, stc-1, arr);
        ans += solve(m, n, maxMove-1, str-1, stc, arr);
        ans += solve(m, n, maxMove-1, str, stc+1, arr);
        return arr[str][stc][maxMove] = ans%1000000007;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) { 
        
        vector<vector<vector<int>>> arr(51, vector<vector<int>> (51, vector<int> (51, -1)));
        return solve(m, n, maxMove, startRow, startColumn, arr);
    }
};