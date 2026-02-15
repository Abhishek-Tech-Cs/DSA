class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        int p1=a.size()-1,p2=b.size()-1;
        int carry=0;
        while(p1>=0 && p2>=0){
            if(carry==0 && a[p1]=='1' && b[p2]=='1'){
                ans.push_back('0');
                carry=1;
            }else if(carry==0 && ((a[p1]=='1' && b[p2]=='0') || (a[p1]=='0' && b[p2]=='1'))) ans.push_back('1');
            else if(carry==0) ans.push_back('0');
            else if(carry==1 && a[p1]=='1' && b[p2]=='1') ans.push_back('1');
            else if(carry==1 && ((a[p1]=='1' && b[p2]=='0') || (a[p1]=='0' && b[p2]=='1'))){
                ans.push_back('0');
                carry=1;
            }else{
                ans.push_back('1');
                carry=0;
            }
            p1--,p2--;
        }
        while(p1>=0){
            if(carry==1 && a[p1]=='0'){
                ans.push_back('1');
                carry=0;
            }else if(carry==1 && a[p1]=='1') ans.push_back('0');
            else ans.push_back(a[p1]);
            p1--;
        }
        while(p2>=0){
            if(carry==1 && b[p2]=='0'){
                ans.push_back('1');
                carry=0;
            }else if(carry==1 && b[p2]=='1') ans.push_back('0');
            else ans.push_back(b[p2]);
            p2--;
        }
        if(carry==1) ans.push_back('1');
        reverse(ans.begin(),ans.end());
        return ans;
    }
};