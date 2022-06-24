class Solution {
public:
    bool isPossible(vector<int>& target) {
        if(target.size() == 1) return (target[0] == 1); //base condition
        
        long long int sum = 0;
        for(int i: target) sum += i;
        
        priority_queue<int> pq;
        
        for(int i: target) pq.push(i);
        
        while(pq.top() != 1){
            
            long long int tp = pq.top(); pq.pop();  // getting largest element in the array
            
            long long int rsum = sum - tp;  // remaining sum in the array
            
            if(rsum >= tp) return false; // if remaining sum >= largest element than we return false
            
            // we use the mod because say the array is [1, 10000000]
            // we keep subtracting 1 from 10000000 which makes the TLE
            // so, we use mod instead
            sum = tp%rsum + rsum;
            int el = tp%rsum;
            
            if(el == 0 && rsum != 1) return false;  // this is your Home Work why this condition or ask me in the comments
            if(el == 0){ 
                el = 1;
                sum = 1 + rsum;
            }
            
            
            pq.push(el);
            
        }
        
        return true;
    }
};