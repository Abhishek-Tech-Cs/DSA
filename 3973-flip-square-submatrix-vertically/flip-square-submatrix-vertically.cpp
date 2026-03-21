class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int ptr1=x,ptr2=x+k-1;
        while(ptr1<ptr2){
            for(int i=y;i<(y+k);i++){
                swap(grid[ptr1][i],grid[ptr2][i]);
            }
            ptr1++,ptr2--;
        }
        return grid;
    }
};