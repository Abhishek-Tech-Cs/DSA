class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int>p(1001,0);
        for(int i=0;i<trips.size();i++){
            int passengers=trips[i][0];
            int from=trips[i][1];
            int to=trips[i][2];
            p[from]+=passengers;
            p[to]-=passengers;
        }
        int cc=0;
        for(int i=0;i<1001;i++){
            cc+=p[i];
            if(cc>capacity) return false;
        }
        return true;
    }
};