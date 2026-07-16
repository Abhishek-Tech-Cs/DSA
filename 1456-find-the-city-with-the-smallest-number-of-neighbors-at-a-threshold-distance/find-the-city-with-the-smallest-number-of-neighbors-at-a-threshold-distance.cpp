using pii=pair<int,int>;
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int,list<pii>>adj;
        for(auto i:edges){
            adj[i[0]].push_back({i[1],i[2]});     //node cost
            adj[i[1]].push_back({i[0],i[2]});
        }
        int ans;
        int numberOfNode=INT_MAX; 
        for(int i=0;i<n;i++){
            vector<int>minW(n,INT_MAX);
            minW[i]=0;
            priority_queue<pii,vector<pii>,greater<pii>>q;
            q.push({0,i}); //cost node
            while(!q.empty()){
                int cost=q.top().first;
                int node=q.top().second;
                q.pop();
                for(auto ngbr:adj[node]){
                    int totalCost=ngbr.second+cost;
                    if(totalCost<minW[ngbr.first]){
                        minW[ngbr.first]=totalCost;
                        q.push({totalCost,ngbr.first});
                    }
                }
            }
            int totalNgbr=0;
            for(int i=0;i<n;i++){
                if(minW[i]<=distanceThreshold)
                    totalNgbr++;
            }
            if(numberOfNode>=totalNgbr){
                numberOfNode=totalNgbr;
                ans=i;
            } 
        }
        return ans;
    }
};