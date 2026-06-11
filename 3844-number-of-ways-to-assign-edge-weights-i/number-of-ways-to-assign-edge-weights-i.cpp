class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n=edges.size()+2;
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int maxDepth=solve(adj);
        int ans=1;
        for(int i=1;i<maxDepth;i++) ans=ans*2%1000000007;
        return ans;
    }
    int solve(vector<vector<int>>&adj,int curr=1,int pre=-1){
        if(curr>adj.size() || adj[curr].size()==0) return 0;
        int ans=0;
        for(int i=0;i<adj[curr].size();i++){
            if(pre!=adj[curr][i]) ans=max(ans,1+solve(adj,adj[curr][i],curr));
        }
        return ans;
    }
};