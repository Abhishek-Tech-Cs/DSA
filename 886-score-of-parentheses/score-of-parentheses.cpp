class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans = 0;
        stack<int>st;
        stack<int>store;
        int score = 0;
        store.push(0);
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                st.push(i);
                store.push(score);
                score = 0;
            }else {
                int pre = st.top();
                if(i - pre > 1){
                   score = store.top() + 2*score;
                }else{
                    score = store.top() + 1;
                }
                st.pop();
                store.pop();
            }
        }
        return score;
    }
};