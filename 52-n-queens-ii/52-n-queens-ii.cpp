class Solution {
public:
    int c=0;
    vector<int>x;
    void nqueen(int k,int n)
    {
        for(int i=1;i<=n;i++)
        {
            if(place(k,i))
            {
                x[k]=i;
                if(k==n)
                    c++;
                else
                    nqueen(k+1,n);
            }
        }
    }
    
    bool place(int k,int i)
    {
        for(int j=1;j<k;j++)
        {
            if(x[j]==i || abs(j-k)==abs(x[j]-i))
                return false;
        }
        return true;
    }
    int totalNQueens(int n) {
        x.resize(n+1,0);
        nqueen(1,n);
        return c;
    }
};