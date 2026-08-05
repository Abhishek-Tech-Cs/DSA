class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        unordered_map<int,list<int>>adj;
        for(auto i:invocations){
            adj[i[0]].push_back(i[1]);
        }

        vector<int>sus(n,0);
        vector<int>vis(n,false);
        dfs(adj,vis,sus,k);

        vector<int>ans;
        vector<int>ansVis(n,false);
        bool check=false;
        for(int i=0;i<n;i++){
            if(!ansVis[i] && sus[i]!=-1){
                queue<int>q;
                q.push(i);
                ansVis[i]=true;
                while(!q.empty()){
                    int top=q.front();
                    if(sus[top]!=-1) ans.push_back(top);
                    else check=true;
                    q.pop();
                    for(auto ngbr:adj[top]){
                        if(!ansVis[ngbr]){
                            ansVis[ngbr]=true;
                            q.push(ngbr);
                        }
                    }
                }
            }
        }
        if(check){
            for(int i=0;i<n;i++){
                if(sus[i]==-1) ans.push_back(i);
            }
        }
        return ans;
    }
    void dfs(unordered_map<int,list<int>> &adj, vector<int> &vis, vector<int> &sus,int k){
        vis[k]=true;
        sus[k]=-1;
        for(auto i:adj[k]){
            if(!vis[i]){
                dfs(adj,vis,sus,i);
            }
        }
    }
};