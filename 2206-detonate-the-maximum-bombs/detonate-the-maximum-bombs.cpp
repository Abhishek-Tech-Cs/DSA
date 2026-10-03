class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        vector<vector<int>>adj(bombs.size());
        for(int i = 0; i < bombs.size(); i++){
            long long r1 = bombs[i][2];
            int x1 = bombs[i][0], y1 = bombs[i][1];
            for(int j = 0; j < bombs.size(); j++){
                if(i == j) continue;
                
                int x2 = bombs[j][0], y2 = bombs[j][1];
                long long dis = 1LL*abs(x2-x1)*abs(x2-x1) + 1LL*abs(y2-y1)*abs(y2-y1);
                if(r1 * r1 * 1LL >= dis){
                    adj[i].push_back(j);
                }
            }
        }
        for(int i = 0;i<adj.size();i++){
            for(auto j:adj[i]) cout<<i<<":"<<j<<" ";
            cout<<endl;
        }

        int ans = 0;

        for(int i = 0; i < bombs.size(); i++){
            queue<int>q;
            q.push(i);
            vector<bool>vis(bombs.size(), false);
            vis[i] = true;
            int len = 1;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(auto i:adj[node]){
                    if(!vis[i]){
                        vis[i] = true;
                        len++;
                        q.push(i);
                    }
                }
            }
            ans = max(ans, len);
        }
        return ans;
    }
};