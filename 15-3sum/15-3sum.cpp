class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        if(nums.size()<3){
            return res;
        }
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size()-2;i++)
        {
            if(i==0 || (i>0 &&nums[i]!=nums[i-1]))
            {
                int low=i+1;
                int high=nums.size()-1;
                // a+b+c=0 -> b+c=-a
                int sum=0-nums[i];
                
                while(low<high)
                {
                    if(nums[low]+nums[high]==sum)
                    {
                        vector<int>v;
                        v.push_back(nums[i]);
                        v.push_back(nums[low]);
                        v.push_back(nums[high]);
                        res.push_back(v);
                    
                        while(low<high && nums[low]==nums[low+1])
                            low++;
                        while(low<high && nums[high]==nums[high-1])
                            high--;

                        low++;high--;
                    }
                    else if(nums[low]+nums[high]<sum)
                        low++;
                    else
                        high--;  
                }
            }
        }
        return res;
    }
};