class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {

        unordered_map<int,list<pair<int,double>>>adj;
        int ptr=0;
        for(auto i:edges){
            int u=i[0];
            int v=i[1];
            double cost=succProb[ptr];
            adj[u].push_back({v,cost});
            adj[v].push_back({u,cost});
            ptr++;
        }

        priority_queue<pair<double,int>>q;
        q.push({1,start_node});            //cost node
        vector<double>maxProb(n,0);
        while(!q.empty()){
            double cost=q.top().first;
            int node=q.top().second;
            q.pop();
            for(auto i:adj[node]){
                int ngbr=i.first;
                double toNgbrCost=i.second;
                double totalCost=toNgbrCost*cost;
                if(totalCost>maxProb[ngbr]){
                    maxProb[ngbr]=totalCost;
                    q.push({totalCost,ngbr});
                }
            }
        }
        return maxProb[end_node];
    }
};