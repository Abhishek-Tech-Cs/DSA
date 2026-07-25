class Solution {
public:
    int myAtoi(string s) {
        int num=0;
        char sign = '+';
        int i = 0;
        while (i < s.size() && s[i] == ' ') i++;
        if (s[i] == '-' || s[i] == '+') {
            sign = s[i];
            i++;
        }
        while (i < s.size() && s[i] == '0') i++;
        while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
            if(num>((INT_MAX-(s[i]-'0'))/10)){
                num=INT_MAX;
                break;
            }else if(num<0 && abs(num)>(abs(INT_MIN+1)-(s[i]-'0'))/10){
                num=INT_MIN;
                break;
            }
            num=abs(num*10)+(s[i]-'0');
            if(sign=='-') num=-num;
            i++;
        }

        return num;
    }
};