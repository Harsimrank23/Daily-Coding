class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        string current="";
        vector<string>temp;
        vector<vector<string>>ans;
        sort(products.begin(),products.end());
        
        for(auto c:searchWord)
        {
            current+=c;
            temp.clear();
            auto itr=lower_bound(products.begin(),products.end(),current);
            
            for(int i=0;i<3 && itr+i!=products.end();i++)
            {
                string now=*(itr+i);
                // cout<<now<<" "<<"h";
                if(now.find(current))
                    break;
                temp.push_back(now);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};