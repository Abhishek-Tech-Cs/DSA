using pii = pair<int,int>;
using piii=pair<int,pair<int,int>>;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>storeMinPrice(n,INT_MAX);
        storeMinPrice[src]=0;
        unordered_map<int,list<pii>>adj;
        for(auto i:flights){
            int u=i[0];
            int v=i[1];
            int price=i[2];
            adj[u].push_back({v,price});
        }
        queue<piii>pq;     //price node k
        pq.push({0,{src,k}});
        while(!pq.empty()){
            int price=pq.front().first;
            int node=pq.front().second.first;
            int currK=pq.front().second.second;
            pq.pop();
            if(currK>=0){
                for(auto i:adj[node]){
                    int ngbr=i.first; 
                    int toNgbrPrice=i.second;
                    int totalPrice=price+toNgbrPrice;
                    if(totalPrice<storeMinPrice[ngbr]){
                        storeMinPrice[ngbr]=totalPrice;
                        pq.push({totalPrice,{ngbr,currK-1}});
                    }
                }
            }
        }
        return (storeMinPrice[dst]==INT_MAX)?-1:storeMinPrice[dst];
    }
};