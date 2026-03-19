class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int ans=0;
        vector<vector<pair<int,int>>> count(grid.size(),vector<pair<int,int>>(grid[0].size(),make_pair(0,0)));
        for(int i=0;i<grid.size();i++){
            int x=0,y=0;
            for(int j=0;j<grid[0].size();j++){

                //counting of x and y in rows
                if(grid[i][j]=='X') x++;
                else if(grid[i][j]=='Y') y++;

                //storing frequency of x and y
                count[i][j]=make_pair(x,y);

                //adding fre of upper row
                if(i>0) count[i][j]=make_pair(count[i-1][j].first+count[i][j].first,count[i-1][j].second+count[i][j].second);

                if(count[i][j].first>0 && count[i][j].first==count[i][j].second) ans++;
            }
        }
        return ans;
    }
};