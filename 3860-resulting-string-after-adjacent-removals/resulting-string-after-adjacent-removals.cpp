class Solution {
public:
    string resultingString(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(!st.empty() && ( abs(st.top()-s[i])==1 || (st.top()=='z' && s[i]=='a') || (st.top()=='a' && s[i]=='z') )) st.pop();
            else st.push(s[i]);
        }
        string temp;
        while(!st.empty()){
            temp.push_back(st.top());
            st.pop();
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};