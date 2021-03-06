class Solution {
public:
    string getPermutation(int n, int k) {
        int fact=1;
        vector<int>numbers;
        
        for(int i=1;i<n;i++)
        {
            fact*=i;
            numbers.push_back(i);
        }
        numbers.push_back(n);
        
        string ans="";
        k--; // as we are using 0 based index;
        
        while(true)
        {
            ans=ans+to_string(numbers[k/fact]);
            numbers.erase(numbers.begin()+(k/fact));
            
            if(numbers.size()==0)
                break;
            
            k=k%fact;
            fact/=numbers.size();
        }
        
        return ans;
    }
};