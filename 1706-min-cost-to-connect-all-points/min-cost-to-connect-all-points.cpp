class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<int>key(n,INT_MAX);
        vector<bool>isMST(n,false);
        key[0]=0;
        for(int i=0;i<n;i++){
            int w=INT_MAX;
            int idx;
            for(int j=0;j<n;j++){
                if(!isMST[j] && key[j]<w){
                    w=key[j];
                    idx=j;
                }
            }
            if(w==INT_MAX) break;
            isMST[idx]=true;
            for(int j=0;j<n;j++){
                if(idx==j) continue;
                if(isMST[j]) continue;
                int distance=abs(points[idx][0]-points[j][0])+abs(points[idx][1]-points[j][1]);
                if(key[j]>distance){
                    key[j]=distance;
                }
            }
        }
        int ans=0;
        for(auto i:key) ans+=i;
        return ans;
    }
};