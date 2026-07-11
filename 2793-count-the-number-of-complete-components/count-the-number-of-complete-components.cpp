class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,list<int>>adj;
        for(auto &i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        int ans=0;
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int V=0,E=0;
                queue<int>q;
                q.push(i);
                vis[i]=true;
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    V++;
                    for(auto &ngbr:adj[node]){
                        E++;
                        if(!vis[ngbr]){
                            vis[ngbr]=true;
                            q.push(ngbr);
                        }
                    }
                }
                if(V==1) ans++;
                else if(V*(V-1)==E) ans++;
            }
        }
        return ans;
    }
    // void dfs(int &src,unordered_map<int,list<int>> &adj, vector<bool> &vis, int &V, int &E){
    //     vis[src]=true;
    //     V++;
    //     for(auto &node:adj[src]){
    //         E++;
    //         if(!vis[node]){
    //             vis[node]=true;
    //             dfs(node,adj,vis,V,E);
    //         }
    //     }
    // }  
};