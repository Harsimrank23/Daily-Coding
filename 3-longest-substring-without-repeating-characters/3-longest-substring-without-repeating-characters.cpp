class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int l=0,r=0,ans=0;
        vector<int>m(256,-1);
        while(r<s.length())
        {
            if(m[s[r]]!=-1)
                l=max(l,m[s[r]]+1);
            
            m[s[r]]=r;
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
        
    }
};