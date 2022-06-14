class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                if(i<j)
                {
                    int temp=matrix[i][j];
                    matrix[i][j]=matrix[j][i];
                    matrix[j][i]=temp;
                }
            }
        }
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
        
        for(int i=0;i<matrix.size();i++)
        {
            int j=0;
            while(j<matrix[i].size()/2)
            {
                int temp=matrix[i][j];
                matrix[i][j]=matrix[i][matrix[i].size()-1-j];
                matrix[i][matrix[i].size()-1-j]=temp;
                j++;
            }
        }
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};