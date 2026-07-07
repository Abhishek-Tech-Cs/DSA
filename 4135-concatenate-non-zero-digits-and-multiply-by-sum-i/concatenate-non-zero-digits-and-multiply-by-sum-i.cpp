class Solution {
public:
    long long sumAndMultiply(int n) {
        string x;
        int sum=0;
        while(n!=0){
            int digit=n%10;
            if(digit!=0) x.push_back(digit+'0');
            sum+=digit;
            n/=10;
        }
        int num=0;
        cout<<x;
        for(int i=x.size()-1;i>=0;i--){
            num=num*10+(x[i]-'0');
        }
        return num*long(sum);
    }
};