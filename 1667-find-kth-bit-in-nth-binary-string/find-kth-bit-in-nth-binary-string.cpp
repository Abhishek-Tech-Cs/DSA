class Solution {
public:
    char findKthBit(int n, int k) {
        string str="0";
        for(int i=1;i<n;i++){
            string temp=str;
            for(int i=0;i<temp.size();i++){
                if(temp[i]=='1') temp[i]='0';
                else temp[i]='1';
            }
            reverse(temp.begin(),temp.end());
            str=str+"1"+temp;
        }
        return str[k-1];
    }
};