class Solution {
public:
    bool palindrome(string s)
    {
        int i=0,j=s.length()-1;
        while(i<=j)
        {
            if(s[i]!=s[j])
                return false;
            i++;j--;
        }
        return true;
    }
    int removePalindromeSub(string s) {
        if(s.length()==0)
            return 0;
        else if(palindrome(s))
            return 1;
        else 
            return 2;
    }
};