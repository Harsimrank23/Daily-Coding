class Solution {
public:
    string findprefix(string ans,string check)
    {
        if(ans.length()>check.length())
            swap(ans,check);
        
        string pref="";
        for(int i=0;i<ans.length();i++)
        {
            if(ans[i]==check[i])
                pref+=ans[i];
            else
                break;
        }
        return pref;
            
    }
    string longestCommonPrefix(vector<string>& strs) {
        string ans=strs[0];
        for(int i=1;i<strs.size();i++)
        {
            ans=findprefix(ans,strs[i]);
        }
        return ans;
    }
};