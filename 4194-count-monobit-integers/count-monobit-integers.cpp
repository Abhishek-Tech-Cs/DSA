class Solution {
public:
    int countMonobit(int n) {
        int ans=1;
        for(int i=1;i<=n;i++){
            int num=i;
            int first=num&1;
            num=num>>1;
            bool check=true;
            while(num!=0){
                int temp=num&1;
                if(temp!=first) check=false;
                num=num>>1;
            }
            if(check) ans++;
        }
        return ans;
    }
};