class Solution {
public:
    int binaryGap(int n) {
        int index=-1,ans=0;
        int i=0;
        while(n!=0){
            if((n&1)==1 && index==-1) index=i;
            else if((n&1)==1){
                ans=max(ans,i-index);
                index=i;
            }
            i++;
            n=n>>1;
        }
        return ans;
    }
};