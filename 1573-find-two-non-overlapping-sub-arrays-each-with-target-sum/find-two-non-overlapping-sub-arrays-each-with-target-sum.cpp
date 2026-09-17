class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<pair<int,int>>subArr;
        int st = 0, end = 0;
        int sum = 0;
        while(st < n){
            if(end < n && sum < target){
                sum += arr[end];
                end++;
            }else{
                sum -= arr[st];
                st++;
            }

            if(sum == target){
                subArr.push_back({st,end});
            }
        }

        int m = subArr.size();
        vector<int> sufMin(m);
        for (int i = m - 1; i >= 0; i--) {
            int len = subArr[i].second - subArr[i].first;
            if (i == m - 1) sufMin[i] = len;
            else sufMin[i] = min(len, sufMin[i + 1]);
        }

        int ans = INT_MAX;
        for(int i = 0; i< m - 1; i++){
            int target = subArr[i].second - 1;
            int st = i + 1, end = m - 1;
            int idx = -1;
            while(st <= end){
                int mid = st + (end - st)/2;
                if (subArr[mid].first >= subArr[i].second) {
                    idx = mid;
                    end = mid - 1;
                } else {
                    st = mid + 1;
                }
            }
            if(idx != -1){
                int len1 = subArr[i].second - subArr[i].first;
                int len2 = sufMin[idx];
                ans = min(ans, len1 + len2);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};