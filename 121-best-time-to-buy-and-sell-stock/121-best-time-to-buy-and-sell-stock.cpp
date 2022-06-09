class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0,min_price=INT_MAX;
        for(int i=0;i<prices.size();i++)
        {
            min_price=min(min_price,prices[i]);
            ans=max(ans,prices[i]-min_price);
        }
        return ans;
    }
};