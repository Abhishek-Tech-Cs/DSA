class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        sort(words.begin(), words.end());
        int ans = 0;
        int i = 1, st = 0;
        for (; i < words.size(); i++) {
            if (words[i].size() >= k && words[i-1].size()>=k) {
                for (int j = 0; j < k; j++) {
                    if (j<words[i].size() && j<words[i-1].size() && words[i - 1][j] != words[i][j]) {
                        if(i-st-1>=1){
                            ans++;
                            st=i;
                        }else st=i;
                    }
                }
            } else{
                if(i-st-1>=1) ans++;
                st=i;
            }
        }
        if (i - st - 1 >= 1 ) {
            ans++;
        }
        return ans;
    }
};