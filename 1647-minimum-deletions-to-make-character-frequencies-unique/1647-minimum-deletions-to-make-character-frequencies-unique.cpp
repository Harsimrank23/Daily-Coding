class Solution {
public:
    int minDeletions(string s) {
        vector<int>freq(26,0);
        for(char c:s)
            freq[c-'a']++;
        
        int deletecnt=0;
        
        unordered_set<int>seenfreq;
        
        for(int i=0;i<26;i++)
        {
            while(freq[i] && seenfreq.find(freq[i])!=seenfreq.end())
            {
                freq[i]--;
                deletecnt++;
            }
            seenfreq.insert(freq[i]);
        }
        return deletecnt;
    }
};