class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans;
        string temp;
        int left=0;
        int one=0;
        for(int right=0;right<s.size();right++){
            if(s[right]=='1') one++;
            if(one<k) continue;
            
            while(one > k) {
                if(s[left]=='1') one--;
                left++;
            }

            while(left < right && s[left] == '0' ) left++;

            string curr = s.substr(left, right - left + 1);

            if( ans == "" || curr.size() < ans.size() || (curr.size() == ans.size() && curr < ans)) 
                ans = curr;
        }
        return ans;
    }
};