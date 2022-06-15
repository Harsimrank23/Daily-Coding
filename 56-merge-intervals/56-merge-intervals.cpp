class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        
        sort(intervals.begin(),intervals.end());
        
        vector<int>temp;
        temp.push_back(intervals[0][0]);
        temp.push_back(intervals[0][1]);
        
        for(auto it:intervals)
        {
            if(it[0]<=temp[1])
                temp[1]=max(it[1],temp[1]);
            
            else
            {
                ans.push_back(temp);
                temp=it;
            }
        }
        ans.push_back(temp);
        
        return ans;
    }
};