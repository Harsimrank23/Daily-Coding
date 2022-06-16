class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0;
        while(i<matrix.size() && matrix[i][0]<=target)
            i++;
        if(i>0)
            i--;
        
        
        for(int j=0;j<matrix[0].size();j++)
        {
            if(matrix[i][j]==target)
                return true;
        }
        return false;
    }
};