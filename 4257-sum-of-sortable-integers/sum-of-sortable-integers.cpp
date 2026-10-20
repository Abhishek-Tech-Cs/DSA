class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        vector<int>sorted = nums;
        sort(sorted.begin(), sorted.end());
        int n = nums.size();
        int ans = 0;
        for(int k = 1; k <= n; k++){
            if(n % k != 0) continue;

            bool check = true;
            for(int i = 0; i < n; i += k){
                vector<int>target(begin(nums) + i, begin(nums) + i + k);
                vector<int>subArr(begin(sorted) + i, begin(sorted) + i + k);
                target.insert(target.end(), target.begin(), target.end());

                if(!checkSorting(target, subArr)){
                    check = false;
                    break;
                }
            }
            if(check) ans += k;
        }
        return ans;
    }
    bool checkSorting(vector<int>& target, vector<int>& subArr){
        int ts = target.size();
        int ss = subArr.size();

        vector<int>lps(ss, 0);
        int len = 0;
        for(int i = 1; i < ss;){
            if(subArr[i] == subArr[len]){
                len++;
                lps[i] = len;
                i++;
            }else{
                if(len != 0) len = lps[len - 1];
                else{
                    lps[i] = 0;
                    i++;    
                }
            }
        }

        int j = 0;
        for(int i = 0; i < ts; ){
            if(target[i] == subArr[j]){
                i++,j++;
            }
            
            if(j == ss) return true;
            else if(i < ts && target[i] != subArr[j]){
                if(j != 0) j = lps[j-1];
                else i++;
            }
        }
        return false;
    }
};