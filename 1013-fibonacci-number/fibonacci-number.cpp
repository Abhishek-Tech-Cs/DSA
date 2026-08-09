class Solution {
public:
    int fib(int n) {
        int d1=0,d2=1;
        if(n<=1) return n;
        for(int i=2;i<n;i++){
            int curr=d1+d2;
            d1=d2;
            d2=curr;
        }
        return d1+d2;
    }
};