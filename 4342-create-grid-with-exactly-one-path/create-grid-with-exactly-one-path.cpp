class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>ans;
        for(int row=0;row<m;row++){
            string temp="";
            for(int col=0;col<n;col++){
                if(row==0 || col==n-1) temp.push_back('.');
                else temp.push_back('#');
            }
            ans.push_back(temp);
        }
        return ans;
    }
};