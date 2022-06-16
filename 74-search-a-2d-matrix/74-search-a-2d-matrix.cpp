class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int i=0;
//         while(i<matrix.size() && matrix[i][0]<=target)
//             i++;
//         if(i>0)
//             i--;
        
        
//         for(int j=0;j<matrix[0].size();j++)
//         {
//             if(matrix[i][j]==target)
//                 return true;
//         }
//         return false;
        
        if(matrix.size()==0)
            return false;
        int n=matrix.size();
        int m=matrix[0].size();
        
        int low=0;
        int high=m*n-1;
        
        while(low<=high)
        {
            int mid=(low+high)/2;
            
            if(matrix[mid/m][mid%m]==target)
                return true;
            
            else if(matrix[mid/m][mid%m]<target)
                low=mid+1;
            
            else 
                high=mid-1;
            
        }
        return false;
    }
};