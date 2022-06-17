class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
       
//         vector<vector<int>>ans;
//         if(nums.size()<4)
//              return ans;
            
//         sort(nums.begin(),nums.end());
//         int n=nums.size();
        
        
//         for(int i=0;i<n-3;i++)
//         {
//             for(int j=i+1;j<n-2;j++)
//             {
//                 long long sum=target-nums[i]-nums[j];
//                 int front=j+1;
//                 int back=n-1;
                
//                 while(front<back)
//                 {
//                     long long sum2=nums[front]+nums[back];
//                     if(sum2<sum)
//                         front++;
//                     else if(sum2>sum)
//                         back--;
//                     else
//                     {
//                         vector<int>v(4,0);
//                         v[0]=nums[i];
//                         v[1]=nums[j];
//                         v[2]=nums[front];
//                         v[3]=nums[back];
//                         ans.push_back(v);
                        
//                         while(front<back && nums[front]==v[2])
//                             front++;
                    
//                         while(front<back && nums[back]==v[3])
//                             back--;
//                     }
//                 }
                
//                 while(j+1<n-2 && nums[j]==nums[j+1])
//                         j++;
//             }
            
//             while(i+1<n-3 && nums[i+1]==nums[i])
//                         i++;
//         }
//         return ans;
        
        vector<vector<int>> res;
if (nums.size() == 0) return res;
int n = nums.size();

    //sort the array
    sort(nums.begin(), nums.end());
    
    for (int i=0 ; i<n ; i++){
        long target3 = target - nums[i];
        for (int j=i+1 ; j<n ; j++){
            long target2 = target3 - nums[j];
            int left = j+1;
            int right = n-1;
            
            while (left < right) {
                int two_sum = nums[left] + nums[right];
                if (two_sum < target2) left++;
                else if (two_sum > target2) right--;
                else {
                    vector<int> v(4, 0);
                    v[0] = nums[i];
                    v[1] = nums[j];
                    v[2] = nums[left];
                    v[3] = nums[right];
                    res.push_back(v);
                
                    while (left < right and nums[left] == v[2]) ++left;
                 
                    while (left < right and nums[right] == v[3]) --right;
                }
            }
            while (j+1 < n and nums[j+1] == nums[j]) ++j;
        }
        while (i+1 < n and nums[i+1] == nums[i]) ++i;
    }
    return res;
    }
};