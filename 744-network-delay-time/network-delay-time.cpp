using pii=pair<int,int>;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>minTime(n+1,INT_MAX);
        unordered_map<int,list<pii>>adj;
        for(auto &i:times){
            adj[i[0]].push_back({i[1],i[2]});        // node cost
        }
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        pq.push({0,k});                              //  time node
        minTime[k]=0;
        while(!pq.empty()){
            int time=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto &ngbr:adj[node]){
                int next=ngbr.first;
                int toNxtTime=ngbr.second;
                int totalTime=time+toNxtTime;
                if(totalTime<minTime[next]){
                    minTime[next]=totalTime;
                    pq.push({totalTime,next});
                }
            }
        }
        int ans=INT_MIN;
        for(int i=1;i<=n;i++){
            if(i==k) continue;
            if(minTime[i]==INT_MAX) return -1;
            ans=max(ans,minTime[i]);
        }
        return ans;
    }
};