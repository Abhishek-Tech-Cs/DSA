class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        string str;
        while(n!=0){
            int temp=n&1;
            str.push_back(temp+'0');
            n=n>>1;
        }
        reverse(str.begin(),str.end());
        for(int i=0;i<str.size();i++){
            if(str[i]=='1') str[i]='0';
            else str[i]='1';
        }
        cout<<str;
        int num=0;
        for(int i=str.size()-1;i>=0;i--){
            if(str[i]=='1') num=num+pow(2,str.size()-i-1);
        }
        return num;
    }
};