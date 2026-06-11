class Solution {
public:
    bool consecutiveSetBits(int n) {
        bool check=false;
        int pre=-1;
        bool mid=true;
        while(n!=0){
            int bit=n&1;
            if(pre==1 && bit==1 && !check) check=true;
            else if(mid) mid=false;
            else if(!mid && pre==1 && bit==1) return false;
            pre=bit;
            n=n>>1;
        }
        return check;
    }
};