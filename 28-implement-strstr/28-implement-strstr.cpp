class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length()==0)
            return 0;
        int n=0,ans=-1;
        for(int i=0;i<haystack.length();i++)
        {
            
            if(haystack[i]==needle[n])
            {
                int m=i,j=n;
                while(m<haystack.length() && n<needle.length() && haystack[m]==needle[j])
                {
                    m++;j++;cout<<"hello";
                }
                if(j==needle.length())
                {
                    ans= i;
                    break;
                }
            }
        }
        return ans;
    }
};