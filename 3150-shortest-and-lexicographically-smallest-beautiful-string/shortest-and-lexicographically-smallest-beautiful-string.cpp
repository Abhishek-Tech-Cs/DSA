class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans;
        string temp;
        int left=0;
        int one=0;
        for(int right=0;right<s.size();right++){
            if(s[right]=='1') one++;
            temp.push_back(s[right]);
            if(one<k) continue;
            while(left < right && one > k){
                if(s[left]=='1') one--;
                temp.erase(0,1);
                left++;
            }
            while(!temp.empty() && temp[0]=='0'){
                left++;
                temp.erase(0,1);
            }

            if(ans.empty()) ans=temp;
            else if(ans.size()>temp.size()) ans=temp;
            else if(ans.size()==temp.size() && ans>temp) ans=temp;
        }
        return ans;
    }
};