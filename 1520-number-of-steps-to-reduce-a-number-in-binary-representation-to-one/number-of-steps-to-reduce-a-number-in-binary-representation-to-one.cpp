class Solution {
public:
    int numSteps(string s) {
        int step=0;
        while(s!="1"){
            int size=s.size()-1;
            if(s[size]=='1'){
                int carry=1;
                s[size]='0';
                for(int i=size-1;i>=0;i--){
                    if(carry==0) break;
                    else{
                        if(s[i]=='1'){
                            s[i]='0';
                            carry=1;
                        }else{
                            s[i]=carry+'0';
                            carry=0;
                        }
                    }
                }
                if(carry==1) s="1"+s;
            }else{
                for(int i=size;i>0;i--){
                    s[i]=s[i-1];
                }
                if (!s.empty()) {
                    s.erase(0, 1);
                }
            }
            step++;
        }
        return step;
    }
};