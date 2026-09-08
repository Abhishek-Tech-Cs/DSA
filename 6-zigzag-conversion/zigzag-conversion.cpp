class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        int n = s.size();
        vector<vector<char>>pt(numRows,vector<char>(n, '-'));

        int row = 0, col = 0;
        bool parity = true;
        for(int i=0; i < n; i++){
            if(row == numRows - 1){
                pt[row][col] = s[i];
                parity = false;
                row--;
                col++;
            }else if(row == 0){
                pt[row][col] = s[i];
                row++;
                parity = true;
            }else if(parity){
                pt[row][col] = s[i];
                row++;
            }else{
                pt[row][col] = s[i];
                row--;
                col++;
            }
        }

        string ans;
        for(int i = 0; i < numRows; i++){
            for(int j = 0; j < n; j++){
                if(pt[i][j] != '-') ans.push_back(pt[i][j]);
            }
        }
        return ans;
    }
};