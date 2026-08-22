class Solution {
public:
    bool checkDivisibility(int n) {
        int add=0;
        int mul=1;
        int temp=n;
        while(temp!=0){
            int digit=temp%10;
            add+=digit;
            mul*=digit;
            temp=temp/10;
        }
        return n%(add+mul)==0;
    }
};