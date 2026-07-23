class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        solve(s,ans,temp);
        return ans;
    }
    void solve(string s,vector<vector<string>> &ans,vector<string>store){
        if(s.empty()){
            ans.push_back(store);
            return;
        }

        string temp;
        for(int i=0;i<s.size();i++){
            temp.push_back(s[i]);
            if(isPalindrome(temp)){
                store.push_back(temp);
                solve(s.substr(i+1),ans,store);
                store.pop_back();
            }
        }
    }
    bool isPalindrome(string s){
        int st=0,end=s.size()-1;
        while(st<end){
            if(s[st]!=s[end]) return false;
            st++,end--;
        }
        return true;
    }
};