class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        int ans=INT_MAX;
        vector<bool>vis(n,false);
        unordered_map<int,list<pair<int,int>>>adj;
        for(auto &i:roads){
            int u=i[0];
            int v=i[1];
            int dis=i[2];
            adj[u].push_back({v,dis});
            adj[v].push_back({u,dis});
        }
        vector<bool>inQueue(n,false);
        queue<int>q;
        q.push(n);
        while(!q.empty()){
            int node=q.front();
            vis[node]=true;
            q.pop();
            for(auto i:adj[node]){
                int ngbr=i.first;
                int cost=i.second;
                if(!vis[ngbr]){
                    ans=min(ans,cost);
                    if(!inQueue[ngbr]) q.push(ngbr);
                    inQueue[ngbr]=true;
                }
            }
        }
        return ans;
    }
};