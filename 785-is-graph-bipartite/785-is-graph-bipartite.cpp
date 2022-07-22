class Solution {
public:
    // Bipartite Check using BFS
    
    bool checkbg(int src,vector<int>adj[],int color[])
    {
        queue<int>q;
        q.push(src);
        color[src]=1;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                if(color[it]==-1)
                {
                    color[it]=1-color[node];
                    q.push(it);
                }
                else if(color[it]==color[node])
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int color[graph.size()];
        memset(color,-1,sizeof color);
        vector<int>adj[graph.size()];
        
        for(int i=0;i<graph.size();i++)
        {
            for(int j=0;j<graph[i].size();j++)
                adj[i].push_back(graph[i][j]);
        }
        for(int i=0;i<graph.size();i++)
        {
            if(color[i]==-1)
                if(!checkbg(i,adj,color))
                    return false;
        }
        return true;
    }
};