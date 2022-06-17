class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s;
        int ans=0;
        for(int i=0;i<nums.size();i++)
            s.insert(nums[i]);
        
        for(int i=0;i<nums.size();i++)
        {
            if(!s.count(nums[i]-1))
            {
                int cnt=1;
                int cno=nums[i];
                
                while(s.count(cno+1))
                {
                    cnt++;
                    cno++;
                }
                ans=max(ans,cnt);
            }
        }
        return ans;
        
    }
};