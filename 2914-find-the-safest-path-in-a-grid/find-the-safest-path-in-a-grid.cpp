class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>g(n,vector<int>(n,0));
        queue<pair<int,int>>q;
        vector<vector<bool>>vis(n,vector<bool>(n,true));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    vis[i][j]=false;
                }
            }
        }
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            if(i>0 && vis[i-1][j]){
                q.push({i-1,j});
                g[i-1][j]=g[i][j]+1;
                vis[i-1][j]=false;
            }
            if(j>0 && vis[i][j-1]){
                q.push({i,j-1});
                g[i][j-1]=g[i][j]+1;
                vis[i][j-1]=false;
            }
            if(i<n-1 && vis[i+1][j]){
                q.push({i+1,j});
                g[i+1][j]=g[i][j]+1;
                vis[i+1][j]=false;
            }
            if(j<n-1 && vis[i][j+1]){
                q.push({i,j+1});
                g[i][j+1]=g[i][j]+1;
                vis[i][j+1]=false;
            }
        }
        int ans=0;
        int st=0,end=2*n;
        while(st<=end){
            int mid=st+(end-st)/2;
            vector<vector<bool>>vis(n,vector<bool>(n,false));
            if(checkPath(n,g,vis,mid)){
                ans=max(ans,mid);
                st=mid+1;
            }else end=mid-1;
        }
        return ans;
    }
    bool checkPath(int n,vector<vector<int>>&g,vector<vector<bool>>&vis,int target,int row=0,int col=0){
        if(row<0 || row>=n || col<0 || col>=n || g[row][col]<target || vis[row][col]) return false;
        if(row==n-1 && col==n-1) return true;

        vis[row][col]=true;
        bool up=checkPath(n,g,vis,target,row-1,col);
        bool down=checkPath(n,g,vis,target,row+1,col);
        bool left=checkPath(n,g,vis,target,row,col-1);
        bool right=checkPath(n,g,vis,target,row,col+1);

        return up||down||left||right;
    }
};