class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for(int i=0;i<4;i++){
            vector<vector<int>>temp(mat.size(),vector<int>(mat[0].size(),0));
            for(int j=0;j<mat.size();j++){
                for(int k=0;k<mat[0].size();k++){
                    temp[k][mat[0].size()-j-1]=mat[j][k];
                }
            }
            mat=temp;
            if(mat==target) return true;
        }
        return false;
    }
};