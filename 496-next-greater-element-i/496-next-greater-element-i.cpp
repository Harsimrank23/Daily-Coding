class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
       int n1=nums1.size();
       int n2=nums2.size();
        stack<int>s;
        unordered_map<int,int>m;
        for(int i=n2-1;i>=0;i--)
        {
            while(!s.empty() && nums2[i]>=s.top())
                s.pop();
            if(s.empty())
                m[nums2[i]]=-1;
            else
                m[nums2[i]]=s.top();
            s.push(nums2[i]);
        }
        
        vector<int>ans;
        
        for(int i=0;i<n1;i++)
            ans.push_back(m[nums1[i]]);
        return ans;
    }
    
   
    
};