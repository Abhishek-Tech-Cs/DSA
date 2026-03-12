class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        pair<int,int>p=make_pair(INT_MAX,INT_MAX);                         //value, index
        for(int i=0;i<capacity.size();i++){
            if(p.first>capacity[i] && capacity[i]>=itemSize) p=make_pair(capacity[i],i);
        }
        if(p.second==INT_MAX) return -1;
        return p.second;
    }
};