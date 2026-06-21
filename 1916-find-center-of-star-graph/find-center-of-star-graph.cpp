class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int x1=edges[0][0],y1=edges[0][1];
        int x2=edges[1][0],y2=edges[1][1];
        if(x1==x2) return x1;
        else if(x1==y2) return x1;
        else return y1;
    }
};