class Solution {
public:
//     int c=0;
//     void backtrack(int i,int j,int m,int n)
//     {
//         if(i>=m || j>=n)
//             return;
//         if(i==m-1 && j==n-1)
//         {
//             c++;return;
//         }
//         backtrack(i+1,j,m,n);
//         backtrack(i,j+1,m,n);
        
//     }
    int uniquePaths(int m,int n) {
        // backtrack(0,0,m,n);
        // return c;
        
//         double res=1;
//         int N=m+n-2;
//         int R=m-1;
        
//         for(int i=1;i<=R;i++)
//         {
//             res=res*(N-R+i)/i;
//         }
//         return (int)res;
        
  int N = m+n-2;
        int r = m-1;
        double res = 1;
        for(int i=1;i<=r;i++)
            res=res*(N-r+i)/i;
        return(int)res;
       
    }
};