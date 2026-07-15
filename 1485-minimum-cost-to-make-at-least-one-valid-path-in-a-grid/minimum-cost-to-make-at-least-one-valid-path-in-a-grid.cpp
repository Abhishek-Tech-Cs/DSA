using tup=tuple<int,int,int>;
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>cost(m,vector<int>(n,INT_MAX));
        priority_queue<tup,vector<tup>,greater<tup>>pq;
        cost[0][0]=0;
        pq.push({0,0,0});     //cost row col
        while(!pq.empty()){
            auto [blockCost,row,col]=pq.top();
            pq.pop();
            int costDown=blockCost,costUp=blockCost,costLeft=blockCost,costRight=blockCost;
            if(row>0){
                if(grid[row][col]!=4) costUp++;
                if(costUp<cost[row-1][col]){
                    cost[row-1][col]=costUp;
                    pq.push({costUp,row-1,col});
                }
            }
            if(row<m-1){
                if(grid[row][col]!=3) costDown++;
                if(costDown<cost[row+1][col]){
                    cost[row+1][col]=costDown;
                    pq.push({costDown,row+1,col});
                }
            }
            if(col>0){
                if(grid[row][col]!=2) costLeft++;
                if(costLeft<cost[row][col-1]){
                    cost[row][col-1]=costLeft;
                    pq.push({costLeft,row,col-1});
                }
            }
            if(col<n-1){
                if(grid[row][col]!=1) costRight++;
                if(costRight<cost[row][col+1]){
                    cost[row][col+1]=costRight;
                    pq.push({costRight,row,col+1});
                }
            }
        }
        return cost[m-1][n-1];
    }
};