class Solution {
public:
    int concatenatedBinary(int n) {
        long ans=0;
        int m=1e9+7,digit=0;
        for(int i=1;i<=n;i++){
            if((i&i-1)==0) digit++;

            ans=((ans<<digit)%m+i)%m;
        }
        return ans;
    }
};