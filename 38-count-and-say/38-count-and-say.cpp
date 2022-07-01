class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
            return "1";
        
        // recursion:
        string s=countAndSay(n-1);
        
        string res=""; 
        
        // find frequency:
        int counter=0;
        
        for(int i=0;i<s.length();i++)
        {
            counter++;
            if(i==s.length()-1 || s[i]!=s[i+1])
            {
                res+=to_string(counter)+s[i];
                counter=0;
            }
        }
        return res;
    }
};