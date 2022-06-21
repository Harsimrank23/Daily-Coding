class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int cnt=0;
        priority_queue<int>q;
        for(cnt=0;cnt<heights.size()-1;cnt++)
        {
            if(heights[cnt]>=heights[cnt+1])
                continue;
            int d=heights[cnt+1]-heights[cnt];
            if(bricks>=d)
            {
                bricks-=d;
                q.push(d);
            }       
            else if(ladders>0)
            {
                if(q.size()>0)
                {
                    int x=q.top();
                    if(x>d)
                    {
                        bricks+=x;
                        q.pop();
                        bricks-=d;
                        q.push(d);
                    }
                }
                ladders--;
            }
            else break;
        }
        
        return cnt;
    }
};