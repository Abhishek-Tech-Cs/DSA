class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m=boxGrid.size(),n=boxGrid[0].size();
        vector<vector<char>>ans(boxGrid[0].size(),vector<char>(boxGrid.size(),'.'));
        for(int i=0;i<m;i++){
            for(int j=n-1;j>=0;j--){
                if(boxGrid[i][j]=='#'){
                    int temp=j+1;
                    while(temp<n && boxGrid[i][temp]!='#' && boxGrid[i][temp]!='*') temp++;
                    boxGrid[i][j]='.';
                    boxGrid[i][temp-1]='#';
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[j][m-1-i]=boxGrid[i][j];
            }
        }
        return ans;
    }
};