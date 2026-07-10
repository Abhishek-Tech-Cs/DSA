class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=INT_MAX;
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),-1));
        queue<tuple<int, int, int, int>>q;
        q.push({0,0,0,k});             // row col pathLength obstacleCount
        while(!q.empty()){
            auto [row,col,pathLen,obsCnt]=q.front();
            q.pop();
            if(row==n-1 && col==m-1){
                return pathLen;
            }
            if(grid[row][col]) obsCnt--;
            if(obsCnt<0) continue; 

            if(vis[row][col]!=-1 && vis[row][col]>=obsCnt) continue;
            else vis[row][col]=obsCnt;
            //up
            if(row>0){
                q.push({row-1,col,pathLen+1,obsCnt});
            }
            //down
            if(row<n-1){
                q.push({row+1,col,pathLen+1,obsCnt});
            }
            //left
            if(col>0){
                q.push({row,col-1,pathLen+1,obsCnt});
            }
            //right
            if(col<m-1){
                q.push({row,col+1,pathLen+1,obsCnt});
            }
        }
        return -1;
    }
};