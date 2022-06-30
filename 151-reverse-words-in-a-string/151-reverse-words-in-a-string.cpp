class Solution {
public:
    string reverseWords(string s) {
        
        string temp="",ans="";
        for(int i=0;i<s.length();i++)
        {
            char ch=s[i];
            if(ch!=' ')
            {
                temp+=ch;
            }
            else if(ch==' ' && temp!=""){
                if(ans!="")
                    ans=temp+" "+ans;
                else
                    ans=temp;
                temp="";
            }
            
        }
        if(temp!="")
        {
            if(ans!="")
                    ans=temp+" "+ans;
            else
                ans=temp;
        }
        return ans;
        
     
    }
};