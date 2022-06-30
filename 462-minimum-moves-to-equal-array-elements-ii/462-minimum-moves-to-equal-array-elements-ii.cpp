class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int median=0;
        int n=nums.size();
        if(n%2==0)
            median=(nums[n/2]+nums[(n/2)-1])/2;
        else
            median=nums[n/2];
        
        int ans=0;
        
        for(auto x:nums)
        {
            ans+=abs(x-median);
        }
            return ans;
    }
};