class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
//         int sum=0;
//         for(auto x:cardPoints)
//             sum+=x;
        
//         int ans=0,window=0;
//         int n=cardPoints.size();
//         if(n==k)
//             return sum;
//         for(int i=0;i<n-k-1;i++)
//             window+=cardPoints[i];
        
//         for(int i=n-k-1;i<n;i++)
//         {
//             window+=cardPoints[i];
//             ans=max(ans,sum-window);
//             window-=cardPoints[i-(n-k-1)];
//         }
        
//         return sum;
        int n = cardPoints.size();
        int windowSum = 0,totalSum=0,end=n-k;
        for(int i=0; i<n; i++){
            totalSum += cardPoints[i];
            if(i==end-1)
                windowSum = totalSum;
        }
        if(n==k)
            return totalSum;
        int start=0, ans=totalSum-windowSum;
        while(end<n){
           windowSum -= cardPoints[start++];
           windowSum += cardPoints[end++];
          ans = max(ans, totalSum-windowSum);
        }
        return ans;
    
    }
    
};