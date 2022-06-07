class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0,j=0;
        vector<int>ans;
        while(i<m && j<n)
        {
            if(nums1[i]<nums2[j])
            {
                ans.push_back(nums1[i]);
                i++;
            }
            else
            {
                ans.push_back(nums2[j]);
                j++;
            }
        }
        // cout<<i<<" "<<j<<" ";
        // for(int k=0;k<ans.size();k++)
        //     cout<<ans[k]<<" ";
        
        while(i<m)
        {
            ans.push_back(nums1[i]);
            i++;
        }
        while(j<n)
        {
            // cout<<j<<" ";
            ans.push_back(nums2[j]);
            j++;
        }
        
        nums1=ans;
    }
};