using tup=tuple<int,int,int>;
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>cost(m,vector<int>(n,INT_MAX));
        deque<tup>dq;
        cost[0][0]=0;
        dq.push_front({0,0,0});     //cost row col
        while(!dq.empty()){
            auto [blockCost,row,col]=dq.front();
            dq.pop_front();
            int costDown=blockCost,costUp=blockCost,costLeft=blockCost,costRight=blockCost;
            if(row>0){
                if(grid[row][col]!=4) costUp++;
                if(costUp<cost[row-1][col]){
                    cost[row-1][col]=costUp;
                    if(costUp==blockCost) dq.push_front({costUp,row-1,col});
                    else dq.push_back({costUp,row-1,col});
                }
            }
            if(row<m-1){
                if(grid[row][col]!=3) costDown++;
                if(costDown<cost[row+1][col]){
                    cost[row+1][col]=costDown;
                    if(costUp==blockCost) dq.push_front({costDown,row+1,col});
                    else dq.push_back({costDown,row+1,col});
                }
            }
            if(col>0){
                if(grid[row][col]!=2) costLeft++;
                if(costLeft<cost[row][col-1]){
                    cost[row][col-1]=costLeft;
                    if(costUp==blockCost) dq.push_front({costLeft,row,col-1});
                    else dq.push_back({costLeft,row,col-1});
                }
            }
            if(col<n-1){
                if(grid[row][col]!=1) costRight++;
                if(costRight<cost[row][col+1]){
                    cost[row][col+1]=costRight;
                    if(costUp==blockCost) dq.push_front({costRight,row,col+1});
                    else dq.push_back({costRight,row,col+1});
                }
            }
        }
        return cost[m-1][n-1];
    }
};