class Solution {
public:
    typedef long long ll;
    typedef pair<long,int>P;
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n=online.size();
        int st=INT_MAX,end=INT_MIN;
        unordered_map<int,list<pair<int,int>>>adj;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int cost=edges[i][2];
            if(!online[u] || !online[v]) continue;
            adj[u].push_back({v,cost});
            st=min(st,cost);
            end=max(end,cost);
        }

        int ans=-1;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(checkPath(adj,mid,k,n)){
                ans=mid;
                st=mid+1;
            }else end=mid-1;
        }
        return ans;
    }
    bool checkPath(unordered_map<int,list<pair<int,int>>>&adj,int mid,long long k,int n){
        vector<ll>store(n,LLONG_MAX);
        priority_queue<P,vector<P>,greater<P>>pq;
        pq.push({0,0});
        while(!pq.empty()){
            ll d=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            if(d>k) return false;

            if(d>store[node]) continue;

            if(node==n-1) return true;

            for(auto i:adj[node]){
                int ngbr=i.first;
                int cost=i.second;
                 
                if(cost<mid) continue;

                if(d+cost<store[ngbr]){
                    store[ngbr]=d+cost;
                    pq.push({d+cost,ngbr});
                }
            }
        }
        return false;
    }
};