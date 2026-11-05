class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans = 0;
        for(auto i : arr1){
            bool check = true;
            for(auto j : arr2){
                if(abs(i-j) <= d){
                    check = false;
                    break;
                }
            }
            if(check) ans++;
        }
        return ans;
    }
};