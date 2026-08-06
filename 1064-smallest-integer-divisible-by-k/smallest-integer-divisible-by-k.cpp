class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k==1) return 1;
        if(k%2==0 || k%5==0) return -1;

        int div=1;
        int ans=1;
        while(true){
            div=(div*10+1)%k;
            ans++;
            if(div==0) return ans;
        }
        return 1;
    }
};