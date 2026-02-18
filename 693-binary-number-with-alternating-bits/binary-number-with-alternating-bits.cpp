class Solution {
public:
    bool hasAlternatingBits(int n) {
        int bit=n&1;
        n=n>>1;
        while(n!=0){
            int temp=n&1;
            if(bit==1 && temp==1) return false;
            else if(bit==0 && temp==0) return false;
            else bit=temp;
            n=n>>1;  
        }
        return true;
    }
};