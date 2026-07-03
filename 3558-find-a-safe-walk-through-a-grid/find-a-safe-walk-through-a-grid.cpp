class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,true));
        vector<vector<int>>store(m,vector<int>(n,INT_MAX));
        store[0][0]=grid[0][0];
        deque<pair<int,int>>dq;
        dq.push_front({0,0});
        while(!dq.empty()){
            int x=dq.front().first;
            int y=dq.front().second;
            dq.pop_front();
            if(x>0 && store[x-1][y]>(store[x][y]+grid[x-1][y])){
                store[x-1][y]=store[x][y]+grid[x-1][y];
                if(grid[x-1][y]==1) dq.push_back({x-1,y});
                else dq.push_front({x-1,y});
            }
            if(y>0 && store[x][y-1]>(store[x][y]+grid[x][y-1])){
                store[x][y-1]=store[x][y]+grid[x][y-1];
                if(grid[x][y-1]==1) dq.push_back({x,y-1});
                else dq.push_front({x,y-1});
            }
            if(x<m-1 && store[x+1][y]>(store[x][y]+grid[x+1][y])){
                store[x+1][y]=store[x][y]+grid[x+1][y];
                if(grid[x+1][y]==1) dq.push_back({x+1,y});
                else dq.push_front({x+1,y});
            }
            if(y<n-1 && store[x][y+1]>(store[x][y]+grid[x][y+1])){
                store[x][y+1]=store[x][y]+grid[x][y+1];
                if(grid[x][y+1]==1) dq.push_back({x,y+1});
                else dq.push_front({x,y+1});
            }
        }
        int finalVal=store[m-1][n-1];
        if(health-finalVal>=1) return true;
        return false;
    }
};