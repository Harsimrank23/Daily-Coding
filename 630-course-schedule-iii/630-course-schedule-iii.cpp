class Solution {
public:
    bool static comparator(vector<int>& a,vector<int>& b){
        if(a[1]<b[1])
            return true;
        
        return false;
    }
    
    int scheduleCourse(vector<vector<int>>& courses) {
        
        sort(courses.begin(),courses.end(),comparator);
        priority_queue<int> pq;
        int time=0;
        
        for(int i=0;i<courses.size();i++)
        {
            // check if we can consider course:
            if(courses[i][0]<=courses[i][1])
            {
                // current course can be completed within duration?
                if(courses[i][0]+time<=courses[i][1])
                {
                    pq.push(courses[i][0]);
                    time+=courses[i][0];
                }
                // else swap
                else
                {
                    if(pq.top()>courses[i][0])
                    {
                        time-=pq.top();
                        pq.pop();
                        time+=courses[i][0];
                        pq.push(courses[i][0]);
                    }
                }
            }
        }
        return pq.size();
    }
};